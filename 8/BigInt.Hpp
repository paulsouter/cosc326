#pragma once
#ifndef BigInt_HPP
#define BigInt_HPP

#include <vector>
#include <string>


class BigInt {

private:
	std::vector <int> number;
	bool negative;
	bool operand;


public:
	void setNumber(std::string n);
	BigInt(std::string number);
	BigInt(std::vector<int> num);
	BigInt add(BigInt num1, BigInt num2);
	BigInt sub(BigInt num1, BigInt num2);
	BigInt mulitply(BigInt n1, BigInt n2);
	int compare(BigInt num1, BigInt num2);
	void half(BigInt n1);
	std::string toString();
	std::vector<int> getNum() { return number; }
	bool isNegative() { return negative; }
	void setNegative(bool set) { negative = set; }
	bool getOperand() { return operand; }
	void setOperand(bool set) { operand = set; }
};
#endif
