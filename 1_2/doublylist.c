#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

/*
pLLink pRLink 뭔지 모르겠어서 Left Right로 생각햇어염
L prev R next 처럼 썻음!!
*/

DoublyList* createDoublyList()
{
	DoublyList  *new;

	new = (DoublyList *)malloc(sizeof(DoublyList));
	if (!new)
		return (FALSE);
	new->currentElementCount = 0; // 헤더노드는 안건드려도 될 것 같아서 걍 냅둿어연
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
	int              i = 0;

	if (!pList || position < 0 || position > pList->currentElementCount + 1)
		return (FALSE);
	*new = element;
	tmp = pList->headerNode.pRLink;
	while (i < position)
	{
		tmp = tmp->pRLink;
		i++;
	}
	tmp->pRLink->pLLink = new; // 포지션 위치 여기가 맞나 ?? tmp next의 prev(원래 tmp)에 new 연결
	new->pRLink = tmp->pRLink; // new next에 tmp next 연결
	new->pLLink = tmp; // new prev 에 tmp 연결
	tmp->pRLink = new; // tmp next에 new 연결 
	if (position == 0)
        pList->headerNode.pRLink = new;
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
		pList->headerNode.pRLink = tmp->pRLink; // 맨 앞 없애는 거면 헤더 옮겨주고
	while (i < position)
	{
		tmp = tmp->pRLink;
		i++;
	}
	tmp->pRLink->pLLink = tmp->pLLink; // 포지션 위치가 아직도 헷갈리는데 요거 맞을 것 같애연
	tmp->pLLink->pRLink = tmp->pRLink; // tmp 없애야되니까 얘 전후로 이어주고
	tmp->pRLink = 0; // tmp에서 뻗어나간 건 끊어줬어여
	tmp->pLLink = 0; // 싹둑
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
		pList->headerNode.pRLink = tmp2; // 계속 헤드노드 초기화 시키면서 없애주려고 했는데 이게맞는지 ... 주석 쓰면서 생각해보니까 remove element 계속 0번째로 호출해도 될 것 같애여
	}
	// while (pList->headerNode.pRLink)
	// {
	// 	removeDLElement(pList, 0); 되지 않을까여?
	// }
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
