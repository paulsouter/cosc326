/*
	Ryan Swanepoel
	Paul Souter
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
//#include <decimal/decimal>
#include <algorithm>
#include <set>
#include <cstdio>
#include <ctime>

using namespace std;

int GCOUNT = 100000;
set<string> troubleMakers {};
set<int> usedWords {};
vector<string> GlobalDict;
clock_t start;

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
		if(next != word){
			if(wordComp(word,next,flag)){
				if(flag == 0){
					if(usedWords.insert(j).second == true && troubleMakers.insert(next).second == true){
						troubleMakers.erase(next);
						tempSingly.push_back(j);
					}
				}else if (flag == 1){
					if(usedWords.insert(j).second == true && troubleMakers.insert(next).second == true){
						troubleMakers.erase(next);
						tempDoubly.push_back(j);
					}
				}
			}
		}
	}
	usedWords.clear();
	if (flag == 0){ 
		return tempSingly;
	}
	if (flag == 1){ 
		return tempDoubly;
	}
}

string joining(string second,vector<int> dictPos,int flag,int depth){
	string result;
	vector<string> list;
	
	if (depth < GCOUNT){			
		for (int j = 0; j<dictPos.size();j++){
			string next = GlobalDict.at(dictPos.at(j));
			if(wordComp(next,second,flag)){
				if (depth < GCOUNT) GCOUNT = depth;
				return " "+next;
			}
		}
		vector<string> words;
		words.clear();
		for (int j = 0; j<dictPos.size();j++){
			string next = GlobalDict.at(dictPos.at(j));
			if(troubleMakers.insert(next).second == true){
				vector<int> newdict = narrow(next,flag);
				result = joining(second,newdict,flag,depth+1);
				if(result.length() >= 3){
					string sub1 = result.substr (result.length()-3,result.length());
					string sub2 = result.substr (0,result.length()-3);
					if (sub1 == "000"){
						if(wordComp(result,second,flag)){
							words.push_back(" "+next+result);
						}else{
						}
					}else if (sub1 != "DEP" && sub1 != "000" && result.length() > 1){
						words.push_back(" "+next+result);
					}
				}else{
					words.push_back(" "+next+result);
				}
				troubleMakers.erase(next);
			}
		}
		int index = 0;
		int spaces;
		int lowest = 100000;
		for(int j = 0; j<words.size();j++){
			spaces = 0;
			string word = words.at(j);
			for(int i = 0; i<word.length();i++){
				if (word.at(i) == ' '){
					spaces++;
				}
			}
			if(lowest >= spaces && spaces > 0){
				lowest = spaces;
				index = j;
			}
		}
		if (words.size() > 0 && index >= 0){
			if((words.at(index)).length() >2) return words.at(index);
		}
		return "000";
	}else{
		return "DEP";
	}
}

void excecute(string first, string second){
	int firstLen = first.length();
	int secondLen = second.length();
	int countReset = GCOUNT;
	vector<string> joins;
	
	vector<string> tempSingle;
	vector<string> tempDouble;
	
	string singly = "";
	string doubly = "";
	
	for(int i=0;i<firstLen;i++){
		string sub1 = first.substr (i);
		if (sub1.length() <= secondLen){
			string sub2 = second.substr (0,sub1.length());
			if(sub1 == sub2){
				if((sub1.length() >= firstLen/2) && (sub2.length() < secondLen/2)){
					singly = "2 "+first+" "+second;
				}else if((sub1.length() < firstLen/2) && (sub2.length() >= secondLen/2)){
					singly = "2 "+first+" "+second;
				}else if((sub1.length() >= firstLen/2) && (sub2.length() >= secondLen/2)){
					doubly = "2 "+first+" "+second;
				}
			}
		}
	}
	
	//singly joined
	GCOUNT = countReset;
	usedWords.clear();
	troubleMakers.clear();
	if (singly.length() == 0){
		singly = joining(second,narrow(first,0),0,0);
		
		int count = 2;
		for(int i = 0; i<singly.length();i++){
			if(singly.at(i) == ' '){
				count++;
			}
		}
		string sub0 = singly.substr (singly.length()-3,singly.length());
		if (sub0 == "DEP"){ 
			singly = "";
			count = 0;
		}
		if (sub0 == "000") singly = singly.substr (0,singly.length()-3);
		if(count > 2){
			string tempc = to_string(count);
			singly = tempc + " " + first + singly + " " + second;
		}else{
			singly = "0";
		}
	}
	cout << singly << endl;
	cout << "time taken: " << ( clock() - start ) / (double) CLOCKS_PER_SEC << endl;
	
	//doubly joined
	GCOUNT = countReset;
	usedWords.clear();
	troubleMakers.clear();
	if (doubly.length() == 0){
		doubly = joining(second,narrow(first,1),1,0);
		int count = 2;
		for(int i = 0; i<doubly.length();i++){
			if (doubly.at(i) == ' '){
				count++;
			}
		}
		string sub1 = doubly.substr (doubly.length()-3,doubly.length());
		if (sub1 == "DEP"){
			doubly = "";
			count = 0;
		}
		if (sub1 == "000") doubly = doubly.substr (0,doubly.length()-3);
		if(count > 2){
			string tempc = to_string(count);
			doubly = tempc + " " + first + doubly + " " + second;
		}else{
			doubly = "0";
		}
	}
	cout <<doubly<<endl;
	cout << "time taken: " << ( clock() - start ) / (double) CLOCKS_PER_SEC << endl;
	
}
int main (int argc, char *argv[]){
	while (true){
		string mystr;
		
		string first = argv[1];
		string second = argv[2];
		GlobalDict.clear();
		
		int count =0;
		while (!cin.eof()){
			getline (cin,mystr);
			GlobalDict.push_back(mystr);
			count++;
		}
		if(count<GCOUNT)GCOUNT = count;
		start = clock();
		excecute(first,second);
		break;
	}
}