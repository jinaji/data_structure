#include "bintree.h"
#include "stdio.h"
#include "stdlib.h"
#include <errno.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree	*tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		exit (0);
	tree->pRootNode = malloc(sizeof(BinTreeNode));
	if (!tree->pRootNode)
		exit (0);
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
		exit (0);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;

	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		exit (0);
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
		exit (0);
	*new = element;
	pParentNode->pRightChild = new;
	new->pParent = pParentNode;
	return (pParentNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		exit (0);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		exit (0);
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
		exit (0);
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

// BinTreeNode	*findJari(BinTreeNode *tmp, int *jari)
// {
// 	while (tmp)
// 	{
// 		if (!tmp->pLeftChild)
// 		{			
// 			*jari = 0;
// 			return (tmp);
// 		}
// 		else if (!tmp->pRightChild)
// 		{
// 			*jari = 1;
// 			return (tmp);
// 		}
// 		else if
// 	}
// }


void	preTravelTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	printf("%c\n", pNode->data);
	preTravelTree(pNode->pLeftChild);
	preTravelTree(pNode->pRightChild);
}

void	midTravelTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	midTravelTree(pNode->pLeftChild);
	printf("%c\n", pNode->data);
	midTravelTree(pNode->pRightChild);
}

void	backTravelTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	backTravelTree(pNode->pLeftChild);
	backTravelTree(pNode->pRightChild);
	printf("%c\n", pNode->data);
}

int main()
{
	BinTree *pBinTree;
	BinTreeNode	root;
	BinTreeNode *tmp;
	BinTreeNode element;
	// root.data = '0';
	// int	i = 1;
	// int	jari;

	// pBinTree = makeBinTree(root);
	// while (i < 10)
	// {
	// 	tmp = &root;
	// 	element.data = i + '0';
	// 	jari = findJari(tmp);
		
	// 	if (jari == 0)
	// 		insertLeftChildNodeBT(tmp, element);
	// 	else if (jari == 1)
	// 		insertRightChildNodeBT(tmp, element);
	// }

	BinTreeNode *Lparent;
	BinTreeNode	*Rparent;

	element.data = 'A';
	pBinTree = makeBinTree(element);
	element.data += 1; // B
	insertLeftChildNodeBT(pBinTree->pRootNode, element);
	element.data += 1; // C
	insertRightChildNodeBT(pBinTree->pRootNode, element);
	element.data += 1; // D
	Lparent = pBinTree->pRootNode->pLeftChild;
	Rparent = pBinTree->pRootNode->pRightChild;
	insertLeftChildNodeBT(Lparent, element);
	element.data += 1; // E
	insertRightChildNodeBT(Lparent, element);
	element.data += 1; // F
	insertLeftChildNodeBT(Rparent, element);
	element.data += 1; // G
	insertRightChildNodeBT(Rparent, element);
	element.data += 1; // H
	Rparent = Lparent->pRightChild; // E
	Lparent = Lparent->pLeftChild; // D
	insertLeftChildNodeBT(Lparent, element);
	element.data += 1; // I
	insertRightChildNodeBT(Lparent, element);
	element.data += 1; // J
	insertLeftChildNodeBT(Rparent, element);
	// printf("%c\n", Rparent->data);
	// printf("%c\n", Rparent->pParent->data);
	element.data += 1; // K
	Lparent = pBinTree->pRootNode->pRightChild->pLeftChild; // F
	// printf("%c\n", Lparent->data);
	Rparent = Lparent->pParent->pRightChild; // G
	insertRightChildNodeBT(Lparent, element);
	element.data += 1; // L
	insertLeftChildNodeBT(Rparent, element);
	// printf("%c\n", Rparent->pLeftChild->data);
	element.data += 1; // M
	insertRightChildNodeBT(Rparent, element);
	// printf("%c\n", Rparent->pLeftChild->data);

	backTravelTree(pBinTree->pRootNode);
// 	printf("%c\n", pBinTree->pRootNode->pLeftChild->pRightChild->pLeftChild->data);
// 	printf("%c\n", pBinTree->pRootNode->pRightChild->pRightChild->pLeftChild->data);
// 	printf("%c\n", pBinTree->pRootNode->pRightChild->pRightChild->pRightChild->data);
 }
