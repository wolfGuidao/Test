#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<Windows.h>
using namespace std;

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)//�����ǰ�����Ϊ�ջ����ҵ�p��q�ڵ㣬�ͷ��ظýڵ�
		{
			return root;
		}
		TreeNode* left = lowestCommonAncestor(root->left, p, q);//�ݹ鵱ǰ������������
		TreeNode* right = lowestCommonAncestor(root->right, p, q);//�ݹ�������
		if (left&&right)//������߶���Ϊ�գ�˵��p��q�ڵ�ǰ���������ֱ࣬�ӷ��ظ����
		{
			return root;
		}
		return left ? left : right;
	}
};

#endif

#if 0

class Solution {
public:
	bool isValid(string s) {
		stack<char>ss;
		char topp1;
		char topp2;
		if (s.size() % 2 != 0)
		{
			return false;
		}
		for (auto i = 0;i < s.size();i++)
		{
			if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			{
				ss.push(s[i]);
			}
			else
			{
				if (!ss.empty())
				{
					topp1 = ss.top();
					ss.pop();
					switch (topp1)
					{
					case'{':
						topp2 = '}';
						break;
					case'(':
						topp2 = ')';
						break;
					case'[':
						topp2 = ']';
						break;
					}
					if (s[i] != topp2)
					{
						return false;
					}
				}
			}
		}
		if (ss.empty() == true)
			return true;
		else
			return false;
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
int main()
{
	cout << sizeof(nullptr)<<endl;
	cout << sizeof(NULL) << endl;
	cout << NULL;
	system("pause");
	return 0;
}