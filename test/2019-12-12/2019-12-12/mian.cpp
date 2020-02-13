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
	bool isSymmetricchild(TreeNode* root1, TreeNode* root2)
	{//���ⶨ��һ�������������ݹ��ж�
		if (root1 == root2 && root2 == nullptr)//�������������ͬʱ�ߵ��ղ�˵�����������ж���ɣ�
		{
			return true;
		}
		if (root1 == nullptr || root2 == nullptr)//����һ��Ϊ�գ�˵��ĳ��������һ������գ�ֱ�ӷ���false
		{
			return false;
		}
		if (root1->val == root2->val)//�ݹ�
		{
			return isSymmetricchild(root1->left, root2->right) && isSymmetricchild(root1->right, root2->left);
		}
		else
		{
			return false;
		}
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}
		return isSymmetricchild(root, root);
	}
};

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
	//����������
	int getlength(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max((1 + getlength(root->left)), (1 + getlength(root->right)));//?(1+getlength(root->left)):(1+getlength(root->right));

	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}//�ݹ��ж�
		if (abs(getlength(root->left) - getlength(root->right)) <= 1)
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
		else
		{
			return false;
		}
	}
};