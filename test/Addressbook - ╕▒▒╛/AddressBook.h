#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

enum SEX
{
	Man,
	Woman,
};

typedef struct AddressInfo
{
	char _name[24];
	char _tel[24];
	int  _age;
	enum SEX  _sex;
}AddressInfo;

//#define MAX_SIZE  10000

typedef struct AddressBook
{
	AddressInfo* _AIArray;
	size_t _size;     // 有效数据个数
	size_t _capacity; // 容量
}AddressBook;

void AddressBookInit(AddressBook* pbook);
void AddressBookDestroy(AddressBook* pbook);

void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo);
void AddressBookDel(AddressBook* pbook, const char* name);
AddressInfo* AddressBookFind(AddressBook* pbook, const char* name);

void AddressBookSave(AddressBook* pbook, const char* filename);
void AddressBookLoad(AddressBook* pbook, const char* filename);
void AddressBookPrint(AddressBook* pbook);







