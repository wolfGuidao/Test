#include<iostream>
#include<Windows.h>
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
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr)
		{
			return head;
		}
		ListNode* cur = head;//�жϵ�ǰ�ڵ�
		ListNode* temp = cur;//ָ��ǰ�ڵ��ǰһ���ڵ�
		while (cur)
		{
			if (cur->val == val)
			{
				if (cur == head)//Ҫɾ��λ����ͷ
				{
					head = cur->next;
					cur = head;
					if (head == nullptr)//���ɾ��������Ϊ�գ���ֱ�ӷ���
					{
						return head;
					}
					else
					{
						continue;//continue��ֹ����һ���ڵ�
					}
				}
				else if (cur->next == nullptr)//���Ҫɾ����λ���ڽ�β
				{
					temp->next = nullptr;
					return head;
				}
				else//Ҫɾ���Ľڵ����м�
				{
					temp->next = cur->next;
					cur = temp->next;
					continue;//���û��continue���ͻ�����һ���ڵ�
				}
			}
			temp = cur;
			cur = cur->next;
		}
		return head;
	}
};

#endif

#if  0

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
	ListNode* reverseList(ListNode* head) {
		ListNode* prv = nullptr;//��¼ǰ��
		ListNode* cur = head;//��ǰ�ڵ�
		ListNode* temp;//��¼cur����һ���ڵ�
		while (cur)
		{
			temp = cur->next;
			cur->next = prv;//��ת
			prv = cur;//����
			cur = temp;//�жϽڵ����
		}
		head = prv;//��ͷ�ڵ����
		return head;
	}
};

#endif

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
	ListNode* middleNode(ListNode* head) {
		ListNode* cur = head;
		ListNode* temp;
		int count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		cur = head;
		int i = count / 2 + 1;
		while (i > 0)
		{
			temp = cur;
			cur = cur->next;
			i--;
		}
		return temp;
	}
};

#endif

#if 0

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int x = 0;
		int num1 = 0;
		int num2 = 0;
		for (auto i : nums)
			x ^= i;//���Ľ��һ��Ϊ����nums��ֻ����һ�ε������������������xһ����һλΪ1��x������Ϊ0

		int pos = 0;//������¼x����һλΪ1
		for (;pos < 32;pos++)
		{
			if (x & (1 << pos))//���1����posλ��x�룬˵����posλΪ1
			{
				break;//����ҵ���ֱ�ӷ���
			}
		}

		vector<int> ans;//�洢���
		for (auto i : nums) {//����ԭ���飬��Ϊ����ֻ����һ�ε�Ԫ���ڵ�posλһ���ǲ�һ���ģ�
			if (i & (1 << pos))//��Ϊ2��num1��num2��������ֻ����һ�ε�Ԫ��һ������ͬһ�飬���������Ͱ�ֻ����һ�ε�����Ԫ�طֿ��ˣ�
			{
				num1 ^= i;//���������Ԫ�صĵ�posλΪ1��
			}
			else
			{
				num2 ^= i;
			}
		}
		ans.push_back(num1);
		ans.push_back(num2);
		return ans;
	}
};

#endif

int main()
{
	system("pause");
	return 0;
}
