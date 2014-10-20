#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "HashRecord.h"

using namespace std;

int main()
{
	fstream fin;
	string currentWord, nextWord;
	fin.open("green.txt");

	HashTable <string, HashRecord> table;
	
	
	//Get very currentRecord word
	fin >> currentWord;

	while (!fin.eof())
	{
		//Get successive words
		fin >> nextWord;
		
		//Remove uppercase letters and punctuation
		for (unsigned int i = 0; i < currentWord.length(); i++)
		{
			if (currentWord[i] >255 || currentWord[i] < 0 || ispunct(currentWord[i]))	currentWord.erase(i, 1);
			else currentWord[i] = tolower(currentWord[i]);
		}
		for (unsigned int i = 0; i < nextWord.length(); i++)
		{
			if (nextWord[i] >255 || nextWord[i] < 0 || ispunct(nextWord[i]))	nextWord.erase(i, 1);
			else nextWord[i] = tolower(nextWord[i]);
		}

		//Create instance of HashRecord for table
 		HashRecord* currentRecord = new HashRecord;
		
		currentRecord->setWord(currentWord);
		currentRecord->insertSuccessor(nextWord);

		table.insert(currentWord, currentRecord);
		
		//Set new currentWord
		currentWord = nextWord;
	}
	fin.close();
	
	return 0;
}