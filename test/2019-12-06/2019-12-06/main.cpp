/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	bool isSymmetricalChild(TreeNode* pRoot1, TreeNode* pRoot2)
	{//ֻ����������ͬʱΪ��ʱ����Ϊ�棬����������Ǽ�
		if (pRoot1 == nullptr&&pRoot2 != nullptr)
		{
			return false;
		}
		else if (pRoot1 != nullptr&&pRoot2 == nullptr)
		{
			return false;
		}
		else if (pRoot1 == pRoot2 && pRoot2 == nullptr)
		{
			return true;
		}

		if (pRoot1->val != pRoot2->val)//�������������ֵ����ȣ�ֱ�ӷ���false
		{
			return false;
		}
		else//�ݹ��ж϶Գ�λ�õ���������Ϊ�Գ�����ÿ���жϲ���ͬһ���ڵ�����
		{
			return isSymmetricalChild(pRoot1->left, pRoot2->right) &&
				isSymmetricalChild(pRoot1->right, pRoot2->left);
		}

	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetricalChild(pRoot, pRoot);
	}

};