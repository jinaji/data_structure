#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

/*
node가 배열 형식으로 있어서 인덱스로 바로 접근할 수 있고 그 안에 data 들어있는 걸로 이해하기루 햇어연 ...
max 정해져있는 배열로 생각하기루 ,,,
*/

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList	*new;

	if (maxElementCount < 0)
		return (FALSE);
	new = (ArrayList *)malloc(sizeof(ArrayList));
	if (!new)
		return (0);
	new->currentElementCount = 0;
	new->maxElementCount = maxElementCount;
	new->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!new->pElement)
	{
		free (new);
		return (0);
	}
	return (new);
}

void deleteArrayList(ArrayList* pList) // position 없는 거 보면 그냥 다 날리는 게 맞는 듯	
{
	int	i;

	i = 0;
	if (!pList)
		return ;
	while (i < pList->currentElementCount)
	{
		pList->pElement[i].data = 0;
		i++;
	}
	free(pList->pElement);
	pList->pElement = 0;
	pList->currentElementCount = 0;
	free(pList);
	pList = 0;
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (FALSE);
	else if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int	i;

	i = 0;
	if (isArrayListFull(pList) || position < 0 || position > pList->maxElementCount || pList->currentElementCount + 1 < position)
		return (FALSE);
	i = pList->currentElementCount + 1;
	while (i > position)
	{
		pList->pElement[i].data = pList->pElement[i - 1].data;
		i--;
	}
	pList->pElement[i].data = element.data;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	int	i;

	if (!pList || position < 0 || position > pList->currentElementCount || pList->currentElementCount < 1)
		return (FALSE);
	i = position;
	while (i < pList->currentElementCount)
	{
		pList->pElement[i] = pList->pElement[i + 1];
		i++;
	}
	pList->pElement[i].data = 0;
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (!pList || position < 0 || position > pList->maxElementCount || pList->currentElementCount < 1)
		return (FALSE);
	return (&(pList->pElement[position]));
}

void displayArrayList(ArrayList* pList)
{
	int	i;

	i = 0;
	if (!pList || pList->currentElementCount == 0)
		return ;
	while (i < pList->currentElementCount)
	{
		printf("%d\n", pList->pElement[i].data);
		i++;
	}
}

void clearArrayList(ArrayList* pList)
{
	int	i;

	if (!pList)
		return ;
	i = 0;
	while (i < pList->currentElementCount)
	{
		pList->pElement[i].data = 0;
		i++;
	}
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

int main()
{
	ArrayList		*list;
	ArrayListNode	new;
	ArrayListNode	new2;
	ArrayListNode	new3;
	ArrayListNode	new4;
	ArrayListNode	new5;

	new.data = 1;
	new2.data = 2;
	new3.data = 3;
	new4.data = 4;
	new5.data = 5;
	list = createArrayList(10);
	addALElement(list, 0, new);
	addALElement(list, 0, new2);
	addALElement(list, 0, new3);
	addALElement(list, 0, new4);
	addALElement(list, 0, new5);
	removeALElement(list, 5);
	displayArrayList(list);
	// for (int i = 0; list->currentElementCount > i; i++)
	// 	printf	("%d\n", list->pElement[i].data );
}
