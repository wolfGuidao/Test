#include<iostream>
using namespace std;

#if 0

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node* cur = head;
		//��Ϊ���������Ľڵ��ַ��ԭ���Ľڵ�û���κι�ϵ��������randomʱӦ��ע��
		while (cur)//��һ����ԭ�����ÿһ���ڵ���濽����ͬ�Ľڵ����ÿһ���ڵ�ĺ���
		{
			Node* temp = cur->next;
			Node* copy = new Node(cur->val);
			cur->next = copy;
			copy->next = temp;
			cur = temp;

		}
		cur = head;
		while (cur)//�ڶ������ÿ��������Ľڵ��random
		{
			Node* temp1 = cur->next;
			Node* temp2 = temp1->next;
			if (cur->random == nullptr)//�жϽڵ��random�Ƿ�Ϊ��
				temp1->random = nullptr;
			else
				temp1->random = cur->random->next;
			cur = temp2;

		}
		Node* newhead = nullptr;
		Node* newheadtail = nullptr;
		cur = head;
		while (cur)//���������ѿ��������Ľڵ�⿪���һ���µ��������ָ�ԭ����
		{
			Node* temp1 = cur->next;
			Node* temp2 = temp1->next;

			if (newhead == nullptr)
			{
				newhead = newheadtail = temp1;
				newheadtail = temp1;

			}
			else
			{
				newheadtail->next = temp1;
				newheadtail = temp1;
			}
			cur->next = temp2;
			cur = temp2;
		}
		return newhead;
	}
};

#endif


int main()
{

	system("pause");
	return 0;
}