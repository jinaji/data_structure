#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

/*
헤더 노드 ... 맨 앞을 잡고있는 걸까여? 왜 포인터가 아닐지 ,,,
그냥 data값 없는 맨 앞 가리키는 걸루 생각하기루
*/

int addLLElement(LinkedStack* pStack, int position, StackNode element)
{
	StackNode	*new;
	StackNode	*tmp;
	int			i;

	if (!pStack || position > pStack->currentElementCount || position < 0)
		return (FALSE);
	new = (StackNode *)malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	*new = element;
	if (pStack->currentElementCount == 0)
	{
		pStack->pTopElement = new;
		pStack->currentElementCount++;
		return (TRUE);
	}
	i = 0;
	if (position == 0)
	{
		new->pLink = pStack->pTopElement;
		pStack->pTopElement = new;
	}
	else
	{
		tmp = pStack->pTopElement;
		while (i < position - 1)
		{
			tmp = tmp->pLink;
			i++;
		}
		tmp->pLink = new->pLink;
		tmp->pLink = new;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedStack* pStack, int position)
{
	StackNode	*prev;
	StackNode	*tmp;
	int			i = 0;

	if (!pStack || pStack->currentElementCount < 1 && position > pStack->currentElementCount)
		return (FALSE);
	tmp = pStack->pTopElement->pLink;
	if (position == 0)
	{
		pStack->pTopElement->pLink = tmp->pLink;
		tmp->pLink = 0;
		free (tmp);
		pStack->currentElementCount--;
		return (TRUE);
	}
	while (i < position - 1)
	{
		tmp = tmp->pLink;
		i++;
	}
	tmp->pLink = tmp->pLink->pLink;
	free (tmp);
	pStack->currentElementCount--;
	return (TRUE);
}

StackNode* getLLElement(LinkedStack* pStack, int position)
{
	int	i;
	StackNode *tmp;

	i = 0;
	if (!pStack || position < 0 || position > pStack->currentElementCount)
		return (FALSE);
	tmp = pStack->pTopElement->pLink;
	while (i < position)
	{
		tmp = tmp->pLink;
		i++;
	}
	return (tmp);
}

void clearLinkedStack(LinkedStack* pStack)
{
	while (pStack->currentElementCount)
		removeLLElement(pStack, 0);
}

int getLinkedStackLength(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->currentElementCount);
}
