#include "AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;
	AddressBookInit(&addressbook);
	/*AddressInfo info1 = {"�߲�", "18213141414", 18, Man};
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "С��", "18213141415", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "С��", "18213141416", 19, Man };
	AddressBookAdd(&addressbook, &info3);
	AddressBookSave(&addressbook, "addressfile.txt");
	AddressBookPrint(&addressbook);*/

	AddressBookLoad(&addressbook, "addressfile.txt");
	AddressBookPrint(&addressbook);

	//AddressInfo* ret = AddressBookFind(&addressbook, "С��");
	//printf("%s\n", ret->_name);
	//AddressBookDel(&addressbook, "С��");
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
//		printf("1.���ͨѶ¼��Ϣ 2.����ͨѶ¼��Ϣ\n");
//		printf("3.ɾ��ͨѶ¼��Ϣ 4.�޸�ͨѶ¼��Ϣ\n");
//		printf("5.����ͨѶ¼���ļ� 6.��ȡ�ļ�ͨѶ¼��Ϣ\n");
//		printf("7.��ӡͨѶ¼��Ϣ -1.�˳�.\n");
//		scanf("%d", &option);
//		if (option == 1)
//		{
//			printf("�����������������绰�����䡢�Ա�:\n");
//			AddressInfo info;
//			scanf("%s", info._name);
//			scanf("%s", info._tel);
//			scanf("%d", &info._age);
//			char sex[10];
//			scanf("%s", sex);
//			if (strcmp(sex, "��") == 0)
//				info._sex = 0;
//			else
//				info._sex = 1;
//			AddressBookAdd(&addressbook, &info);
//		}
//		else if (option == 2)
//		{
//			char name[20];
//			printf("������Ҫ������ϵ�˵�����\n");
//			scanf("%s", name);
//			AddressInfo* ret = AddressBookFind(&addressbook, name);
//			if (ret == NULL)
//			{
//				printf("���޴���\n");
//			}
//			else
//			{
//				printf("����:%s\n", ret->_name);
//				printf("�绰:%s\n", ret->_tel);
//				printf("����:%d\n", ret->_age);
//				printf("�Ա�:%d\n", ret->_sex);
//			}
//		}
//		else if (option == 4)
//		{
//			char name[20];
//			printf("������Ҫ�޸���ϵ�˵�����\n");
//			scanf("%s", name);
//			AddressInfo* ret = AddressBookFind(&addressbook, name);
//			if (ret == NULL)
//			{
//				printf("���޴���\n");
//			}
//			else
//			{
//				printf("������Ҫ�޸���ϵ�˵ĵ绰\n");
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