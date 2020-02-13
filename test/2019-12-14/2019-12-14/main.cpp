#include<iostream>
using namespace std;
typedef char TypeData;

typedef struct Tree
{
	TypeData _val;
	Tree* left;
	Tree* right;
}BiTreeNode;
//BiTreeNode* Tree;
void CreateBiTree(BiTreeNode** T)
{//
	TypeData val;
	scanf("%c", &val);

	if (val == '#')
	{
		*T = NULL; //null��ʾΪ��֦
	}
	else
	{
		*T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
		(*T)->_val = val;
		CreateBiTree(&(*T)->left);
		CreateBiTree(&(*T)->right);
	}
}

void InOrderTravel(BiTreeNode* T)
{
	if (T == NULL)
		return;
	InOrderTravel(T->left);
	printf("%c ", T->_val);
	InOrderTravel(T->right);
}
int main()
{
	//ע�����Ҫ������Զ������Ľڵ���и��ģ���Ҫ������ָ�룬���ֻ���з��ʣ�ֻ�贫һ��ָ�뼴��
	BiTreeNode* T;
	T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	CreateBiTree(&T);
	InOrderTravel(T);
	return 0;
}