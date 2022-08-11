#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

typedef struct ArrayStackNodeType
{
	int data;
} ArrayStackNode;

typedef struct ArrayStackType
{
	int maxElementCount;		// 최대 원소 갯수
	int currentElementCount;	// 현재 원소 갯수
	ArrayStackNode *pElement;
	ArrayStackNode	pTopElement;	// 원소 저장을 위한 일차원 배열
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
void deleteArrayStack(ArrayStack* pStack); // 하나 
int isArrayStackFull(ArrayStack* pStack);
int addALElement(ArrayStack* pStack, int position, ArrayStackNode element);
int removeALElement(ArrayStack* pStack, int position); // 하나 
ArrayStackNode* getALElement(ArrayStack* pStack, int position);
void displayArrayStack(ArrayStack* pStack);
void clearArrayStack(ArrayStack* pStack); // 다 지우기
int getArrayStackLength(ArrayStack* pStack);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif