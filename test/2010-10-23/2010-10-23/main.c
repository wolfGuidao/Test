#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

#if 0

void Left(char* str, int len, int k)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0;i < k;i++)
	{
		temp = str[0];
		for (j = 0;j < len;j++)
		{
			str[j] = str[j + 1];
		}
		str[len - 1] = temp;
	}
}

int main()
{
	char str[20] = "ABCDEF";
	int len = strlen(str);
	int k = 2;
	Left(str, len, k);
	for (int i = 0;i < len;i++)
	{
		printf("%c", str[i]);
	}
	system("pause");
	return 0;
}

#endif

#if 0
//
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
int CheckLeft(char* str1, char*str2, int len)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int tag = 0;
	for (i = 0;i < len;i++)
	{
		temp = str1[0];
		for (j = 0;j < len;j++)
		{
			str1[j] = str1[j + 1];
		}
		str1[len - 1] = temp;
		
		if (!strcmp(str1, str2))
		{
			tag+=1;
		}
		
	}
	return tag;
}

int main()
{
	char str1[] = "AABCD";
	char str2[] = "AABCD";
	int len = strlen(str1);
	if (CheckLeft(str1, str2, len))
	{
		printf("%d", 1);
	}
	else
	{
		printf("%d", 0);
	}
	system("pause");
	return 0;
}

#endif
//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�

//3.ģ��ʵ��strcpy
//4.ģ��ʵ��strcat

#if 0

int main()
{
	int str[]={ 1,1,2,3,3,2,4,5,5,6,6,7 };
	int len = sizeof(str) / sizeof(str[0]);
	int temp[2];
	int i = 0;
	int j = 0;
	int tag = 0;
	int k = 0;
	for (i = 0;i < len;i++)
	{
		tag = 0;
		for (j = 0;j < len;j++)
		{
			if (str[i] == str[j])
			{
				tag++;
			}
		}
		if (tag == 1)
		{
			temp[k++] = str[i];
		}
	}
	printf("%d  %d", temp[0], temp[1]);
	system("pause");
	return 0;
}
#endif

#if 0

//
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
//
int main()
{
	int money = 20;
	int woter = money;//��ˮƿ��
	int pinpin = woter;//��ʼ��ƿ��
	int num = 0;//��¼ʣ���ƿ��
	int lastpinpin = pinpin;//�ܿ�ƿ��
	while (pinpin)
	{
		pinpin = lastpinpin / 2;//2����ƿ��һƿ��ˮ������������ˮ���͵õ����ٿ�ƿ
		num = lastpinpin % 2;//��¼�ϴλ�����ˮ��û��ʣ��
		 lastpinpin=pinpin+ num;//�ܿ�ƿ��==�õ�����ˮ��+ʣ���ƿ��
		 woter += pinpin;//ÿ�θ���ˮ����
	}
	printf("%d", woter);
	system("pause");
	return 0;
}
#endif
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

int my_strlen1(const char* str)//ģ��ʵ��strken():����
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(const char*str)//�ݹ�
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen2(str + 1);
}

int my_strlen3(const char* str)//�������ڴ�����ָ�����������֮��Ԫ�ظ���
{
	assert(str);
	const char*str1 = str;
	while (*str)
	{
		str++;
	}
	return str - str1;
}

char* my_strcpy(char* dest, const char* str)//ģ��strcpy����
{
	assert(dest&&str);
	char* dest1 = dest;
	while (*str)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';//ע���β��'\0'
	return dest1;
}

char* my_strcat(char* dest, const char* str)//ģ��strcat()
{
	assert(dest&&str);
	char* dest1 = dest;
	while (*dest)
	{
		dest++;
	}
	do
	{
		*dest = *str;
		dest++;
		str++;
	} while (*str);
	*dest = '\0';
	return dest1;
}

int my_strcmp(const char* dest, const char* str)//ģ��strcmp()
{
	assert(dest&&str);
	while (*dest != '\0'&&*str != '\0')
	{
		if (*dest == *str)
		{
			str++;
			dest++;
		}
	}
	if (*str == *dest&&*str == '\0')
	{
		return 0;
	}
	else if (*dest > *str)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char* my_strstr(const char*dest, const char* str)//
{
	assert(dest&&str);
	char* start;
	const char* str1 = str;//�����ƥ�䴮�׵�ַ
	while (*dest)
	{
		start = (char*)dest;//��¼ÿ��ƥ��λ��
		while (*dest == *str&&*str != '\0')
		{
			dest++;
			str++;
		}
		if (*str == '\0')//���str=='\0'˵�������ƥ��
		{
			return start;
		}//���ﲻ��ֱ��break����Ϊ������ܻ����
		else//������ƥ�䣬��¼�����ص�һ���ַ���λ�ã��ô�û�����ƥ�䣬��¼��λ�ã���һ���ظ�λ�ú�һ�����бȽ�
		{
			dest = start + 1;
			str = str1;
		}
	}
	return NULL;
}

void* my_memmove(void* dest, const void* str, size_t count)//ע������ͷ���ֵ������
{
	assert(dest&&str);
	char* dest1 = (char*)dest;
	char* str1 = (char*)str;
	if (str1 < dest1 || dest1 < str1 + count)//�ڴ渲���ں��棻�Ӻ���ǰ��ֵ
	{
		dest1 += (count - 1);
		str1 += (count - 1);
		while (count--)
		{
			*dest1 = *str1;
			dest1 = dest1 - 1;
			str1 = str1 - 1;
		}
	}
	else//û���ڴ���ڴ渲����ǰ�棻��ǰ����ֵ
	{
		while (count--)
		{
			*dest1 = *str1;
			dest1 = dest1 - 1;
			str1 = str1 - 1;
		}
	}
	return dest1;
}

int main()
{
	//���������в�Ҫȫ���ſ������ܻᷢ����ͻ
	char str[] = "wolf guidao";
	/*cout << strlen(str) << endl;
	cout << my_strlen1(str) << endl;
	cout << my_strlen2(str) << endl;
	cout << my_strlen3(str) << endl;*/

	char str1[40];
	//cout << strcpy(str1, str) << endl;
	//cout << my_strcpy(str1, str) << endl;

	//cout << my_strcat(my_strcpy(str1, str), str) << endl;

	//cout << strcmp(str, my_strcpy(str1, str)) << endl;
	//cout << my_strcmp(str, my_strcpy(str1, str)) << endl;
	//cout << my_strcmp(str, strcpy(str1, "wolf guidaoo")) << endl;
	//cout << my_strcmp(str, my_strcpy(str1, "wolf guidaoo")) << endl;

	//cout << my_strstr(str, my_strcpy(str1, str)) << endl;
	//cout << strstr(str, my_strcpy(str1, str)) << endl;
	//cout << my_strstr(str, my_strcpy(str1, "guidao")) << endl;
	//cout << strstr(str, my_strcpy(str1, "guidao")) << endl;

	//my_memmove(str1, str, 12);
	//memmove(str1, str, 12);
	//cout << str1 << endl;
	//my_memmove(str+11, " aini", 6);
	//memmove(str + 11, " aini", 6);
	//cout << str << endl;
	//memmove(str + 10, str, 12);
	my_memmove(str + 10, str, 12);
	cout << str << endl;

	system("pause");
	return 0;
}
