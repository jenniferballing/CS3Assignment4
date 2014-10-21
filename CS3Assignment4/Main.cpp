#include <iostream>
#include <fstream>
#include <cstdlib>
#include "HashTable.h"
#include "HashRecord.h"
#include <time.h>

using namespace std;
void inputPoem(int i, HashTable<string, HashRecord> *table);
void poem(string s, int i, HashTable<string, HashRecord> *table);
int main()
{
	HashTable <string, HashRecord> *table = new HashTable<string, HashRecord>();

	inputPoem(4, table);
	poem("mordecai", 50, table);


	return 0;
}

void poem(string s, int i, HashTable<string, HashRecord> *table)
{
	string current = s;
	int count = 1;
	cout << s << " ";

	vector <string> arr;
	while (count < i)
	{
		HashRecord* record = table->find(current);

		//get the number of values
		int size = record->getSuccessorList().size();
		
		//put values in array
		for (int i = 0; i < size; i++)
		{
			Successor first  = record->getSuccessorList()[i];
			for (int j = 0; j < first.occurances; j++)
			{
				arr.push_back(first.word);
			}
		}

		//Randomly assign value from array
		//srand(time(NULL));
		string nextWord = arr[rand() % size];
		cout << nextWord << " ";

		current = nextWord;
		arr.clear();
		count++;
	}
}

void inputPoem(int i, HashTable<string, HashRecord> *table)
{
	fstream fin;
	if (i == 1) fin.open("green.txt");
	if (i == 2) fin.open("poe.txt");
	if (i == 3) fin.open("inch.txt");
	if (i == 4) fin.open("Suess.txt");
	if (i == 5) fin.open("clown.txt");

	string currentWord, nextWord;	

	//Get very currentRecord word
	fin >> currentWord;
	for (unsigned int i = 0; i < currentWord.length(); i++)
	{
		if (currentWord[i] >255 || currentWord[i] < 0 || ispunct(currentWord[i]))	currentWord.erase(i, 1);
		else currentWord[i] = tolower(currentWord[i]);
	}	

	while (!fin.eof())
	{
		//Get successive words
		fin >> nextWord;

		//Remove uppercase letters and punctuation			
		for (unsigned int i = 0; i < nextWord.length(); i++)
		{
			if (nextWord[i] >64 && nextWord[i] < 91)nextWord[i] = tolower(nextWord[i]);
			else if (ispunct(nextWord[i]))nextWord.erase(i, 1);
		}

		//Create instance of HashRecord for table
		HashRecord* currentRecord = new HashRecord;

		currentRecord->setWord(currentWord);
		currentRecord->insertSuccessor(nextWord);

		table->insert(currentWord, currentRecord);

		//Set new currentWord
		currentWord = nextWord;
	}
	fin.close();
}