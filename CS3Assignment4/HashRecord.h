#ifndef HASHHashRecord_H
#define HASHHashRecord_H

#include<iostream>
#include "HashTable.h"

using namespace std;
struct Successor
{
	string word;
	int occurances;

	Successor(string w)
	{ 
		word = w; 
		occurances = 0;
	}
};
class HashRecord
{
	string word;
	vector <Successor> successorList;
	///int occuranceCount;

public:
	//Constructors
	HashRecord();
	HashRecord(string w);

	//Getters
	string getWord(){ return word; }
	vector<Successor> getSuccessorList(){ return successorList; }
	//int getOccuranceCount(){ return occuranceCount; }

	//Setters
	void setWord(string w){ word = w; }
	void setSuccessorList(vector<Successor> l){ successorList = l; }
	//void setOccuranceCount(int c){ occuranceCount = c; }

	void insertSuccessor(Successor s);

	~HashRecord();
};
#endif
