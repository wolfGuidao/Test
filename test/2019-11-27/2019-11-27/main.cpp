#include<iostream>
using namespace std;



/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{

		if (pRoot1 == nullptr)//�������ʱpRoot1����pRoot2Ϊ��ֱ�ӷ���false
		{
			return false;
		}
		if (pRoot2 == nullptr)
		{
			return false;
		}
		if (dfs(pRoot1, pRoot2))//dfs��pRoot1��pRoot2���ǵ���dfs�����жϵ�ǰ������
			//���ǲ�����ȵģ��������ȵģ�����dfs�н����ж��ǲ������еĽڵ㶼��ȣ�
			//���dfs����true��˵���ӵ�ǰ�ڵ㿪ʼ���������⣬�ͷ���true
			return true;
		else//������ǵ�ǰ�ڵ㲻��ȣ��͵ݹ��ж�pRoot1�����������������������������н��бȽϣ���
			//�ܷ��ҵ���������������ṹ
			return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

	}
	bool dfs(TreeNode* pRoot1, TreeNode* pRoot2)//�ú������жϴ�pRoot1��pRoot2
		//��ʼ�����pRoot1��pRoot2��Ⱦ͵ݹ��ж�pRoot2�����������������������ֱ�ӷ���false

	{
		//pRoot1Ϊ������A��pRot2Ϊ������B�������ж�pRoot2�ǲ���pRoot1���ӽṹ
		if (pRoot2 == nullptr)//���pRoot2Ϊ��˵��pRoot2��ͷ�ڵ㿪ʼ��һֱ��ȣ�ֱ���ߵ���
			//������ֱ�ӷ���true����������ע��??pRoot2==nullptr����ж�����������
			//pRoot1==nullptr�������֮ǰ����Ϊ���ܻ�ͬʱΪ�գ��ᵼ�³���
		{
			return true;
		}
		if (pRoot1 == nullptr)//��ʾpRoot1��һ��Ϊ�գ�pRoot2��û��Ϊ�գ��ͷ���false
		{
			return false;
		}
		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}
		else
		{
			//�ݹ��ж�
			return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
		}
	}
	
	if(!pRoot1)
		return false;
	if(!pRoot2)
		return false;
	return ( dfs(pRoot1,pRoot2)) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

bool dfs(TreeNode * pRoot1, TreeNode * pRoot2){
	if(!pRoot2)
		return true;
	if(!pRoot1)
		return false;
	if(pRoot1->val != pRoot2->val)
		return false;
	return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
}

};
*/


int main()
{
	short f = 0xb600;
	if (f == 0xb600)
	{
		cout << "wolf" << endl;

	}
	else
	{
		cout << "guidao" << endl;
	}
	system("pause");
	return 0;
}