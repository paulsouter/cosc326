#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include<ctype.h>

using namespace std;

void display(string cards[5]) {
	for (int i = 0; i < 5; i ++ ) {
		if (cards[i].size() == 3) {
			if (cards[i].substr(0, 2).compare("14") == 0) {
				cards[i].replace(0, 2, "A");
			}
			else if (cards[i].substr(0, 2).compare("13") == 0) {
				cards[i].replace(0, 2, "K");
			}
			else if (cards[i].substr(0, 2).compare("12") == 0) {
				cards[i].replace(0, 2, "Q");
			}
			else if (cards[i].substr(0, 2).compare("11") == 0) {
				cards[i].replace(0, 2, "J");
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		cout << cards[i] + " ";
	}
	cout << cards[4] << endl;
}
void sort(string (&cards)[5]) {
	int size = 5;
	int j;
	string temp;
	for (int i = 0; i < size; i++) {
		j = i;
		while (j > 0) {
			if ((stoi(cards[j].substr(0, cards[j].size() - 1)) < stoi(cards[j - 1].substr(0, cards[j - 1].size() - 1)))) {
				temp = cards[j];
				cards[j] = cards[j - 1];
				cards[j - 1] = temp;
			}else if ((((stoi(cards[j].substr(0, cards[j].size() - 1)) == stoi(cards[j - 1].substr(0, cards[j - 1].size() - 1))) &&
				cards[j].at(cards[j].size() - 1) < (cards[j - 1].at(cards[j - 1].size() - 1))))) {
				temp = cards[j];
				cards[j] = cards[j - 1];
				cards[j - 1] = temp;
			}
			j--;
		}
	}
}


bool isValid(string hand) {
	string cards[5];
	char separtor;
	int i = 0;
	int x;
	int y = 0;

	if (hand.size() < 14 || hand.size() > 19) {
		return false;
	}
	//checks if there  a separtor
	while (isalnum(hand.at(i)) !=0) {
		i++;
		if (i == hand.size() - 1) {
			return false;
		}
	} 
	separtor = hand.at(i);
	if (separtor == ' ') {
	}
	else if (separtor == '-') {
	}
	else if (separtor == '/') {
	}
	else {
		return false;
	}

	//makes the array of cards
	for (x = 0; x < 5; x++) {
		if (x == 4) {
			cards[x] = hand.substr(y);
		}
		else {
			cards[x] = hand.substr(y, i);
		}
		y += i + 1;
		if (x != 4 && x != 3) {
			i = hand.find(separtor,  y);
			//finds if there not enough separtors 
			if (i == -1) {
				return false;
			}
			i = i - y;
		}

		//checks if theres a sepator at the end
		if (x == 4 && hand.find(separtor, y) == hand.size()) {
			return false;

		}
		//size of card
		if (cards[x].size() > 3 || cards[x].size() < 1) {
			return false;
		}
	}


	for (x = 0; x < 5; x++) {
		//suit toupper
		if (cards[x].size() == 2) {
			if (isalpha(cards[x].at(1)) != 0) {
				cards[x].at(1) = toupper(cards[x].at(1));
			}
			else {
				return false;
			}
		}
		if (cards[x].size() == 3) {
			if (isalpha(cards[x].at(2)) != 0)
				cards[x].at(2) = toupper(cards[x].at(2));
			else {
				return false;
			}

		}

		//checking numbers
		if (cards[x].at(0) == '0') {
			return false;
		}
		if (cards[x].size() == 3) {
			if (isalpha(cards[x].at(1)) != 0) {
				return false;
			}
			if (stoi(cards[x].substr(0, 2)) > 13) {
				return false;
			}
		}

		//check A J Q K
		if (isalpha(cards[x].at(0)) != 0) {
			if (cards[x].at(0) == 'a' || cards[x].at(0) == 'A') {
				cards[x].replace(0, 1, "14");
			}
			else if (cards[x].at(0) == 'j' || cards[x].at(0) == 'J') {
				cards[x].replace(0, 1, "11");
			}
			else if (cards[x].at(0) == 'q' || cards[x].at(0) == 'Q') {
				cards[x].replace(0, 1, "12");
			}
			else if (cards[x].at(0) == 'k' || cards[x].at(0) == 'K') {
				cards[x].replace(0, 1, "13");
			}
			else if (cards[x].at(0) == 't' || cards[x].at(0) == 'T') {
				cards[x].replace(0, 1, "10");
			}
			else {
				return false;
			}
		}

		//1 to 14 for sorting
		if (cards[x].size() == 2) {
			if (cards[x].at(0) == '1') {
				cards[x].replace(0, 1, "14");

			}
		}

		// suit
		char suit = cards[x].at(cards[x].size() - 1);
		if (suit == 'S'){
		}else if (suit == 'H') {
		}else if (suit == 'D') {
		}else if(suit == 'C') {
		}
		else {
			return false;
		}
		
	}
//	cout << "finshed for loop 2" << endl;
	sort(cards);
//	cout << "finished sort" << endl;
	for (int x = 0; x < 4; x++) {
		if (cards[x].compare(cards[x+1]) == 0) {
			return false;
		}
	}
	display(cards);
	return true;
	
}
int main() {
	vector<string> hands;
	int numberOfHands = 0;
	string hand = "start of input";
	while (getline(cin, hand)) {
		numberOfHands++;
		if (!isValid(hand)) {
			cout << "invalid: " + hand << endl;
		}
	}

	return 0;
}