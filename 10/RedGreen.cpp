// compile with g++ -std=c++11 -stdlib=libc++ RedGreen.cpp 

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>

std::map<int, char> factors;
std::string output;

int findColour(int n) {
	int nearFactor = 1;
    int factorColours = 0;
    while (nearFactor <= n / 2) {
    	int d = n / nearFactor;
    	if (n / d == nearFactor) {
    		if (factors.find(nearFactor) != factors.end()) {
    			if (factors.find(nearFactor)->second == 'G') {
    				factorColours += 1;
    			} else {
    				factorColours -= 1;
    			}
    		} else {
    			factorColours += findColour(nearFactor);
    		}
    	}
    	nearFactor++;
    }
	if (factorColours <= 0) {
    	factors.insert(std::pair<int, char>(n, 'G'));
    	return 1;
    } else {
    	factors.insert(std::pair<int, char>(n, 'R'));
        return -1;
    }
}


void processInput(std::string input) {
	std::vector<int> inputInts;
    std::istringstream iss(input);
    for(std::string input; iss >> input; ) {
        inputInts.push_back(stoi(input));
    }
    factors.insert(std::pair<int, char>(1, 'G'));
    for(int i = inputInts[0]; i < inputInts[0] + inputInts[1]; i++) {
    	output += (findColour(i) == 1) ? 'G' : 'R';
    } 
}

int main(int arg, char **argv) {
	
    std::string input;
    while (std::getline(std::cin, input) && !input.empty()) {
    	if (input[0] != '#') {
    		std::cout << input << std::endl;
    		processInput(input);	
    		std::cout << "# " << output << "\n" << std::endl;
    		output = "";
    	}
    }
                  
    return EXIT_SUCCESS;
}


