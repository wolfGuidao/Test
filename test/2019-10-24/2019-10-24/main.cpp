#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
//
//int my_strlen1(const char* str)//ģ��ʵ��strken():����
//{
//	assert(str);
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int my_strlen2(const char*str)//�ݹ�
//{
//	assert(str);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return 1 + my_strlen2(str + 1);
//}
//
//int my_strlen3(const char* str)//�������ڴ�����ָ�����������֮��Ԫ�ظ���
//{
//	assert(str);
//	const char*str1 = str;
//	while (*str)
//	{
//		str++;
//	}
//	return str - str1;
//}
//
//char* my_strcpy(char* dest, const char* str)//ģ��strcpy����
//{
//	assert(dest&&str);
//	char* dest1 = dest;
//	while (*str)
//	{
//		*dest = *str;
//		dest++;
//		str++;
//	}
//	*dest = '\0';//ע���β��'\0'
//	return dest1;
//}
//
//char* my_strcat(char* dest, const char* str)//ģ��strcat()
//{
//	assert(dest&&str);
//	char* dest1 = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	do
//	{
//		*dest = *str;
//		dest++;
//		str++;
//	} while (*str);
//	*dest = '\0';
//	return dest1;
//}
//
//int my_strcmp(const char* dest, const char* str)//ģ��strcmp()
//{
//	assert(dest&&str);
//	while (*dest != '\0'&&*str != '\0')
//	{
//		if (*dest == *str)
//		{
//			str++;
//			dest++;
//		}
//	}
//	if (*str == *dest&&*str == '\0')
//	{
//		return 0;
//	}
//	else if (*dest > *str)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//char* my_strstr(const char*dest, const char* str)//
//{
//	assert(dest&&str);
//	char* start;
//	const char* str1 = str;//�����ƥ�䴮�׵�ַ
//	while (*dest)
//	{
//		start = (char*)dest;//��¼ÿ��ƥ��λ��
//		while (*dest == *str&&*str != '\0')
//		{
//			dest++;
//			str++;
//		}
//		if (*str == '\0')//���str=='\0'˵�������ƥ��
//		{
//			return start;
//		}//���ﲻ��ֱ��break����Ϊ������ܻ����
//		else//������ƥ�䣬��¼�����ص�һ���ַ���λ�ã��ô�û�����ƥ�䣬��¼��λ�ã���һ���ظ�λ�ú�һ�����бȽ�
//		{
//			dest = start + 1;
//			str = str1;
//		}
//	}
//	return NULL;
//}
//
//void* my_memmove(void* dest, const void* str, size_t count)//ע������ͷ���ֵ������
//{
//	assert(dest&&str);
//	char* dest1 = (char*)dest;
//	char* str1 = (char*)str;
//	if (str1 < dest1 || dest1 < str1 + count)//�ڴ渲���ں��棻�Ӻ���ǰ��ֵ
//	{
//		dest1 += (count - 1);
//		str1 += (count - 1);
//		while (count--)
//		{
//			*dest1 = *str1;
//			dest1 = dest1 - 1;
//			str1 = str1 - 1;
//		}
//	}
//	else//û���ڴ���ڴ渲����ǰ�棻��ǰ����ֵ
//	{
//		while (count--)
//		{
//			*dest1 = *str1;
//			dest1 = dest1 - 1;
//			str1 = str1 - 1;
//		}
//	}
//	return dest1;
//}
//
//char* my_strchr(const char *str, char c)
//{
//	assert(str);
//	char* str1 = (char*)str;
//	while (*str1++)
//	{
//		if (*str1 == c)
//		{
//			return str1;
//		}
//	}
//	return NULL;
//}
//
//
//int main()
//{
//	//���������в�Ҫȫ���ſ������ܻᷢ����ͻ
//	char str[] = "wolf guidao";
//	/*cout << strlen(str) << endl;
//	cout << my_strlen1(str) << endl;
//	cout << my_strlen2(str) << endl;
//	cout << my_strlen3(str) << endl;*/
//
//	char str1[40];
//	//cout << strcpy(str1, str) << endl;
//	//cout << my_strcpy(str1, str) << endl;
//
//	//cout << my_strcat(my_strcpy(str1, str), str) << endl;
//
//	//cout << strcmp(str, my_strcpy(str1, str)) << endl;
//	//cout << my_strcmp(str, my_strcpy(str1, str)) << endl;
//	//cout << my_strcmp(str, strcpy(str1, "wolf guidaoo")) << endl;
//	//cout << my_strcmp(str, my_strcpy(str1, "wolf guidaoo")) << endl;
//
//	//cout << my_strstr(str, my_strcpy(str1, str)) << endl;
//	//cout << strstr(str, my_strcpy(str1, str)) << endl;
//	//cout << my_strstr(str, my_strcpy(str1, "guidao")) << endl;
//	//cout << strstr(str, my_strcpy(str1, "guidao")) << endl;
//
//	//my_memmove(str1, str, 12);
//	//memmove(str1, str, 12);
//	//cout << str1 << endl;
//	//my_memmove(str+11, " aini", 6);
//	//memmove(str + 11, " aini", 6);
//	//cout << str << endl;
//	//memmove(str + 10, str, 12);
//	//my_memmove(str + 10, str, 12);
//	//cout << str << endl;
//
//	//cout << my_strchr(str, 'o') << endl;
//	//cout << strchr(str, 's') << endl;
//
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	/*Date()
//	{
//		count++;
//	}*/
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		//,count(10)//�ᱨ��
//	{
//		count+=1;
//	}
//	void Show()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//	static void GetCount()
//	{
//		cout << count << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	static int count;//���ڲ�����������
//	friend void Get_month();
//};
//int Date::count = 0;//������ж����ʼ��
//
//void Get_month()
//{
//	Date c(1019, 10, 2);
//	cout << c._month << endl;
//}
//
//void txt()
//{
//	Date a1(1111,11,1);
//	a1.GetCount();
//	Date d2(1111, 11, 1);
//	Date d3(1111, 11, 1);
//	Date d4(1111, 11, 1);
//	d4.GetCount();
//}
//int main()
//{
//	Date a(1111, 11, 1);
//	a.GetCount();
//	//a.Show();
//	Date b(2019, 10, 19);
//	//b.Show();
//	//cout << a.GetCount() << endl;//����ͨ����������������ʾ�̬��Ա����
//	//cout << Date::GetCount() << endl;
//	//Get_month();
//	//txt();
//	b.GetCount();
//	Date f(1111, 11, 1);
//	Date ff(1111, 11, 1);
//	a.GetCount();
//	system("pause");
//	return 0;
//}
