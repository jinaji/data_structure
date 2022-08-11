#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

/*
node가 배열 형식으로 있어서 인덱스로 바로 접근할 수 있고 그 안에 data 들어있는 걸로 이해하기루 햇어연 ...
max 정해져있는 배열로 생각하기루 ,,,
*/

int addALElement(ArrayStack* pStack, int position, ArrayStackNode element)
{
	int	i;

	i = 0;
	if (isArrayStackFull(pStack) || position < 0 || position > pStack->maxElementCount || pStack->currentElementCount + 1 < position)
		return (FALSE);
	i = pStack->currentElementCount + 1;
	while (i > position)
	{
		pStack->pElement[i].data = pStack->pElement[i - 1].data;
		i--;
	}
	pStack->pElement[i].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayStack* pStack, int position)
{
	int	i;

	if (!pStack || position < 0 || position > pStack->currentElementCount || pStack->currentElementCount < 1)
		return (FALSE);
	i = position;
	while (i < pStack->currentElementCount)
	{
		pStack->pElement[i] = pStack->pElement[i + 1];
		i++;
	}
	pStack->pElement[i].data = 0;
	pStack->currentElementCount--;
	return (TRUE);
}

ArrayStackNode* getALElement(ArrayStack* pStack, int position)
{
	if (!pStack || position < 0 || position > pStack->maxElementCount || pStack->currentElementCount < 1)
		return (FALSE);
	return (&(pStack->pElement[position]));
}

void displayArrayStack(ArrayStack* pStack)
{
	int	i;

	i = 0;
	if (!pStack || pStack->currentElementCount == 0)
		return ;
	while (i < pStack->currentElementCount)
	{
		printf("%d\n", pStack->pElement[i].data);
		i++;
	}
}

void clearArrayStack(ArrayStack* pStack)
{
	int	i;

	if (!pStack)
		return ;
	i = 0;
	while (i < pStack->currentElementCount)
	{
		pStack->pElement[i].data = 0;
		i++;
	}
	pStack->currentElementCount = 0;
}

int getArrayStackLength(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->currentElementCount);
}

int main()
{
	ArrayStack		*Stack;
	ArrayStackNode	new;
	ArrayStackNode	new2;
	ArrayStackNode	new3;
	ArrayStackNode	new4;
	ArrayStackNode	new5;

	new.data = 1;
	new2.data = 2;
	new3.data = 3;
	new4.data = 4;
	new5.data = 5;
	Stack = createArrayStack(10);
	addALElement(Stack, 0, new);
	addALElement(Stack, 0, new2);
	addALElement(Stack, 0, new3);
	addALElement(Stack, 0, new4);
	addALElement(Stack, 0, new5);
	removeALElement(Stack, 5);
	displayArrayStack(Stack);
	// for (int i = 0; Stack->currentElementCount > i; i++)
	// 	printf	("%d\n", Stack->pElement[i].data );
}
