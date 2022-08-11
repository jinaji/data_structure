#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
	DoublyList  *new;

	new = (DoublyList *)malloc(sizeof(DoublyList));
	if (!new)
		return (FALSE);
	new->currentElementCount = 0;
	return (new);
}

void deleteDoublyList(DoublyList* pList)
{
	if (!pList)
		return (FALSE);
	clearDoublyList(pList);
	free (pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode  *new;
	DoublyListNode  *tmp;
    DoublyListNode  *last;
	int              i = 0;

	if (!pList || position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	*new = element;
	tmp = pList->headerNode.pRLink;
	while (i < position)
	{
		tmp = tmp->pLLink;
		i++;
	}
	tmp->pRLink->pLLink = new;
	new->pRLink = tmp->pRLink;
	new->pLLink = tmp;
	tmp->pRLink = new;
    if (position == 0)
    {
        pList->headerNode.pRLink = new;
        last = pList->headerNode.pRLink;
        while (last) // 처음이면 처음이랑 마지막 이어주려고 추가된부분
            last = last->pRLink;
        last->pRLink = new;
        new->pLLink = last;
    }
    else if (position == pList->currentElementCount + 1)
    {
        new->pLLink = pList->headerNode.pRLink;
        pList->headerNode.pLLink = new; // 마지막이면 처음이랑 이어주려고 추가된부분
    }
    pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode  *tmp;
	int              i = 0;

	if (!pList || position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	tmp = pList->headerNode.pRLink;
	if (position == 0)
		pList->headerNode.pRLink = tmp->pRLink;
	while (i < position)
	{
		tmp = tmp->pLLink;
		i++;
	}
	tmp->pRLink->pLLink = tmp->pLLink;
	tmp->pLLink->pRLink = tmp->pRLink;
	tmp->pRLink = 0;
	tmp->pLLink = 0;
	free (tmp);
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode	*tmp;
	DoublyListNode	*tmp2;
	int				i = 0;

	if (!pList)
		return (FALSE);
	tmp = pList->headerNode.pRLink;
	while (tmp2)
	{
		tmp2 = tmp->pRLink;
		tmp->data = 0;
		tmp->pLLink = 0;
		tmp->pRLink = 0;
		free (tmp);
		pList->headerNode.pRLink = tmp2;
	}
	pList->currentElementCount = 0;
	return (TRUE);
}

int getDoublyListLength(DoublyList* pList)
{
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*tmp;
	int				i = 0;
	
	tmp = pList->headerNode.pRLink;
	while (i < position)
	{
		tmp = tmp->pRLink;
		i++;
	}
	return (tmp);
}

void displayDoublyList(DoublyList* pList)
{
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("%d\n", getDLElement(pList, i)->data);
}
