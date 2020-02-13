#include "AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;
	AddressBookInit(&addressbook);
	/*AddressInfo info1 = {"高博", "18213141414", 18, Man};
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "小王", "18213141415", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "小李", "18213141416", 19, Man };
	AddressBookAdd(&addressbook, &info3);
	AddressBookSave(&addressbook, "addressfile.txt");
	AddressBookPrint(&addressbook);*/

	AddressBookLoad(&addressbook, "addressfile.txt");
	AddressBookPrint(&addressbook);

	//AddressInfo* ret = AddressBookFind(&addressbook, "小王");
	//printf("%s\n", ret->_name);
	//AddressBookDel(&addressbook, "小王");
	//AddressBookPrint(&addressbook);

	//AddressBookSave(&addressbook, "addressfile.bin");
	AddressBookDestroy(&addressbook);
}

int main()
{
	TestAddressBook();

	return 0;
}

//int main()
//{
//	AddressBook addressbook;
//	AddressBookInit(&addressbook);
//	AddressBookLoad(&addressbook, "addressfile.bin");
//	int option = 0;
//	do{
//		printf("=========================================\n");
//		printf("1.添加通讯录信息 2.查找通讯录信息\n");
//		printf("3.删除通讯录信息 4.修改通讯录信息\n");
//		printf("5.保存通讯录到文件 6.读取文件通讯录信息\n");
//		printf("7.打印通讯录信息 -1.退出.\n");
//		scanf("%d", &option);
//		if (option == 1)
//		{
//			printf("请依次输入姓名、电话、年龄、性别:\n");
//			AddressInfo info;
//			scanf("%s", info._name);
//			scanf("%s", info._tel);
//			scanf("%d", &info._age);
//			char sex[10];
//			scanf("%s", sex);
//			if (strcmp(sex, "男") == 0)
//				info._sex = 0;
//			else
//				info._sex = 1;
//			AddressBookAdd(&addressbook, &info);
//		}
//		else if (option == 2)
//		{
//			char name[20];
//			printf("请输入要查找联系人的姓名\n");
//			scanf("%s", name);
//			AddressInfo* ret = AddressBookFind(&addressbook, name);
//			if (ret == NULL)
//			{
//				printf("查无此人\n");
//			}
//			else
//			{
//				printf("姓名:%s\n", ret->_name);
//				printf("电话:%s\n", ret->_tel);
//				printf("年龄:%d\n", ret->_age);
//				printf("性别:%d\n", ret->_sex);
//			}
//		}
//		else if (option == 4)
//		{
//			char name[20];
//			printf("请输入要修改联系人的姓名\n");
//			scanf("%s", name);
//			AddressInfo* ret = AddressBookFind(&addressbook, name);
//			if (ret == NULL)
//			{
//				printf("查无此人\n");
//			}
//			else
//			{
//				printf("请输入要修改联系人的电话\n");
//				scanf("%s", ret->_tel);
//			}
//		}
//		else if (option == 5)
//		{
//			AddressBookSave(&addressbook, "addressfile.bin");
//		}
//		else if (option == 6)
//		{
//			addressbook._size = 0;
//			AddressBookLoad(&addressbook, "addressfile.bin");
//		}
//		else if (option == 7)
//		{
//			AddressBookPrint(&addressbook);
//		}
//		printf("=========================================\n");
//	} while (option >= 0);
//
//
//	return 0;
//}