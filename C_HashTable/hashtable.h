#pragma once

typedef struct
{
	char* key;
	char* value;
}
Item;

typedef struct
{
	int size;
	int count;
	Item** items;
}
Table;

void Insert(Table* table, const char* key, const char* value);
void Delete(Table* table, const char* key);
char* Search(Table* table, const char* key);
Table* AllocTable();
void FreeTable(Table* table);