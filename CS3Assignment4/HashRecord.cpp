#include "HashRecord.h"
#include <sstream>


HashRecord::HashRecord()
{
	word = " ";
	//occuranceCount = 0;
}
HashRecord::HashRecord(string w)
{
	word = w;
	//occuranceCount = 0;
	successorList = vector<Successor>();
}
void HashRecord::insertSuccessor(Successor s)
{
	vector<Successor> tempVec = this->getSuccessorList();
	
	//Check for successor in vector
	bool found = false;
	for (int i = 0; i < tempVec.size(); i++)
	{
		Successor temp = tempVec[i];
		
		//If the word is already in the vec
		if (temp.word == s.word)
		{
			tempVec[i].occurances++;
			found = true;
		}
	}
	
	//If the word was not found in the vec
	if (!found)
	{
		s.occurances = 1;
		tempVec.push_back(s);
	}
	this->setSuccessorList(tempVec);
}
string HashRecord::toString()
{
	return "Key: " + this->getWord() + "\n";
	//cout << "Key: " << this->getWord() << endl;
	/*for (unsigned int i = 0; i < this->getSuccessorList().size(); i++)
	{
		string s = this->getSuccessorList()[i].word;
		int j = this->getSuccessorList()[i].occurances;

		stringstream ss;
		ss << j;
		string newJ;
		ss >> newJ;
		
	}*/
}








HashRecord::~HashRecord()
{
}
