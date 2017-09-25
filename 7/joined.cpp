/*
	Ryan Swanepoel
	Paul Souter
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <ctime>

using namespace std;

struct word {
	vector<int> chain;
	int position;
};

vector<string> GlobalDict;
vector<bool> usedIndex;
vector<bool> allFalse;
vector<int> currChildren;

queue<word> wordQ;
int depthC = 0;

bool wordComp(string left,string right,int flag){
	double wordLen = (double) (right.length()-1) /2;
	double nextLen = (double) (left.length()-1) /2;
	for(int i = left.length()-1;i>0;i--){
		if(i >= nextLen || i >= wordLen){
			string sub1 = left.substr (i);
			if (sub1.length() <= right.length()){
				string sub2 = right.substr (0,sub1.length());
				if(sub1 == sub2){
					double subLen = (double) sub1.length();
					if(flag == 0){
						if ((subLen >= wordLen || subLen >= nextLen)){
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
	}
	return false;
}

void narrow(string word,int flag){
	currChildren.clear();
	for(int j = 0;j<GlobalDict.size();j++){
		string next = GlobalDict[j];
		if(next != word){
			if(wordComp(word,next,flag)){
				if(!usedIndex[j]){
					currChildren.emplace_back(j);
					usedIndex[j]=true;
				}
			}
		}
	}
}

string joining(string ending,int flag){
	string result = "";
	while (wordQ.size() > 0){
		word current = wordQ.front();
		if (wordComp(GlobalDict[current.position],ending,flag)){
			for(int i =0; i<current.chain.size();i++){
				result += (" " + GlobalDict[current.chain[i]]);
			}
			result += (" " + GlobalDict[current.position]);
			return result;
		}else{
			narrow(GlobalDict[current.position],flag);
			vector<int> children = currChildren;
			vector<int> newChain = current.chain;
			newChain.emplace_back(current.position);
			if (newChain.size() > depthC) depthC = newChain.size();
			for(int i = 0;i<children.size();i++){
				word child;
				child.chain = newChain;
				child.position = children[i];
				wordQ.push (child);
			}
		}
		wordQ.pop();
	}
	return "empty";
}
void excecute(string first, string second){
	string singly = "";
	string doubly = "";
	int chainT;
	if(wordComp(first,second,0)) singly = "2 "+first+" "+second;
	if(wordComp(first,second,1)) doubly = "2 "+first+" "+second;
	if(first == second){
		singly = "1 "+first;
		doubly = "1 "+first;
	}
	
	//doubly joined
	clock_t start2 = clock();
	if (doubly.length() == 0){
		narrow(first,1);
		vector<int> children = currChildren;
		vector<int> newChain;
		for(int i = 0;i<children.size();i++){
			word child;
			child.chain = newChain;
			child.position = children[i];
			wordQ.push (child);
		}
		doubly = joining(second,1);
		int count = 2;
		for(int i = 0; i<doubly.length();i++){
			if(doubly.at(i) == ' '){
				count++;
			}
		}
		chainT = count;
		if(count > 2){
			string tempc = to_string(count);
			doubly = tempc + " " + first + doubly + " " + second;
		}else{
			doubly = "0";
		}
	}	
	double duration2 = ( clock() - start2 ) / (double) CLOCKS_PER_SEC;
	
	cout << "depht " << depthC << endl;
	//singly joined
	clock_t start = clock();
	depthC = 0;
	if(chainT == 3) singly = doubly;
	if (singly.length() == 0){
		queue<word> empty;
		swap(wordQ,empty);
		vector<bool> temp(GlobalDict.size());
		usedIndex = temp;
		narrow(first,0);
		vector<int> children = currChildren;
		vector<int> newChain;
		for(int i = 0;i<children.size();i++){
			word child;
			child.chain = newChain;
			child.position = children[i];
			wordQ.push (child);
		}
		singly = joining(second,0);
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
	double duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	
	cout << singly << endl;
	cout << "singly time taken: " << duration << endl;
	
	cout <<doubly<<endl;
	cout << "doubly time taken: " << duration2 << endl;
	
}
int main (int argc, char *argv[]){
	while (true){
		string mystr;
		string first = argv[1];
		string second = argv[2];
		
		int count =0;
		while (!cin.eof()){
			getline (cin,mystr);
			GlobalDict.emplace_back(mystr);
			count++;
		}
		vector<bool> temp(count);
		usedIndex = temp;
		excecute(first,second);
		break;
	}
}