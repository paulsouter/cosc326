#include <iostream>
#include "Shapes.hpp"
#include <map>

typedef void(*FnPtr)(int[][], int, int);
using namespace std;

long tryCarpet(int carpet[][], piece) {
	{
		map<int, FnPtr> shape;
		shape[1] = shape1;
		shape[2] = shape2;
		shape[3] = shape3;
		shape[4] = shape4;
		shape[5] = shape5;
		shape[6] = shape6;
		shape[7] = shape7;
		shape[8] = shape8;
		shape[9] = shape9;
		shape[10] = shape10;
		shape[11] = shape11;
		shape[12] = shape12;
		shape[13] = shape13;
		shape[14] = shape14;
		shape[15] = shape15;
		shape[16] = shape16;
		shape[17] = shape17;
		shape[18] = shape18;
		shape[19] = shape19;
	}
	int x = 0;
	int y = 0;
	while (x < carpet.size()) {
		while (y < carpet[x].size()) {
			int i = 1;
			while (carpet[x][y] == 0) {
				shape[i](carpet, x, y);
				i++;
				if (i == 19)
					break;
			}
			y++;
		}
		x++;
	}

}

long execute(int width, int length) {
	long result;
	int piece = 0;

	while (piece < 19) {
		int carpet[width][length];
		result += tryCarpet(carpet, piece);
		piece++;
	}
	return result;
}
int main() {

	long result;
	int width;
	int lenght;
	string input;

	while (getline(cin, input)) {
		if (!input.empty()) {
			width = input.substr(0, input.find(" "));
			length = input.substr(input.find(" ") + 1);
			result = execute(width, length);
			cout << length << endl;
		}
	}
}

