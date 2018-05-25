
import static java.lang.Math.abs;
import java.util.ArrayList;
import java.util.Collections;

/**
 * William Sanson 4213239
 * Paul Souter 4876118
 * 
 * Works with javac 1.8.0_31
 *
 * BinInt stores arbitrarily large integers and has basic int operations that
 * can be performed on BigInt objects.
 */
public class BigInt {

    private ArrayList<Integer> number;
    private boolean negative = false;
    private boolean operand = true;

    public BigInt() {
    }

    public BigInt(String n) {
        setNumber(n);
    }

    private void setNumber(String n) {
        number = new ArrayList<Integer>();
        boolean zeroPadding = false;

        if (n.length() == 1 && n.charAt(0) == '0') {
            number.add(0);
        } else if (!n.isEmpty() && n.charAt(0) != '-') {
            for (int i = 0; i < n.length(); i++) {
                if (n.charAt(0) == '0') {
                    if (i == 0) {
                        zeroPadding = true;
                    } else if (n.charAt(i) != '0') {
                        zeroPadding = false;
                    }
                }
                if (!zeroPadding) {
                    number.add(n.charAt(i) - '0');
                }
            }
        } else {
            negative = true;
            for (int i = 1; i < n.length(); i++) {
                if (n.charAt(1) == '0') {
                    if (i == 1) {
                        zeroPadding = true;
                    } else if (n.charAt(i) != '0') {
                        zeroPadding = false;
                    }
                }

                if (!zeroPadding) {
                    if (n.charAt(i) != '-') {
                        number.add(n.charAt(i) - '0');
                    }
                }
            }
        }

        if (number.isEmpty()) {
            negative = false;
            number.add(0);
        }
    }

    public BigInt(ArrayList<Integer> number) {
        this.number = new ArrayList<Integer>(number);
    }

    public void negate() {
        this.negative = true;
    }

    public static BigInt subtract(BigInt n1, BigInt n2) {

        ArrayList<Integer> newNumber = new ArrayList<>();
        boolean neg = false;
        ArrayList<Integer> number1 = n1.number;
        ArrayList<Integer> number2 = n2.number;
        int num1Size = number1.size();
        int num2Size = number2.size();
        int remainder = 0;
        int sum = 0;
        int num1 = 0;
        int num2 = 0;

        if (n1.operand) {
            if (!n1.negative && n2.negative) {
                if (num1Size >= num2Size) {
                    n1.operand = false;
                    return add(n1, n2);
                } else {
                    BigInt newNum = new BigInt(n2.number);
                    newNum.operand = false;
                    return add(newNum, n1);
                }
            } else if (n1.negative && !n2.negative) {
                if (num1Size >= num2Size) {
                    n1.operand = false;
                    return add(n1, n2);
                } else {
                    BigInt newNum = new BigInt(n2.number);//here
                    newNum.negate();
                    newNum.operand = false;
                    return add(newNum, n1);
                }
            }
        }

        if (num1Size == num2Size) {

            if (num1Size == 1 && number1.get(0) == 0) {
                return new BigInt("-" + n2.toString());
            } else {
                boolean num1Sign = n1.negative;
                boolean num2Sign = n2.negative;
                n1.negative = false;
                n2.negative = false;
                int compare = compare(n1, n2);

                if (compare == 0) {
                    return new BigInt("0");
                } else if (compare < 0) {
                    newNumber = subtractionHelper(number2, number1, newNumber);
                    if (num2Sign) {
                        neg = true;
                    } else if (num1Sign) {
                        neg = false;
                    }
                } else {
                    newNumber = subtractionHelper(number1, number2, newNumber);
                }
                n1.negative = num1Sign;
                n2.negative = num2Sign;

                Collections.reverse(newNumber);

                StringBuilder s = new StringBuilder();
                if (neg) {
                    s.append("-");
                }
                for (Integer i : newNumber) {
                    s.append(i.toString());
                }
                BigInt c = new BigInt(newNumber);
                c.negative = neg;
                return c;
            }

        } else {

            int index1 = num1Size - 1;
            int index2 = num2Size - 1;

            if (num1Size > num2Size) {
                while (index1 >= 0) {
                    while (index2 >= 0) {
                        num1 = number1.get(index1);
                        num2 = number2.get(index2);
                        sum = (num1 + remainder) - num2;
                        remainder = (sum < 0 ? -1 : 0);
                        if (sum >= 0) {
                            newNumber.add(sum);
                        } else {
                            newNumber.add(10 + sum);
                        }
                        index1--;
                        index2--;
                    }
                    if (remainder == -1) {
                        num1 = number1.get(index1);
                        sum = num1 + remainder;
                        remainder = (sum < 0 ? -1 : 0);
                        if (sum >= 0) {
                            newNumber.add(sum);
                        } else {
                            newNumber.add(10 + sum);
                        }

                    } else {
                        newNumber.add(number1.get(index1));
                    }
                    index1--;
                }
            } else {
                BigInt newNum = new BigInt(n2.number);
                if (!n1.negative && n2.negative) {
                    newNum.negate();
                }
                newNum.negate();
                newNum.operand = false;
                return subtract(newNum, n1);
            }
        }

        Collections.reverse(newNumber);
        StringBuilder s = new StringBuilder();

        if (n1.negative) {
            s.append("-");
        }

        for (Integer i : newNumber) {
            s.append(i.toString());
        }
        return new BigInt(s.toString());
    }

    private static ArrayList<Integer> subtractionHelper(
            ArrayList<Integer> n1,
            ArrayList<Integer> n2,
            ArrayList<Integer> n3) {

        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int sum = 0;
        int remainder = 0;
        int index = n1.size() - 1;

        while (index >= 0) {
            num1 = n1.get(index);
            num2 = n2.get(index);
            sum = (num1 + remainder) - num2;

            remainder = (sum < 0 ? -1 : 0);
            if (sum >= 0) {
                n3.add(sum);
            } else if (sum < 0 && index != 0) {
                n3.add(10 + sum);
            }
            index--;
        }
        if (remainder < 0 && n3.isEmpty()) {
            n3.add(sum);
        }
        return n3;
    }

    public static BigInt add(BigInt n1, BigInt n2) {
        ArrayList<Integer> newNumber = new ArrayList<>();
        ArrayList<Integer> number1 = n1.number;
        ArrayList<Integer> number2 = n2.number;
        int num1Size = number1.size();
        int num2Size = number2.size();
        int remainder = 0;
        int sum = 0;
        int num1 = 0;
        int num2 = 0;

        // if this function was called from etude8 class
        if (n1.operand) {
            if (n1.negative && !n2.negative) {
                if (num1Size >= num2Size) {
                    n2.operand = false;
                    return subtract(n2, n1);
                } else {
                    n2.operand = false;
                    return add(n1, n1);
                }
            } else if (!n1.negative && n2.negative) {
                if (num1Size >= num2Size) {
                    n1.operand = false;
                    return subtract(n1, n2);
                } else {
                    n2.negate();
                    n2.operand = false;
                    return subtract(n2, n1);
                }
            }
        }

        if (num1Size == num2Size) {
            int index = num1Size - 1;
            while (index >= 0) {
                num1 = number1.get(index);
                num2 = number2.get(index);
                sum = num1 + num2 + remainder;
                newNumber.add(sum % 10);
                remainder = (sum >= 10 ? 1 : 0);
                index--;
            }
            if (remainder == 1) {
                newNumber.add(1);
            }
        } else {
            int index1 = num1Size - 1;
            int index2 = num2Size - 1;

            if (num1Size > num2Size) {
                while (index1 >= 0) {
                    while (index2 >= 0) {
                        num1 = number1.get(index1);
                        num2 = number2.get(index2);
                        sum = num1 + num2 + remainder;
                        newNumber.add(sum % 10);
                        remainder = (sum >= 10 ? 1 : 0);
                        index1--;
                        index2--;
                    }
                    if (remainder == 1) {
                        num1 = number1.get(index1);
                        sum = num1 + remainder;
                        newNumber.add(sum % 10);
                        remainder = (sum >= 10 ? 1 : 0);
                    } else {
                        newNumber.add(number1.get(index1));
                    }
                    index1--;
                }
                if (remainder == 1) {
                    newNumber.add(1);
                }
            } else {
                n2.operand = false;
                return add(n2, n1);
            }
        }

        Collections.reverse(newNumber);

        StringBuilder s = new StringBuilder();
        if (n1.negative) {
            s.append("-");
        }

        for (Integer i : newNumber) {
            s.append(i.toString());
        }

        return new BigInt(s.toString());
    }

    public static int compare(BigInt n1, BigInt n2) {
        ArrayList<Integer> number1 = n1.number;
        ArrayList<Integer> number2 = n2.number;
        if (!n1.negative && n2.negative) {
            return 1;
        }
        if (n1.negative && !n2.negative) {
            return -1;
        }

        if (number1.size() > number2.size()) {
            return 1;
        } else if (number1.size() < number2.size()) {
            return -1;
        } else {
            int equal = 0;
            for (int i = 0; i < number1.size() && equal == 0; i++) {
                equal = number1.get(i).compareTo(number2.get(i));
            }
            return equal;
        }
    }

    public static void truncate(BigInt n1) {
        int remainder = 0;
        int temp = 0;

        for (int i = 0; i < n1.number.size(); i++) {
            int n = n1.number.get(i);
            if (n > 0 && n % 2 == 1) {
                temp = remainder;
                remainder = 5;
                n1.number.set(i, (n / 2) + temp);
            } else {
                temp = remainder;
                n1.number.set(i, (n / 2) + temp);
                remainder = 0;
            }
        }
    }

    public static BigInt mulitply(BigInt n1, BigInt n2) {

        boolean negative = false;
        if (n1.negative && !n2.negative) {
            negative = true;
        } else if (!n1.negative && n2.negative) {
            negative = true;
        }

        BigInt result = new BigInt("0");
        BigInt a = new BigInt(n1.toString());

        if (a.toString().charAt(0) == '-') {
            a = new BigInt(a.toString().substring(1));
        }
        if (n2.toString().charAt(0) == '-') {
            n2 = new BigInt(n2.toString().substring(1));
        }

        ArrayList<Integer> number1 = a.number;
        ArrayList<Integer> number2 = n2.number;
        int numlength = 0;

        if (number1.size() < number2.size()) {
            BigInt k = a;
            numlength = number1.size();
            number1 = number2;
            number2 = a.number;
            a = n2;
        } else {
            numlength = number2.size();
        }

        int zeropad = 0;
        for (int i = numlength; i > 0; i--) {
            int times = number2.get(i - 1);
            BigInt num = new BigInt("0");
            String zero = "";
            for (int x = 0; x < zeropad; x++) {
                zero += "0";
            }

            for (int x = 0; x < times; x++) {
                num = add(num, a);
            }
            num = new BigInt(num.toString() + zero);
            result = add(result, num);
            zeropad++;
        }
        if (negative) {
            result = new BigInt("-" + result.toString());
        }
        return result;
    }

    public static String[] divide(BigInt n1, BigInt n2) {
        boolean aNeg = n1.negative;
        boolean bNeg = n2.negative;
        n1.negative = false;
        n2.negative = false;
        String[] result = {"", "0"};
        String remainder = "";

        
        if (n1.number.size() < n2.number.size()) {
            result[0] = "0";
            result[1] = n1.toString();
            return result;
        } else if (n2.number.get(0) == 0) {
            result[0] = "0";
            result[1] = "0";
            return result;
        } else if (n1.number.size() == n2.number.size()) {

            boolean numbersEqual = true;
            int index = 0;
            while (numbersEqual && index < n1.number.size()) {

                int num1 = n1.number.get(index);
                int num2 = n2.number.get(index);
                if (num1 < num2) {
                    result[0] = "0";
                    if (aNeg) {
                        result[1] = "-" + n1.toString();
                    } else {
                        result[1] = n1.toString();
                    }
                    return result;
                } else if (num1 > num2) {
                    numbersEqual = false;
                }
                index++;
            }

            if (numbersEqual) {
                result[0] = "1";
                result[1] = "0";
                if (((aNeg || bNeg) && (!aNeg || !bNeg)) && result[0].compareTo("0") != 0) {
                    result[0] = "-" + result[0]; 
            }
                return result;
            }

        }

        if (n1.number.size() < 9 && n2.number.size() < 9) {
            int num1 = Integer.parseInt(n1.toString());
            int num2 = Integer.parseInt(n2.toString());
            result[0] = Integer.toString(num1 / num2);
            result[1] = Integer.toString(num1 % num2);
            
            if (((aNeg || bNeg) && (!aNeg || !bNeg)) && result[0].compareTo("0") != 0) {
                result[0] = "-" + result[0]; 
            }
            return result;
        }
        
        result = longDivision(n1, n2);
        if (result[1].length() > 1 && result[1].charAt(0) == '0') {
			while (result[1].charAt(0) == '0') {
				result[1] = result[1].substring(1);
			}
        }

		 if (result[0].length() > 1 && result[0].charAt(0) == '0') {
			while (result[0].charAt(0) == '0') {
				result[0] = result[0].substring(1);
			}
        }
		
		if (((aNeg || bNeg) && (!aNeg || !bNeg)) && result[0].compareTo("0") != 0) {
            result[0] = "-" + result[0];
        }
		
        return result;
    }

    private static String[] longDivision(BigInt n1, BigInt n2) {
        String newNum = "";
        ArrayList<Integer> dividend = n1.number;

        BigInt temp = new BigInt("");
        String[] result = {"", "0"};

        int index = 0;
        int num1 = dividend.get(index);
        temp.setNumber(Integer.toString(num1));

        while (index < dividend.size()) {
            num1 = dividend.get(index);
            temp.setNumber(result[1] + num1);
            if (compare(temp, n2) < 0) {
                result[0] = "0";
                result[1] = temp.toString();
            } else {
                result[0] = "";
                result = divisionHelper(temp, n2, result);
                result[0] = Integer.toString(result[0].length());
            }

            newNum += result[0];
            index++;
        }

        result[0] = newNum;
        return result;
    }

    private static String[] divisionHelper(BigInt n1, BigInt n2,
            String[] result) {

        BigInt temp = n1;
        int compare = compare(temp, n2);

        while (compare >= 0) {
            result[0] += "1";
            temp = subtract(temp, n2);
            compare = compare(temp, n2);

            if (compare == 0) {
                result[1] = "0";
            } else if (compare > 0) {
                result[1] = temp.toString();
            } else {
                result[1] = temp.toString();
            }
        }

        return result;
    }

    public static BigInt gcd(BigInt n1, BigInt n2) {
        BigInt a;
        BigInt c;

        if (compare(n1, n2) < 0) {
            a = n2;
            c = n1;
        } else {
            a = n1;
            c = n2;
        }

        String[] result;
        BigInt remainder;
        do {
            result = divide(a, c);
            remainder = new BigInt(result[1]);
            if (remainder.toString().compareTo("0") == 0) {
                break;
            }
            a = c;
            c = remainder;
        } while (true);

        return c;

    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        if (negative) {
            s.append('-');
        }
        for (int i = 0; i < number.size(); i++) {
            s.append(abs(number.get(i)));
        }
        return s.toString();
    }
}