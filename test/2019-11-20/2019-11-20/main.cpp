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
	void deleteNode(ListNode* node) {
		ListNode* cur = node;
		ListNode* temp = node->next;

		int a = temp->val;
		temp->val = node->val;
		node->val = a;
		node->next = temp->next;

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
	ListNode* deleteDuplicates(ListNode* head) {
		/*
		if(head==nullptr)
		{
			return nullptr;
		}
		if(head->next==nullptr)
		{
			return head;
		}
		//
		ListNode* cur=head;
		ListNode* temp=head->next;
		ListNode* list=new ListNode(0);
		ListNode* listtail=list;
		//��Ҫ˼���Ǵ���һ���µ�ͷ�ڵ�ָ�룬�������cur��tempָ��������ڵ�ֵ����ȣ��Ͱ�curβ�嵽�½ڵ���棬
		while(temp)//
		{
			if(cur->val==temp->val)//��������ڵ�ֵ��ȣ���ִ�������ƶ�
			{
				while(cur->val==temp->val&&temp)//��������ڵ�ֵ��ȣ��Ͱ�temp����
					//�ƶ���ֱ����temp���ں�cur����ȵĽڵ��ϣ�����temp=nullptr
				{
					temp=temp->next;
				}
				while(cur!=temp)//��cur��ʼ��һֱɾ����tempλ�ô�
				{
					ListNode* next=cur;
					cur=cur->next;
					delete next;
				}

				if(temp)//��Ϊtemp��ΪԪ����ȶ��ŵ���λ���ϣ���ʱ�Ͳ�������temp����next����
				temp=temp->next;
			}
			else//����ֵ����ȣ��Ͱ�cur��ֵβ�嵽ͷ�ڵ�ĺ���
			{
				listtail->next = cur;
				listtail=cur;
				cur=temp;
				temp=temp->next;
			}
		}
		listtail->next=cur;//�����ܻ����ĩβȫ��������ͬ��Ԫ�أ�������մ���ִ�У�listtail��ָ��ԭ���Ľڵ�,���Ե���Ϊcur
		return list->next;
		*/
		ListNode* hhead = new ListNode(1);//����һ��ͷ�ڵ�
		hhead->next = head;

		ListNode* cur1 = hhead;//cur1ָ��ͷ�ڵ�
		ListNode* cur2 = head;//cur1ָ���һ���ڵ�

		if (head == nullptr)
		{
			return nullptr;
		}

		int count = 0;//��һ����־��
		while (1)
		{
			if (cur2->next == nullptr)
			{
				if (count)
				{
					count = 0;
					cur2 = cur2->next;
					cur1->next = cur2;
				}
				break;
			}
			if (cur2->next->val == cur2->val)//�������cur2->next->val==cur2->val����ɾ��cur2-��next�����ѱ�־����Ϊ1
			{
				count++;
				cur2->next = cur2->next->next;
			}
			else
			{
				if (count == 0)//���count����0��˵��û��ɾ��������ֱ��������
				{
					cur2 = cur2->next;
					cur1 = cur1->next;

				}
				else//�������ɾ�����������ð�cur2���Ǹ�λ�ø�ɾ�������Ұ�count��Ϊ0
				{
					count = 0;
					cur2 = cur2->next;
					cur1->next = cur2;
				}
			}
		}
		return hhead->next;
	}
};

#endif

#if 0

/*
ֻ��Ҫ�������������
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
		{
			return pHead;
		}
		ListNode* cur = pHead;
		ListNode* temp = pHead;
		ListNode* prev = nullptr;
		while (temp)
		{
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			if (temp)
				cur = temp;

		}
		return cur;
	}
};

#endif

#include<list>

int main()
{
	
	system("pause");
	return 0;
}