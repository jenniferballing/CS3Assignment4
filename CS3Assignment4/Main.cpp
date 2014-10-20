#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "HashRecord.h"

using namespace std;
void inputPoem(int i, HashTable<string, HashRecord> *table);
void poem(string s, int i, HashTable<string, HashRecord> *table);
int main()
{
	HashTable <string, HashRecord> *table = new HashTable<string, HashRecord>();

	inputPoem(1, table);
	poem("sam", 20, table);


	return 0;
}

void poem(string s, int i, HashTable<string, HashRecord> *table)
{
	string current = s;
	int count = 1, num = 0;;
	cout << s << " ";

	vector <string> arr;
	while (count < i)
	{
		HashRecord* record = table->find(current);

		//get the number of values
		vector <Successor> temp = record->getSuccessorList();
		int size = temp.size();
		
		//put values in array
		for (int i = 0; i < size; i++)
		{
			Successor first  = record->getSuccessorList()[i];
			for (int j = 0; j < first.occurances; j++)
			{
				arr.push_back(first.word);
				num++;
			}
		}
		count++;
	}
}

void inputPoem(int i, HashTable<string, HashRecord> *table)
{
	fstream fin;
	if (i == 1) fin.open("green.txt");

	string currentWord, nextWord;	

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

		table->insert(currentWord, currentRecord);

		//Set new currentWord
		currentWord = nextWord;
	}
	fin.close();
}