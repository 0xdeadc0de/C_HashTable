#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hashtable.h"

int main()
{
	// Dirty testing
	Table* table = AllocTable();
#define SZ 55
	const int sz = SZ;
	char value[SZ];
	const int test = sz;

	// Inserting all items should be no problem
	for (int i = 0; i < test; i++)
	{
		sprintf_s(value, sz, "%d", i);
		Insert(table, value, value);
	}

	// All items should exist
	for (int i = 0; i < test; i++)
	{
		sprintf_s(value, sz, "%d", i);
		if (NULL == Search(table, value))
		{
			printf("assertion failed. shouldn't reach here");
			gets_s(value, 4);
		}
	}

	// All items can be deleted without problem
	for (int i = 0; i < test; i++)
	{
		sprintf_s(value, sz, "%d", i);
		Delete(table, value);
	}

	// All items should not exist at this point
	for (int i = 0; i < test; i++)
	{
		sprintf_s(value, sz, "%d", i);
		if (NULL != Search(table, value))
		{
			printf("assertion failed. shouldn't reach here");
			gets_s(value, 4);
		}
	}

	FreeTable(table);
	return 0;
}