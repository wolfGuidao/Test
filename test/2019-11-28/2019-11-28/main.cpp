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
	vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>>ret;
		vector<int>temp;
		if(root==nullptr)
		{
			return ret;
		}
		temp.push_back(root->val);
		if((expectNumber-root->val)==0&&root->left==nullptr&&root->right==nullptr)
		{
			ret.push_back(temp);
		}
		if(root->left)
		{
			FindPath(root->left,expectNumber-root->val);
		}
		if(root->right)
		{
			FindPath(root->right,expectNumber-root->val);

		}
		if(temp.size()!=0)
		{
			temp.pop_back();
		}
		return ret;
	}
};
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	vector<vector<int> > buffer;//�������Ľ��
	vector<int> tmp;//��ʱ�洢
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return buffer;
		tmp.push_back(root->val);//�Ѹ�����ֵ�ŵ�temp��
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL)
		{
			buffer.push_back(tmp);//�������ýڵ���Ҷ�ӽڵ㣬�������expecNumber����
			//��ǰ�ڵ��val��Ϊ0��˵��ע��·���������⣬ֱ�ӷŵ�buffer��
		}
		if (root->left)//�ݹ���ߣ�ע���ʱֻ�����������Һ�expectNumber-root->val����
			FindPath(root->left, expectNumber - root->val);
		if (root->right)//�ݹ��ұ�
			FindPath(root->right, expectNumber - root->val);
		if (tmp.size() != 0)//����ݹ��ҵ�Ҷ�ӽڵ㵫����(expectNumber-root->val)��=0��
			//˵����һ·�����������⣬�����丸�׽ڵ㣬�����ݹ飬����temp�����һ��Ԫ��ɾ��
			tmp.pop_back();
		return buffer;
	}
};