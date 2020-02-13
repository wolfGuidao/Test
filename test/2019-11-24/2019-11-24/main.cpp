#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

#if 0

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
		int ret1 = 0;
		int ret2 = 0;
		int ret = 0;
		for (size_t i = 0; i < data.size(); i++)
		{
			ret ^= data[i];//ret�洢������ֻ����һ�ε������
		}
		int pos = 0;//��ret��Ϊ1��λ��pos��������
		for (int i = 0; i < 31; i++)
		{
			if ((ret & (1 << i)))
			{
				pos = i;
				break;
			}
		}


		for (size_t i = 0; i < data.size(); i++)
		{
			if ((data[i] & (1 << pos)) == 0)//����data����data��Ԫ����posλΪ1�ĺ���posλΪ
				//0�ķ�Ϊ2�飬��Ϊ���ĳ��Ԫ�س��������Σ���ô��Ԫ����posλ��ҪôΪ0��Ҫô
				//Ϊ1�������϶���ͬһ�飬���ĳ��Ԫ��ֻ������һ�Σ�������һ��ֻ����һ�ε�Ԫ��
				//�϶��ڲ�ͬ�飬�����Ͱ�����ת��Ϊ��һ����������һ��ֻ����һ�ε�Ԫ����
			{
				ret1 ^= data[i];
			}
			else
			{
				ret2 ^= data[i];
			}
		}
		*num1 = ret1;
		*num2 = ret2;
	}
};

void test()
{
	vector<int>l = { 4,6,2,2,3,3,8,8,9,9,1000000,1000000 };
	Solution s;
	int a;
	int b;
	
	s.FindNumsAppearOnce(l,&a,&b);
	//cout << *num1 << " " << *num2  ;
	cout << a <<"  "<< b << endl;
	//cout << ret1 << endl;
	//cout << ret2 << endl;
}

#endif

#if 0

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int count = 1;
		if (numbers.size() == 1)
		{
			return numbers[0];
		}
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i - 1] == numbers[i])
			{
				count++;
			}
			else
			{
				if (count > (numbers.size() / 2))
				{
					return numbers[i - 1];
				}
				else
				{
					count = 1;

				}
			}
		}
		return 0;
	}
};

#endif

#include<string>

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		/*
		char str1[100]={0};
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			{
				str1[str[i]-'a'+1]++;
			}
			else
			{
				str1[str[i]-'A'+27]++;
			}

		}
		for(int i=1;i<100;i++)
		{
			if(str1[i]==1)
			{
				if(i<=26)
				{
					return str.find((i-1)+'a');
				}
				else if(i<=52)
				{
					return str.find(i-27+'A');
				}
			}
		}
		return -1;
		*/
		int i = 0;
		for ( ;i < str.size();i++)
		{
			int j = 0;
			while (j < str.size())
			{
				if (str[i] != str[j]&& i != j)
				{
					j++;
				}
				else if (str[i] == str[j] && i == j)
				{
					j++;
				}
				else
				{
					
					break;
				}
			}
			if (j == str.size())
			{
				return i;
			}
		}
		return -1;
	}
};

#if 0

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];//�洢���Ľ��
		int tempsum = array[0];//��ʱ�洢���������еĺ�
		for (int i = 1; i < array.size(); i++)
		{
			if (tempsum >= 0)//���tempsum����0��˵�������Լ�������һ��Ԫ�أ�
			{
				tempsum += array[i];
				sum = sum > tempsum ? sum : tempsum;//ÿ��ȡ������������еĺ�

			}
			else
			{
				tempsum = array[i];//���tempsum���С��0��˵��tempsum�ڼ���ĳ��Ԫ�غ�
				//��Ϊ��������ʱ�Ͳ����ټ��ˣ��ð�tempsum��Ϊ��ǰԪ�أ����¿�ʼ����
				//tempsum��ע��Ԫ�ر������Ϊ����������ÿ�ζ�Ҫ�Ƚ�
				sum = sum > tempsum ? sum : tempsum;//ÿ�ζ�Ҫ����������������еĺͣ���Ϊ���ܳ���
				//����������Ԫ�ض��Ǹ���

			}
		}
		return sum;
	}
};

#endif

void test()
{
	Solution s;
	string s1 = "google";
	s.FirstNotRepeatingChar(s1);
}

int main()
{
	test();
	system("pause");
	return 0;
}