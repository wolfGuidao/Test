#include<iostream>
#include<vector>
#include<list>
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
	ListNode *detectCycle(ListNode *head) {

		if (head == nullptr || head->next == nullptr)
		{
			return nullptr;
		}

		ListNode* slower = head;
		ListNode* faster = head->next;

		while (faster != slower)
		{
			if (faster == nullptr || faster->next == nullptr)
			{
				return nullptr;
			}
			slower = slower->next;
			faster = faster->next->next;
		}
		//�������ж�������û�л���������ߵ�����˵������϶����л���

		faster = faster->next;//����������ָ��ָ��ͷ�ڵ㣬��ָ��ָ�������ڵ����һ���ڵ㣬����ָ��һ�ζ���һ����������ָ���ٴ�����ʱָ��Ľڵ�����뻷�ڵ㣬��ͼ��ͼ��ͼ
		slower = head;
		while (slower != faster)
		{
			slower = slower->next;
			faster = faster->next;
		}
		return slower;
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr)
		{
			return nullptr;
		}
		/*
		ListNode* headA=new ListNode(0);
		ListNode* headB=new ListNode(0);
		headA->next=head;
		headB->next=head;
		//ListNode* heada=head;
		//ListNode* headb=headB;
		ListNode* cur=head;
		int count=1;
		while(cur->next)
		{
			count++;
			cur=cur->next;
		}
		cur->next=headB->next;
		cur=headA;
		int m=count-k%count;
		while(m)
		{
			cur=cur->next;
			m--;
		}
		ListNode* temp=cur;
		while(count)
		{
			cur=cur->next;
			count--;
		}
		cur->next=nullptr;
		return temp;
		*/
		ListNode* cur = head;
		int count = 1;
		while (cur->next)
		{
			count++;
			cur = cur->next;
		}
		cur->next = head;
		cur = head;
		int m = count - k % count;
		ListNode* temp;
		while (m)
		{
			cur = cur->next;
			m--;
		}
		temp = cur;
		while (count - 1)
		{
			cur = cur->next;
			count--;
		}
		cur->next = nullptr;
		return temp;
	}
};

#endif

int main()
{
	vector<int> s1{ 1,2,3,4,5 };
	list<int>s2{ 1,2,3,4,5 };
	auto it1 = s1.end();
	auto it2 = s2.end();
	//s1.erase(it1-1);
	cout << *(--it1) << endl;
	cout<< *(--it2) << endl;
	system("pause");
	return 0;
}
