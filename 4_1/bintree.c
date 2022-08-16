#include "bintree.h"
#include "stdio.h"
#include "stdlib.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree	*tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		exit (errno());
	tree->pRootNode->data = rootNode.data;
	tree->pRootNode->visited = 0;
	tree->pRootNode->pParent = NULL;
	tree->pRootNode->pLeftChild = NULL;
	tree->pRootNode->pRightChild = NULL;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		exit (errno());
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;

	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		exit (errno());
	*new = element;
	pParentNode->pLeftChild = new;
	new->pParent = pParentNode;
	return (pParentNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;

	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		exit (errno());
	*new = element;
	pParentNode->pRightChild = new;
	new->pParent = pParentNode;
	return (pParentNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		exit (errno());
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		exit (errno());
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	while (pBinTree->pRootNode)
		deleteBinTreeNode(pBinTree, pBinTree->pRootNode);
}

void deleteBinTreeNode(BinTree *pBinTree, BinTreeNode* pNode)
{
	BinTreeNode	*baby;
	BinTreeNode	*papa;

	if (!pBinTree || !pNode)
		exit (errno());
	papa = pNode->pParent;
	if (pNode->pLeftChild == NULL && pNode->pRightChild == NULL)
	{
		if (!papa)
			pBinTree->pRootNode = NULL;
		else if (papa->pLeftChild == pNode && papa->pRightChild)
		{
			papa->pLeftChild = papa->pRightChild;
			papa->pRightChild = NULL;
		}
		else
			papa->pRightChild = NULL;
		free(pNode);
	}
	else if (pNode->pLeftChild && pNode->pRightChild)
	{
		baby = pBinTree->pRootNode;
		while (baby && baby->pLeftChild)
		{
			if (baby->pRightChild)
				baby = getRightChildNodeBT(baby);
			else
				baby = getLeftChildNodeBT(baby);
		}
		pNode->data = baby->data;
		pNode->visited = baby->visited;
		if (baby->pParent->pLeftChild == baby)
			baby->pParent->pLeftChild = NULL;
		else
			baby->pParent->pRightChild = NULL;
		free(baby);
	}
	else
	{
		pNode->data = pNode->pLeftChild->data;
		pNode->visited = pNode->pLeftChild->visited;
		pNode->pLeftChild = NULL;
		free (pNode->pLeftChild);
	}
}

BinTreeNode	*findJari(BinTreeNode *tmp, int *jari)
{
	while (tmp)
	{
		if (!tmp->pLeftChild)
		{			
			*jari = 0;
			return (tmp);
		}
		else if (!tmp->pRightChild)
		{
			*jari = 1;
			return (tmp);
		}
		else if
	}
}

int main()
{
	BinTree *pBinTree;
	BinTreeNode	root;
	BinTreeNode *tmp;
	BinTreeNode element;
	root.data = '0';
	int	i = 1;
	int	jari;

	pBinTree = makeBinTree(root);
	while (i < 10)
	{
		tmp = &root;
		element.data = i + '0';
		jari = findJari(tmp);
		
		if (jari == 0)
			insertLeftChildNodeBT(tmp, element);
		else if (jari == 1)
			insertRightChildNodeBT(tmp, element);
	}
}
