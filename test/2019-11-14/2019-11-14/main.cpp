#include<iostream>
using namespace std;

#if 0

class Solution {
public:
	int cutRope(int number) {
		/*if(number<2)
		{
			return 0;
		}
		if(number==2)
		{
			return 1;
		}
		if(number==3)
			return 2;
		int x=number/3;
		int y=number%3;

		if(y==0)
		{
			return pow(3,x);
		}
		if(y==1)
		{
			return  4*pow(3,x-1);
		}
		else
		{
			return 2*pow(3,x);
		}
		*/
		static int n = 0;
		int x = 0, i;
		if (number == 2)
			return n == 0 ? 1 : 2;
		if (number == 3)
			return n == 0 ? 2 : 3;
		n++;
		for (i = 1; i <= number / 2; i++)
		{
			if (cutRope(i)*cutRope(number - i) > x)
			{
				x = cutRope(i)*cutRope(number - i);
			}
		}
		return x;
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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {

		ListNode* cur = root;//����ѭ���жϵ�
		ListNode* cur2 = nullptr;//ָ��cur����һ������Ϊ����vector�еĲ�һ���ǵ����ڵ㣬���ܻ������ضϣ���ֹcur�Ҳ�����һ���ڵ�
		ListNode* cur1 = cur;//��¼��ʼҪ����vector�еĵ�һ���ڵ�
		vector<ListNode*>s;

		int count = 0;//������������ڵ����
		int count1 = 0;//������¼vectorÿ��Ҫ�ŵĸ���
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		int m = count % k;
		int n = count / k;

		cur = root;
		if (count <= k)
		{
			ListNode* temp;

			while (cur)
			{
				s.push_back(cur);
				temp = cur->next;
				cur->next = nullptr;
				cur = temp;
				count--;
			}
			if (s.size() < k)
			{
				s.resize(k, NULL);
			}

		}
		else
		{
			while (cur)
			{

				count1 = n + (m == 0 ? 0 : 1) - 1;//��ΪҪ����ǰ��Ĳ��ֵĳ��ȱȺ���Ĳ��ֳ��ȳ����ҳ��Ȳ�ܳ���1��
				while (count1)//��ѭ������ÿ��vector����÷Ŷ��ٸ�
				{
					cur = cur->next;
					count1--;
				}
				if (m > 0)//��Ϊmһֱ�����ܻ�Ϊ��������ü�һ���ж�
					m--;
				s.push_back(cur1);//��Ϊcur1һֱָ��Ҫ��vector�зŵĵ�һ���ڵ㣬����ֱ��push�������ٰ�����ض�


				cur2 = cur->next;//��¼cur����һ��λ�ã���ֹcur�Ҳ���·
				cur->next = nullptr;//��Ϊ�գ��ض�����

				cur = cur2;//�����ƶ�
				cur1 = cur2;

			}
		}
		return s;
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
	ListNode* oddEvenList(ListNode* head) {
		/*
		 ListNode* A=new ListNode(1);
		 ListNode* B=new ListNode(1);

		 ListNode* headA=A;
		 ListNode* headB=B;

		 ListNode* cur=head;
		 int count=0;
		 while(cur)
		 {
			 count++;
			 cur=cur->next;
		 }

		 cur=head;

			 for(int i=1;i<=count;i++)
			 {
				 if(i%2!=0)
				 {
					 headA->next=cur;
					 headA=cur;
					 cur=cur->next;
				 }
				 else
				 {
					 headB->next=cur;
					 headB=cur;
					 cur=cur->next;
				 }
		 }
		 headA->next=B->next;
		 return B->next;
		 */
		if (head == nullptr)
			return nullptr;

		ListNode* oddhead = head;//����һ������ͷָ��ָ�������ͷ
		ListNode* evenhead = head->next;//����һ��ż��ͷָ��ָ������ĵڶ����ڵ�
		ListNode* odd = oddhead;//����һ�������ڵ�ָ�룬ÿ�ζ�ָ�������������ڵ㣬�������ڵ��������ͷָ�����
		ListNode* even = evenhead;//����һ��ż���ڵ�ָ�룬ÿ�ζ�ָ��������ż���ڵ㣬��ż���ڵ����ż��ͷ�ڵ����

		while (even&&even->next)//
		{
			odd->next = even->next;//����ͼ�ͺ����ף�
			odd = even->next;
			even->next = odd->next;
			even = odd->next;
		}
		odd->next = evenhead;//��ż����ͷ�ڵ���������ĺ���
		return oddhead;

	}
};

#endif
int main()
{


	system("payse");
	return 0;
}