class Solution {
public:
	int Gethight(TreeNode* pRoot)
	{
		//��ĳ�������������
		if (pRoot == nullptr)
		{
			return 0;
		}
		return max(1 + Gethight(pRoot->right), 1 + Gethight(pRoot->left));


	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr)
		{
			return true;
		}
		//�������������������������Ȳ����1����ֱ�ӷ���false
		//��֮�ݹ�ø����������������ж��Ƿ����������ֱ�����Һ���Ϊ��
		if (abs(Gethight(pRoot->left) - Gethight(pRoot->right)) <= 1)
		{
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

		}
		else
		{
			return false;
		}
	}
};