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
	//Print poem and hash table for green.txt
	inputPoem(1, table);
	cout << "green.txt poem: " << endl;
	poem("sam", 20, table);
	cout << endl << "HashTable after green.txt: " << table->toString() << endl;
	cout << endl << endl;
	
	HashTable <string, HashRecord> *table1 = new HashTable<string, HashRecord>();
	//Print poem and hash table for clown.txt
	inputPoem(2, table1);
	cout << "clown.txt poem: " << endl;
	poem("go", 20, table1);
	cout << endl << "HashTable after clown.txt: " << table1->toString() << endl;
	cout << endl << endl;

	HashTable <string, HashRecord> *table2 = new HashTable<string, HashRecord>();
	//Print poem for inch.txt
	inputPoem(3, table2);
	cout << "inch.txt poem: " << endl;
	poem("computer", 50, table2);
	cout << endl << endl;

	HashTable <string, HashRecord> *table3 = new HashTable<string, HashRecord>();
	//Print poem for poe.txt
	inputPoem(4, table3);
	cout << "Poe.txt poem: " << endl;
	poem("nevermore", 50, table3);
	cout << endl << endl;

	HashTable <string, HashRecord> *table4 = new HashTable<string, HashRecord>();
	//Print poem for Suess.txt
	inputPoem(5, table4);
	cout << "Suess.txt poem: " << endl;
	poem("mordecai", 50, table4);


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
		for (int j = 0; j < size; j++)
		{
			Successor first  = record->getSuccessorList()[j];
			for (int k = 0; k < first.occurances; k++)
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

void inputPoem(int num, HashTable<string, HashRecord> *table)
{
	fstream fin;
	if (num == 1) fin.open("green.txt");
	if (num == 4) fin.open("poe.txt");
	if (num == 3) fin.open("inch.txt");
	if (num == 5) fin.open("Suess.txt");
	if (num == 2) fin.open("clown.txt");

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
		for (int i = 0; i < nextWord.length();)
		{
			if (nextWord[i] >255 || nextWord[i] < 0 || ispunct(nextWord[i]))
				nextWord.erase(i, 1);
			else{
				nextWord[i] = tolower(nextWord[i]);
				i++;
			}
		}

		//Create instance of HashRecord for table
		HashRecord* currentRecord = new HashRecord;

		currentRecord->setWord(currentWord);
		currentRecord->insertSuccessor(nextWord);

		if (currentWord == "i")
		{
			cout << "";
		}
		table->insert(currentWord, currentRecord);

		//Set new currentWord
		currentWord = nextWord;
	}
	fin.close();
}