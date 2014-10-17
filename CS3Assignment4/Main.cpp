#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "HashRecord.h"

using namespace std;

int main()
{
	fstream fin;
	string firstWord, secondWord;
	fin.open("green.txt");

	fin >> firstWord;
	fin >> secondWord;
	for (int i = 0; i < firstWord.length(); i++)
	{
		if (firstWord[i] >255 || firstWord[i] < 0 || ispunct(firstWord[i]))	firstWord.erase(i, 1);
		else firstWord[i] = tolower(firstWord[i]);
	}
	for (int i = 0; i < secondWord.length(); i++)
	{
		if (secondWord[i] >255 || secondWord[i] < 0 || ispunct(secondWord[i]))	secondWord.erase(i, 1);
		else secondWord[i] = tolower(secondWord[i]);
	}

	HashRecord* first = new HashRecord;
	first->setWord(firstWord);
	//first->insertSuccessor(secondWord);

	HashTable <string, HashRecord> table;
	//table.insert(firstWord, first);	
	
	return 0;
}