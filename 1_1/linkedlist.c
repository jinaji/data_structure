#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

/*
헤더 노드 ... 맨 앞을 잡고있는 걸까여? 왜 포인터가 아닐지 ,,,
그냥 data값 없는 맨 앞 가리키는 걸루 생각하기루
*/

LinkedList* createLinkedList()
{
	LinkedList	*new;

	new = (LinkedList *)malloc(sizeof(LinkedList));
	if (!new)
		return (0);
	new->headerNode.data = 0;
	new->headerNode.pLink = 0;
	new->currentElementCount = 0;
	return (new);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*new;
	ListNode	*tmp;
	int			i;

	if (!pList || position > pList->currentElementCount || position < 0)
		return (FALSE);
	new = (ListNode *)malloc(sizeof(ListNode));
	if (!new)
		return (FALSE);
	*new = element;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pLink = new;
		pList->currentElementCount++;
		return (TRUE);
	}
	i = 0;
	if (position == 0)
	{
		new->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = new;
	}
	else
	{
		tmp = pList->headerNode.pLink;
		while (i < position - 1)
		{
			tmp = tmp->pLink;
			i++;
		}
		tmp->pLink = new->pLink;
		tmp->pLink = new;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*prev;
	ListNode	*tmp;
	int			i = 0;

	if (!pList || pList->currentElementCount < 1 && position > pList->currentElementCount)
		return (FALSE);
	tmp = pList->headerNode.pLink;
	if (position == 0)
	{
		pList->headerNode.pLink = tmp->pLink;
		tmp->pLink = 0;
		free (tmp);
		pList->currentElementCount--;
		return (TRUE);
	}
	while (i < position - 1)
	{
		tmp = tmp->pLink;
		i++;
	}
	tmp->pLink = tmp->pLink->pLink;
	free (tmp);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	int	i;
	ListNode *tmp;

	i = 0;
	if (!pList || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	tmp = pList->headerNode.pLink;
	while (i < position)
	{
		tmp = tmp->pLink;
		i++;
	}
	return (tmp);
}

void clearLinkedList(LinkedList* pList)
{
	while (pList->currentElementCount)
		removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free (pList);
}

int main()
{
	int i = 0;
	LinkedList	*list;
	ListNode	*tmp;
	ListNode	new;
	ListNode	new2;
	ListNode	new3;

	new.data = 3;
	new.pLink = 0;
	new2.data = 5;
	new2.pLink = 0;
	new3.data = 7;
	new3.pLink = 0;
	list = createLinkedList();
	addLLElement(list, 0, new);
	addLLElement(list, 1, new2);
	addLLElement(list, 0, new3);
	// removeLLElement(list, 2);
	tmp = list->headerNode.pLink;
	while (i < list->currentElementCount)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->pLink;
		i++;
	}
	printf("%d\n", getLLElement(list, 0)->data);
}
