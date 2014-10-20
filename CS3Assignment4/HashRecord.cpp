#include "HashRecord.h"


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








HashRecord::~HashRecord()
{
}
