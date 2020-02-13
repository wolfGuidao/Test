#include<iostream>
using namespace std;

#if 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
		{
			return true;
		}
		if (head->next == nullptr)
		{
			return true;
		}
		ListNode* slower = head;
		ListNode* faster = head->next;
		stack<int>s;
		int count = 0;
		while (faster&&faster->next)
		{
			slower = slower->next;
			faster = faster->next->next;
		}
		ListNode* cur = head;
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		cur = head;

		if (count % 2 == 0)
		{
			slower = slower->next;

			while (slower != cur)
			{
				s.push(cur->val);
				cur = cur->next;
			}
		}
		else
		{
			while (slower != cur)
			{
				s.push(cur->val);
				cur = cur->next;
			}
			slower = slower->next;
		}

		while (!s.empty())
		{
			if (s.top() == slower->val)
			{
				s.pop();
				slower = slower->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

#endif

void reverse(char* str)//�ݹ鷴ת�ַ���
{
	int len = strlen(str);//ÿ�εݹ������Ҫ��һ��len
	char* str_end =str + len - 1;//str_len������len�ļ��ٶ�������ǰ�ƶ�
	char temp = 0;//��ʱ������

	if (len < 2)//�ݹ���ڣ����lenС��2��˵���Ѿ��Ѻ�벿�ֵݹ���ϣ��Ͳ����ٵݹ���ȥ��
	{
		return;
	}
	else
	{
		temp = *str;//���Ȱѵ�һ��Ԫ�ر�������
		*str = *str_end;//�����һ��Ԫ�ط��ڵ�һ��Ԫ�ص�λ�ã�������һ���ַ����ķ�ת
		*str_end = '\0';//�����һλ��Ϊ\0����str�ĳ��Ȳ������̣�ʹ��str_end������ǰ�ƶ�
		reverse(++str);//�ݹ�Ѻ����Ԫ�ض��ŵ�ǰ�棬��ǰ���Ԫ������ʱ��������������ֱ��srt�ĳ���С��2��ֹ�ݹ�
		*str_end = temp;//��ɺ�벿�ֵ����ú��ڷֱ��temp�е�Ԫ�ط���str_end��λ��
	}
}

int main()
{
	char str[20];
	cin >> str ;
	reverse(str);
	cout << str << endl;
	system("pause");
	return 0;
}