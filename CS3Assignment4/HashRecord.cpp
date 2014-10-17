#include "HashRecord.h"


HashRecord::HashRecord()
{
	word = " ";
	occuranceCount = 0;
}
HashRecord::HashRecord(string w)
{
	word = w;
	occuranceCount = 0;
	successorList = vector<Successor>();
}








HashRecord::~HashRecord()
{
}
