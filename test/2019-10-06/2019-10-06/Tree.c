#include "Tree.h"


/**********************************************
Author:tmw
date:2018-2-13
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100



/**�������Ľ���--��������ʽ����--����**/
void CreateBiTree(BiTree *T) {
	char val;
	scanf("%c", &val);

	if (val == '#')
		*T = NULL; //null��ʾΪ��֦

	else {
		*T = (BiTree)malloc(sizeof(BiTreeNode));
		(*T)->data = val;
		CreateBiTree(&(*T)->left);
		CreateBiTree(&(*T)->right);
	}
}


/**�������  ������**/
void PreOrderTravel(BiTree T) {
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTravel(T->left);
	PreOrderTravel(T->right);
}

/**������� �����**/
void InOrderTravel(BiTree T) {
	if (T == NULL)
		return;
	InOrderTravel(T->left);
	printf("%c ", T->data);
	InOrderTravel(T->right);
}

/**������� ���Ҹ�**/
void TailOrderTravel(BiTree T) {
	if (T == NULL)
		return;
	TailOrderTravel(T->left);
	TailOrderTravel(T->right);
	printf("%c ", T->data);
}
