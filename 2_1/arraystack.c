#include <stdlib.h>
#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount);
int pushLS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popLS(ArrayStack* pStack);
ArrayStackNode* peekLS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack	*new;

	new = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (!new)
		return (FALSE);
	new->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!new->pElement)
		exit (1);
	new->currentElementCount = 0;
	new->maxElementCount = maxElementCount;
	return (new);
}

int pushLS(ArrayStack* pStack, ArrayStackNode element)
{
	ArrayStackNode	*new;

	if (!pStack || isArrayStackFull(pStack))
		return (FALSE);
	addALElement(pStack, pStack->currentElementCount - 1, element);
	pStack->pTopElement = pStack->pElement[pStack->currentElementCount - 1];
	return (TRUE);
}

ArrayStackNode* popLS(ArrayStack* pStack)
{
	ArrayStackNode	*tmp;

	if (!pStack || isArrayStackEmpty(pStack))
		return (FALSE);
	tmp = getALElement(pStack, pStack->currentElementCount - 1);
	removeALElement(pStack, pStack->currentElementCount - 1);
	pStack->pTopElement = pStack->pElement[pStack->currentElementCount - 1];
	return (tmp);
}

ArrayStackNode* peekLS(ArrayStack* pStack)
{
	return (getALElement(pStack, pStack->currentElementCount - 1));
}

void deleteArrayStack(ArrayStack* pStack)
{
	int	i;

	i = 0;
	if (!pStack)
		return ;
	while (i < pStack->currentElementCount)
	{
		pStack->pElement[i].data = 0;
		i++;
	}
	free(pStack->pElement);
	pStack->pElement = 0;
	pStack->currentElementCount = 0;
	free(pStack);
	pStack = 0;
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}


int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}


/*
ArrayList	*pList;

LinkedStack* createLinkedStack()
{
	LinkedStack	*new;

	new = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!new)
		return (FALSE);
	new->currentElementCount = 0;
	new->pTopElement = 0;
	return (new);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	ArrayListNode	tmp;

	if (isArrayListFull(pStack))
		return (FALSE);
	tmp.data = element.data;
	addALElement(pList, getArrayListLength, tmp);
}

StackNode* popLS(LinkedStack* pStack)
{
	if (!pStack || isLinkedStackEmpty(pStack))
		return (FALSE);
	removeALElement(pList, 0);
	return (pStack->pTopElement);
}

StackNode* peekLS(LinkedStack* pStack)
{
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	deleteArrayList(pList);
	free (pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	if (!pList || !pStack)
		return (FALSE);
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
*/