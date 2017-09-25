#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findFactors(int a, vector<int> &redGreen) {
	int result = 0;
	int k = 1;
	while (k <= a / 2) {
		int d = a / k;
		if (k == a/d) {
			if (redGreen.at(k) == 0) {
				result += findFactors(k, redGreen);
			}
			else {
				if (redGreen.at(k) == 1) {
					result++;
				}
				else if (redGreen.at(k) == -1) {
					result--;
				}
			}
		}
		k++;
	}
	if (result > 0) {
		redGreen.at(a) = -1;//red
		return -1;
	}
	else {
		redGreen.at(a) = 1;//green
		return 1;
	}
}

int main() {
	string input;
	string result;
	int a;
	int b;
	int arrayLength;
	vector <int> redGreen;
	while (getline(cin, input)) {
		if (!input.empty()) {
			if (input.at(0) != '#') {
				a = stoi(input.substr(0, input.find(' ')));
				b = stoi(input.substr(input.find(' ')));
				arrayLength = (a + b);
				redGreen.resize(arrayLength);
				redGreen[1] = 1;
				for (int i = a; i < (a + b); i++) {
					int r = findFactors(i, redGreen);
					if (r == 1) {
						result.append("G");
					}
					if (r == -1) {
						result.append("R");
					}
				}
				cout << input << endl;
				cout << "# " << result << "\n" << endl;
				result = "";
			}
		}
	}
	return 0;
}