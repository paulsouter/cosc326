/*
	Ryan Swanepoel
	Paul Souter
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//#include <cstdlib>
//#include <decimal/decimal>
#include <algorithm>
#include <set>
#include <cstdio>
#include <ctime>
#include <queue>

using namespace std;

struct word {
	vector<int> chain;
	int position;
};

set<int> usedWords {};
vector<string> GlobalDict;
queue<word> wordQ;
int queueSize =0;

bool wordComp(string left,string right,int flag){
	for(int i=0;i<left.length();i++){
		string sub1 = left.substr (i);
		if (sub1.length() <= right.length()){
			string sub2 = right.substr (0,sub1.length());
			if(sub1 == sub2){
				double subLen = (double) sub1.length();
				double wordLen = (double) right.length() /2;
				double nextLen = (double) left.length() /2;
				if(flag == 0){
					if ((subLen >= wordLen && subLen < nextLen)
							|| (subLen < wordLen && subLen >= nextLen)){
						return true;
					}
				}else if (flag == 1){
					if (subLen >= wordLen && subLen >= nextLen){
						return true;
					}
				}
			}
		}
	}
	return false;
}

vector<int> narrow(string word,int flag){
	vector<int> tempSingly;
	vector<int> tempDoubly;
	tempSingly.clear();
	tempDoubly.clear();
	for(int j = 0;j<GlobalDict.size();j++){
		string next = GlobalDict.at(j);
		if(next == word) usedWords.insert(j);
		if(wordComp(word,next,flag)){
			if(flag == 0){
				if(usedWords.insert(j).second == true){
					tempSingly.push_back(j);
				}
			}else if (flag == 1){
				if(usedWords.insert(j).second == true){
					tempDoubly.push_back(j);
				}
			}
		}
		
	}
	if (flag == 0){ 
		return tempSingly;
	}
	if (flag == 1){ 
		return tempDoubly;
	}
}

string joining(string ending,int flag){
	string result = "";
	while (wordQ.size() > 0){
		word current = wordQ.front();
		if (wordComp(GlobalDict.at(current.position),ending,flag)){
			for(int i =0; i<current.chain.size();i++){
				result += " ";
				result += GlobalDict.at(current.chain.at(i));
			}
			result += " ";
			result += GlobalDict.at(current.position);
			return result;
		}else{
			vector<int> children = narrow(GlobalDict.at(current.position),flag);
			vector<int> newChain = current.chain;
			newChain.push_back(current.position);
			clock_t start = clock();
			for(int i = 0;i<children.size();i++){
				word child;
				child.chain = newChain;
				child.position = children.at(i);
				wordQ.push (child);
				queueSize++;
			}
			double duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
			if (duration > 0.1) cout << "loop time taken: " << duration << endl;
		}
		wordQ.pop();
	}
	return "empty";
}

void excecute(string first, string second){
	int firstLen = first.length();
	int secondLen = second.length();
	vector<string> joins;
	
	vector<string> tempSingle;
	vector<string> tempDouble;
	
	string singly = "";
	string doubly = "";
	
	if(wordComp(first,second,0)) singly = "2 "+first+" "+second;
	if(wordComp(first,second,1)) doubly = "2 "+first+" "+second;
	
	//singly joined
	queueSize =0;
	usedWords.clear();
	if (singly.length() == 0){
		queue<word> empty;
		swap(wordQ,empty);
		vector<int> children = narrow(first,0);
		vector<int> newChain;
		for(int i = 0;i<children.size();i++){
			word child;
			child.chain = newChain;
			child.position = children.at(i);
			wordQ.push (child);
		}
		clock_t start = clock();
		singly = joining(second,0);
		double duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
		cout << "time taken: " << duration << endl;
		cout << "queue size: " << queueSize << endl;
		int count = 2;
		for(int i = 0; i<singly.length();i++){
			if(singly.at(i) == ' '){
				count++;
			}
		}
		if(count > 2){
			string tempc = to_string(count);
			singly = tempc + " " + first + singly + " " + second;
		}else{
			singly = "0";
		}
	}
	cout << singly << endl;
	
	//doubly joined
	queueSize =0;
	usedWords.clear();
	if (doubly.length() == 0){
		queue<word> empty;
		swap(wordQ,empty);
		vector<int> children = narrow(first,1);
		vector<int> newChain;
		for(int i = 0;i<children.size();i++){
			word child;
			child.chain = newChain;
			child.position = children.at(i);
			wordQ.push (child);
		}
		clock_t start = clock();
		doubly = joining(second,1);
		double duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
		cout << "time taken: " << duration << endl;
		cout << "queue size: " << queueSize << endl;
		int count = 2;
		for(int i = 0; i<doubly.length();i++){
			if(doubly.at(i) == ' '){
				count++;
			}
		}
		if(count > 2){
			string tempc = to_string(count);
			doubly = tempc + " " + first + doubly + " " + second;
		}else{
			doubly = "0";
		}
	}
	cout <<doubly<<endl;	
}
int main (int argc, char *argv[]){
	while (true){
		string mystr;
		
		string first = argv[1];
		string second = argv[2];
		GlobalDict.clear();
		usedWords.clear();
		queue<word> empty;
		swap(wordQ,empty);
		
		int count =0;
		while (!cin.eof()){
			getline (cin,mystr);
			GlobalDict.push_back(mystr);
			count++;
		}
		excecute(first,second);
		break;
	}
}