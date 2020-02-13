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
	bool isSubtreechild(TreeNode* s, TreeNode* t)
	{//�ж���������ֵ�ͽṹ�Ƿ����
		if (t == nullptr&&s == nullptr)//ֻ��ͬʱΪ�ղŷ���true������ͬʱΪ��ʱ������ÿ����Ӧ�ڵ�ֵ��ȣ����ҽṹһ��
		{
			return true;
		}
		if (s == nullptr)
		{
			return false;
		}
		if (t == nullptr)
		{
			return false;
		}
		if (s->val != t->val)
		{
			return false;

		}
		else
		{//�ݹ��ж�
			return isSubtreechild(s->left, t->left) && isSubtreechild(s->right, t->right);
		}
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		//ע������ⲻ��Ҫ�ڵ��ֵ��ȣ����һ�Ҫ�ṹ��ͬ�ŷ���true
		if (s == nullptr)
		{
			return false;
		}
		if (t == nullptr)
		{
			return false;
		}
		//���isSubtreechild����true˵���ҵ�ƥ����Ӵ�ֱ�ӷ��أ���֮��s�еݹ�������ܷ��ҵ�
		if (isSubtreechild(s, t))
		{
			return true;
		}
		else
		{
			return isSubtree(s->right, t) || isSubtree(s->left, t);
		}
	}
};