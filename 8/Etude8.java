    
import java.util.Arrays;
import java.util.Scanner;

/**
 * William Sanson 4213239
 * Paul Souter 4876118
 * 
 * Works with javac 1.8.0_31
 *
 * Program reads in integers and operations, and performs arithmetic using 
 * a big integer class.
 */
public class Etude8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String[] operators = {"+", "-", "<", ">", "*", "/", "=", "gcd"};

        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] input = line.split(" ");

            if (!line.isEmpty() && line.charAt(0) != '#') {
                System.out.println(line);

                if (input.length == 3) {
                    boolean operation = Arrays.asList(operators)
                            .contains(input[1]);

                    if (!operation) {
                        System.out.println("# Syntax error" + "\n");
                    } else if (!input[0].matches("^-?\\d+$")
                            || !(input[2].matches("^-?\\d+$"))) {
                        System.out.println("# Syntax error" + "\n");
                    } else {

                        BigInt a = new BigInt(input[0]);
                        BigInt b = new BigInt(input[2]);
                        switch (input[1]) {
                            case "+":
                                System.out.println("# "
                                        + BigInt.add(a, b) + "\n");
                                break;
                            case "-":
                                System.out.println("# "
                                        + BigInt.subtract(a, b) + "\n");
                                break;
                            case "*":
                                System.out.println("# "
                                        + BigInt.mulitply(a, b) + "\n");
                                break;
                            case "/":
                                String[] div = BigInt.divide(a, b);
                                System.out.println("# "
                                        + div[0] + " " + div[1] + "\n");
                                break;
                            case "<":
                                System.out.println("# "
                                        + (BigInt.compare(a, b) < 0) + "\n");
                                break;
                            case ">":
                                System.out.println("# "
                                        + (BigInt.compare(a, b) > 0) + "\n");
                                break;
                            case "=":
                                System.out.println("# "
                                        + (BigInt.compare(a, b) == 0) + "\n");
                                break;
                            case "gcd":
                                System.out.println("# "
                                        + BigInt.gcd(a, b) + "\n");
                                break;
                        }
                    }
                } else {
                    System.out.println("# Syntax error" + "\n");
                }
            }

        }
    }

}
