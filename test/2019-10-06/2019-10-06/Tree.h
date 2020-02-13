#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TreeDataType char

/**���������ݽṹ����**/
typedef struct BiTreeNode {
	char data;
	struct BiTreeNode *left;
	struct BiTreeNode *right;
} BiTreeNode, *BiTree;

/**�������Ľ���--��������ʽ����--����**/
void CreateBiTree(BiTree *T);

/**�������  ������**/
void PreOrderTravel(BiTree T);

/**������� �����**/
void InOrderTravel(BiTree T);

/**������� ���Ҹ�**/
void TailOrderTravel(BiTree T);