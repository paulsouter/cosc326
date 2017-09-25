/*
Ants on a plane (etude 1)
Created by Ryan Swanepoel and Paul Souter.
compile in terminal using: g++ etude1.cpp -o etude1comp
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

struct Coordinate {
	int x, y;
	Coordinate(int x, int y) : x(x), y(y){}
};

map<int, map<int, char> >  grid;


char getState(int posx, int posy,char initialState){
	//iterate through set
	if(grid.find(posx) != grid.end() && grid[posx].find(posy) != grid[posx].end()){
		return grid[posx][posy];
	}
	grid[posx][posy] = initialState;
	return initialState;
}

int setState(int posx, int posy,char newState,char oldState){
	if(oldState == newState) return 0;
	grid[posx][posy] = newState;
	
	return 0;
}

bool charCheck(string str){
	if(str.length() == 0) return true;
	return false;
}

bool notComment(string str){
	if(str.at(0) == '#') return false;
	return true;
}

bool numCheck(string str){
	if(charCheck(str)) return true;
	if (isdigit(str.at(0))){
		return false;
	}
	return true;
}

void executeProgram(vector<string> storage, int i){
	int count = 0;
	int count2 = 0;
	int posX = 0;
	int posY = -1;
	int length = storage.size();
	string DNA = storage.at(count2);
	//initial direction is from south
	char prevDirect = 'N';
	char nextDirect;
	//initial state is first line of DNA
	char defaultState = storage.at(0).at(0);
	char state;
	string stateChange;
	//travel is NESW respectively
	//DNA Format: w WESN bbbb
	
	while (count <= i){
		if(prevDirect == 'n' || prevDirect == 'N'){
			posY++;
		}else if(prevDirect == 'e' || prevDirect == 'E'){
			posX++;
		}else if(prevDirect == 's' || prevDirect == 'S'){
			posY--;
		}else if(prevDirect == 'w' || prevDirect == 'W'){
			posX--;
		}
		
		state = getState(posX,posY,defaultState);
		
		while(DNA.at(0) != state){
			count2++;
			if (count2 >= length || count2 < 0){
				count2 = 0;
			}
			DNA = storage.at(count2);
		}
		char oldState = state;
		
		if(prevDirect == 'n' || prevDirect == 'N'){
			nextDirect = DNA.at(2);
			state = DNA.at(7);
		}else if(prevDirect == 'e' || prevDirect == 'E'){
			nextDirect = DNA.at(3);
			state = DNA.at(8);
		}else if(prevDirect == 's' || prevDirect == 'S'){
			nextDirect = DNA.at(4);
			state = DNA.at(9);
		}else if(prevDirect == 'w' || prevDirect == 'W'){
			nextDirect = DNA.at(5);
			state = DNA.at(10);
		}
		
		setState(posX,posY,state,oldState);
		prevDirect = nextDirect;
		count++;
	}
	
	//print each line in storage with blank space between each
	for (int i = 0; i < storage.size(); i++) {
		cout << storage[i]<< endl;
	}
	//print i
	cout << i << endl;
	cout << "# " << posX << " " << posY << "\n" << endl;
}

int main (){
	//cout << __cplusplus << endl;
	while (true){
		string mystr;
		vector<string> storage;
		int i;
		bool inputBlank = false;
		
		getline (cin,mystr);
		inputBlank = charCheck(mystr);
		
		while (true){
			if (!inputBlank){
				if(notComment(mystr)){
					storage.push_back(mystr);
				}
				getline (cin,mystr);
				inputBlank = charCheck(mystr);
				if(!numCheck(mystr))break;
			}else{
				getline (cin,mystr);
				if(cin.eof())break;
				inputBlank = charCheck(mystr);
				if(!numCheck(mystr)) break;
			}
		}
		
		if(!cin.eof()){
			i = stoi(mystr);
			executeProgram(storage,i);
			storage.clear();
			grid.clear();
		}else{
			break;
		}
	}
}