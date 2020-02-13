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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}
		if (l1 == nullptr&&l2 == nullptr)
		{
			return nullptr;
		}

		ListNode* head = new ListNode(1);//Ϊl1�����Ը�ͷ�ڵ�
		head->next = l1;//��ͷ�ڵ��l1��������

		ListNode* cur1 = l1;//������ʱ�ڵ�ָ���¼l1�ıȽ�Ԫ��
		ListNode* cur2 = l2;//������ʱ�ڵ�ָ���¼l2�ıȽ�Ԫ��
		ListNode* temp1 = head;//temp1ʼ��ָ��cur1��ǰһ���ڵ㣬�������
		ListNode* temp2 = cur2->next;//temp2ָ��cur2�ĺ�һ���ڵ㣬��Ϊһ���������룬l2�Ѿ����ƻ�������Ҫ��ǰ��¼������cur2���޷�ǰ��
		while (cur1&&cur2)
		{
			if (cur2->val < cur1->val)//���cur2��valС��cur1��val�Ͱ�cur2�Ľڵ�嵽cur1��ǰ��
			{
				//if(temp1==cur1)
				//{
				//    temp2 = cur2->next;
				//    cur2->next=cur1;
				//    l1=cur2;
				//    temp1=cur2;
				//    cur2 = temp2;
				//    continue;
				//}

				temp2 = cur2->next;//����cur2����һ��λ��

				temp1->next = cur2;//ִ�в������
				cur2->next = cur1;

				temp1 = cur2;//��Ϊ���ܷ���ͷ�壬Ϊ�˺��������뱣��һ�£���temp1ָ��cur2��

				cur2 = temp2;//cur2����
			}
			else//cur2��val����cur1��val���Ͱ�cur1���ƣ���cur2����һ��cur1�Ƚ�
			{
				temp1 = cur1;
				cur1 = temp1->next;//cur1����
			}
		}
		if (cur1 == nullptr)//������cur1�ߵ���β����cur2��û�ߵ���β���Ͱ�cur2ֱ�ӽӵ�cur1�ĺ��棬���cur2�ߵ���β����Ϊ���صľ���cur1����cur1������������ģ����ԾͲ��ù�
		{
			temp1->next = cur2;
		}
		return head->next;//��Ϊ���ǽ�ͷ�ڵ��ʱ���ͷ�ڵ����һ��ֵ�����Է���head->next
	}
};

#endif

class Date
{
public:
	void Printf()
	{
		cout << _a << endl;
	}
	void show()
	{
		cout << "hello world" << endl;
	}
private:
	int _a=10;
};

#if 0

/*
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* head = new ListNode(1);
		head->next = pHead;
		ListNode* top = head;

		ListNode* cur = pHead;
		ListNode* temp = cur->next;

		if (pHead == nullptr)
		{
			return nullptr;
		}

		int count = 0;
		while (temp || count)
		{
			int a = cur->val;
			int b = temp->val;
			if (a == b)
			{
				if (temp->next != nullptr)
				{
					temp = temp->next;
					a = cur->val;
					b = temp->val;
					count++;
					continue;
				}

			}
			if (count != 0)
			{
				top->next = temp;
				count = 0;
			}
			else
			{
				top = cur;
			}
			cur = temp;
			temp = temp->next;
		}
		return head->next;
	}
};

#endif

#if 0


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* smallhead = new ListNode(0);//����һ��С��x��ͷ�ڵ�
		ListNode* largehead = new ListNode(0);//����һ�����ڵ���x��ͷ�ڵ�

		ListNode* small = smallhead;//����ͷָ��ָ��ͷ�ڵ�
		ListNode* large = largehead;

		while (pHead)//ÿ�αȽ�ͷ�ڵ�
		{
			if (pHead->val < x)
			{
				small->next = pHead;
				small = small->next;
				pHead = pHead->next;
			}
			else
			{
				large->next = pHead;
				large = large->next;
				pHead = pHead->next;
			}
		}
		small->next = largehead->next;//�νӣ�ע��ͷ�ڵ�������ֵ�ģ�����ͷ�ڵ㣬ָ��ͷ�ڵ����һ���ڵ�
		large->next = nullptr;//�ÿ�
		return smallhead->next;
	}
};

#endif

#include<algorithm>
#include<vector>

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		auto it = nums.begin();
		sort(it, it + nums.size());

		int i = 0;
		int count = 0;
		while (i < nums.size() )
		{
			if (nums[i] == val)
			{
				nums.erase(it + i);
				//count++;
			}
			else
			{
				i++;
			}
		}
		return nums.size();
	}
};

//void Test()
//{
//	Date* p = nullptr;
//	//p->Printf();
//	p->show();
//}


void Test()
{
	vector<int>nums{ 3,2,2,3 };
	Solution s;
	s.removeElement(nums, 3);


}
int main()
{
	Test();
	system("pause");
	return 0;
}