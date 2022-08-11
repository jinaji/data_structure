#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

int addLLElement(LinkedStack* pStack, int position, StackNode element);
int removeLLElement(LinkedStack* pStack, int position);
StackNode* getLLElement(LinkedStack* pStack, int position);
void clearLinkedStack(LinkedStack* pStack);
int getLinkedStackLength(LinkedStack* pStack);

LinkedStack* createLinkedStack()
{
	LinkedStack	*new;

	new = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!new)
		return (0);
	new->pTopElement = (StackNode *)malloc(sizeof(StackNode));
	if (!new->pTopElement)
		exit(1);
	new->pTopElement->pLink = 0;
	new->currentElementCount = 0;
	return (new);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*tmp;

	if (!pStack || isLinkedStackFull(pStack))
		return (FALSE);
	addLLElement(pStack, 0, element);
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*tmp;

	if (!pStack || isLinkedStackEmpty(pStack))
		return (FALSE);
	tmp = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	return (tmp);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	clearLinkedStack(pStack);
	free (pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
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

// int main()
// {
// 	int i = 0;
// 	LinkedStack	*Stack;
// 	StackNode	*tmp;
// 	StackNode	new;
// 	StackNode	new2;
// 	StackNode	new3;

// 	new.data = 3;
// 	new.pLink = 0;
// 	new2.data = 5;
// 	new2.pLink = 0;
// 	new3.data = 7;
// 	new3.pLink = 0;
// 	Stack = createLinkedStack();
// 	addLLElement(Stack, 0, new);
// 	addLLElement(Stack, 1, new2);
// 	addLLElement(Stack, 0, new3);
// 	// removeLLElement(Stack, 2);
// 	tmp = Stack->pTopElement;
// 	while (i < Stack->currentElementCount)
// 	{
// 		printf("%d\n", tmp->data);
// 		tmp = tmp->pLink;
// 		i++;
// 	}
// 	printf("%d\n", getLLElement(Stack, 0)->data);
// 	printf("%d\n", (peekLS(Stack))->data);
// 	printf("%d\n", (popLS(Stack))->data);
// 	printf("%d\n", (popLS(Stack))->data);
// 	printf("%d\n", (popLS(Stack))->data);
// 	// printf("%c\n", popLS(Stack->pTopElement->data));
// 	// printf("%c\n", popLS(Stack->pTopElement->data));
// }
