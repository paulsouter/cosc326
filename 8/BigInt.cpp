#include "BigInt.hpp"
#include <iostream>

using namespace std;
BigInt::BigInt(string num) {
	bool zeroPadding = false;
	for (int i = 0; i < num.size(); i++) {
		if (num.at(0) == '0') {
			if (i == 0) {
				zeroPadding = true;
			}
			else if (num.at(i) != '0') {
				zeroPadding = false;
			}
		}
		if (!zeroPadding) {
			//	number.push_back(num.at(i) - '0');
			number.push_back(num.at(i));
		}
	}
	if (number.empty()) {
		number.push_back(0);
	}
}

void BigInt::setNumber(string n) {
	bool zeroPadding = false;

	if (n.size() == 1 && n.at(0) == '0') {
		number.push_back(0);
	}
	else if (!n.empty() && n.at(0) != '-') {
		for (int i = 0; i < n.size(); i++) {
			if (n.at(0) == '0') {
				if (i == 0) {
					zeroPadding = true;
				}
				else if (n.at(i) != '0') {
					zeroPadding = false;
				}
			}
			if (!zeroPadding) {
				number.push_back(n.at(i) - "0");
			}
		}
	}
	else {
		negative = true;
		for (int i = 1; i < n.size(); i++) {
			if (n.at(1) == '0') {
				if (i == 1) {
					zeroPadding = true;
				}
				else if (n.at(i) != '0') {
					zorePadding = false;
				}
			}
			if (!zeroPadding) {
				if (n.at(i) != '-') {
					number.push_back(n.at(i) - '0');
				}
			}
		}
	}
	if (number.empty()) {
		negative = false;
		number.push_back(0);
	}
}

BigInt::BigInt(vector<int> num) {
	number = num;
}

BigInt BigInt::add(BigInt n2) {
	vector <int> newNumber;
	vector <int> number2 = n2.getNum();
	int num1Size = number.size();
	int num2Size = number2.size();
	int remainder = 0;
	int sum = 0;
	int num1 = 0;
	int num2 = 0;

	if (this->getOperand) {
		if (this->getNegative && !n2.getNegative) {
			n2.setOperand(false);
			return subtract(n1, this)
		}
		else {
			n2.setOperand(false);
			return add(this, n2)
		}

	else if (!this->getNegative && n2.getNegative) {
		if (num1Size >= num2Size) {
			this->setNegative(false);
			return subtract(this, n2);
		}
		else {
			n2.setNegative(true);
			n2.setOperand(false);
			return subtract(n2, this);
		}
	}
	}
	if (num1Size == num2Size) {
		int index = num1Size - 1;
		while (index >= 0) {
			num1 = number.at(index);
			num2 = number2.at(index);
			sum = num1 + num2 + remainder;
			newNumber.push_back(sum % 10);
			if (sum >= 10)
				remainder = 1;
			else
				remainder = 0;
			index--;
		}
		if (remainder == 1) {
			newNumber.push_back(1);
		}
	}
	else {
		int index1 = num1Size - 1;
		int index2 = num2Size - 1;
		int sizeDiff = num1Size - num2Size;

		if (sizeDiff > 0) {
			while (index1 >= 0) {
				while (index2 >= 0) {
					num1 = number.at(index1);
					num2 = number2.at(index2);
					newNumber.push_back(sum % 10);
					if (sum >= 10)
						remainder = 1;
					else
						remainder = 0;
					index1--;
					index2--;
				}
				if (remainder == 1) {
					num1 = number.at(index1);
					sum = num1 + remainder;
					newNumber.push_back(sum % 10);
					if (sum >= 10)
						remainder = 1;
					else
						remainder = 0;
				}
				else {
					newNumber.push_back(number.at(index1));
				}
				index1--;
			}
			if (remainder == 1) {
				newNumber.push_back(1);
			}
			else {
				n2.setOperand(false);
				return add(n2, n1);
			}
		}
		/*	else {
				while (index2 >= 0) {
					while (index1 >= 0) {
						num1 = number.at(index1);
						num2 = number2.at(index2);
						sum = num1 + num2 + remainder;
						newNumber.push_back(sum % 10);
						if (sum >= 10)
							remainder = 1;
						else
							remainder = 0;
						index1--;
						index2--;
					}
					if (remainder == 1) {
						num2 = number2.at(index2);
						sum = num2 + remainder;
						newNumber.push_back(sum % 10);
						if (sum >= 10)
							remainder = 1;
						else
							remainder = 0;
					}
					else {
						newNumber.push_back(number2.at(index2));
					}
					index2--;
				}
			}*/
	}
	string reverse;
	for (int i = newNumber.size() - 1; i >= 0; i--) {
		reverse += newNumber.at(i);
	}
	if (n1.getNegative()) {
		reverse.insert(0, "-");
	}
	BigInt result(reverse);
	return result;
}

vector<int> subractionHelper(vector<int> n1, vector<int> n2, vector<int> n3) {
	int num1;
	int num2;
	int num3;
	int sum;
	int remainder;
	int index = n1.size() - 1;

	while (index >= 0) {
		num1 = n1.at(index);
		num2 = n2.at(index);
		sum = (num1 + remainder) - num2;

		remainder = (sum < 0 ? -1 : 0);
		if (sum >= 0) {
			n3.add(sum);
		}
		else if (sum < 0 && index != 0) {
			n3.add(10 + sum);
		}
		index--;
	}
	if (remainder < 0 && n3.empty())){
	n3.add(sum);
	return n3;
}
}

BigInt BigInt::sub(BigInt n1, BigInt n2) {
	vector<int> newNumber;
	vector<int> number1 = n1.getNum();
	vector<int> number2 = n2.getNum();
	int num1Size = number1.size();
	int num2Size = number2.size();
	int remainder = 0;
	int sum = 0;
	int num1 = 0;
	int num2 = 0;

	if (n1.operand) {
		if (!n1.isNegative() && n2.isNegative()) {
			if (num1Size >= num2Size) {
				n1.setOperand(false);
				return add(n1, n2);
			}
			else {
				BigInt newNum = new BigInt(n2.getNum());
				newNum.setOperand(false);
				return add(newNum, n1);
			}
		}
		else if (n1.isNegative() && !n2.isNegative()) {
			if (num1Size >= num2Size) {
				n1.setOperand(false);
				return add(n1, n2);
			}
			else {
				BigInt numNum = new BigInt(n2.getNum());
				newNum.setNegative(true);
				newNum.setOperand(false);
				return add(newNum, n1);
			}
		}
	}
	if (num1Size == num2Size) {
		int index = num1Suze - 1;
		while (index >= 0) {
			num1 = number1.at(index);
			num2 = number2.at(index);
			sum = num1 + num2 + remainder;
			newNumber.add(sum % 10);
			remainder = (sum >= 10 ? 1 : 0);
			index--;
		}
		if (remainder == 1) {
			newNumber.push_back(1);
		}
	}
	else {
		int index1 = num1Size - 1;
		int index2 = num2Size - 1;
		if (num1Size > num2Size) {
			while (index1 >= 0) {
				while (index2 >= 0) {
					num1 = number1.at(index1);
					num2 = number2.at(index2);
					sum = num1 + num2 + remainder;
					newNumber.push_back(sum % 10);
					remainder = (sum >= 10 ? 1 : 0);
					index1--;
					index2--;
				}
				if (remainder == 1) {
					num1 = number1.at(index1);
					sum = num1 + remainder;
					newNumber.push_back(sum % 10);
					remainder(sum >= 10 ? 1 : 0);
				}
				else {
					newNumber.push_back(number1.at(index1);
				}
				index1--;
			}
			if (remainder == 1) {
				newNumber.push_back(1);
			}
		}
		else {
			n2.setOperand(false);
			return add(n2, n1);
		}
	}
	reverse(newNumber.begin()), newNumber.end());

	string s;
	if (n1.isNegative()) {
		s += "-";
	}
	for (int x : newNumber) {
		s += to_string(x);
	}
	BigInt c = new BigInt(s);
	c.setNegative(neg);
	return c;
}

int BigInt::compare(BigInt n1, BigInt n2) {
	vector <int> number2 = num2.getNum();
	vector<int> number1 = num1.getNum();

	if (!n1.isNegative() && n2.isNegative()) {
		return 1;
	}
	if (n1.isNegative() && n2.isNegative()) {
		return -1;
	}
	if (number1.size() > number2.size()) {
		return 1;
	}
	else if (number1.size() < number2.size()) {
		return -1;
	}
	else {
		int equal = 0;
		for (int i = 0; i < number1.size() && equal == 0; i++) {
			if (number1.at(i) > number2.at(i))
				equal = 1;
			else if (number1.at(i) < number2.at(i))
				equal = -1;
			else
				equal = 0;
		}
		return equal;
	}
}

void BigInt::half(BigInt n1) {//need to change to truncate
	int remainder = 0;
	int temp;

	for (int i = 0; i < n1.getNum().size(); i++) {
		int n = n1.getNum().at(i);
		if (n > 0 && n % 2 == 1) {
			temp = remainder;
			remainder = 5;
			n1.getNum().at(i) = (n / 2) + temp;
		}
		else {
			temp = remainder;
			n1.getNum().at(i) = (n / 2) + temp;
			remainder = 0;
		}
	}
}
//here mulitply

BigInt BigInt::mulitply(BigInt n1, BigInt n2) {
	bool negative = false;

	if (n1.isNegative() && !n2.isNegative()) {
		negative = true;
	}
	else if (!n1.isNegative() && n2.isNegative()) {
		negative = true;
	}

	BigInt result = new BigInt("0");
	BigInt a = new BigInt(n1.toString());

	if (a.toString().at(0) == '-') {
		a = new BigInt(a.toString().substr(1));
	}
	if (n2.toString().at(0) == '-') {
		n2 = new BigInt(n2.toString().substr(1));
	}

	vector<int> number1 = a.getNum();
	vector<int> number2 = n2.getNum();
	int numlength = 0;

	if (number1.size() < number2.size()) {
		numlength = number1.size();
		number1 = number2;
		number2 = a.getNum();
		a = n2;
	}
	else {
		numlength = number2.size();
	}

	int zeropad = 0;
	for (int i = numlength; i > 0; i--) {
		int times = number2.at(i - 1);
		BigInt num = new BigInt("0");
		string zero = "";
		for (int x = 0; x < zeropad; x++) {
			zero += "0";
		}
		for (int x = 0; x < times; x++) {
			num = add(result, num);
		}
		num = new BigInt(num.toString() + zero);
		result = add(result, num);//i think that this break it add needs to be refernce by a bigint
		zeropad++;
	}
	return result;
}

vector<string> divisionHelper(BigInt n1, BigInt n2, vector<string> result) {
	BigInt temp = n1;
	int compare = compare(temp, n2);
	while (compare >= 0) {
		result[0] += "1";
		temp = sub(temp, n2);
		compare = compare(temp, n2);

		if (compare == 0) {
			result[1] = "0";
		}
		else if (compare > 0) {
			result[1] = temp.toString();
		}
		else {
			reuslt[1] = temp.toString();
		}
	}
	return result;
}

string BigInt::toString() {
	string result;
	if (negative) {
		s += "-";
	}
	for (int i = 0; i < number.size(); i++) {
		result += (number.at(i));
	}
	return result;
}
