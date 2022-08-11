#include "doublylist.h"

typedef struct ListNodeType
{
    int coef;
	int degree; // 걍 링크드리스트 헤더에서 data만 요것들로 바꿨어염
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	
	ListNode headerNode;		
} LinkedList;

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
    int ret = FALSE, i = 0;

    ListNode node = {0,};
    node.coef = coef;
    node.degree = degree;

    if (pList != NULL)
    {
        int length = getLinkedListLength(pList);
        ret = addLLElement(pList, length, node);
    }
    return (ret); // 이건 pdf 에 있는 함수 긁어왔어여
}

int getRetNode(LinkedList *ret, LinkedList *list1, LinkedList *list2)
{
    ListNode    *node1;
    ListNode    *node2;
    ListNode    *tmp;
    int         pos = 0; // 포지션

    node1 = list1->headerNode.pLink;
    node2 = list2->headerNode.pLink;
    while (node1 && node2)
    {
        if (node1->degree > node2->degree) // A degree 가 더 클 때
            addLLElement(ret, pos, node1);
        else if (node1->degree == node2->degree) // 같을 때 새로운 노드 만들어서 coef 합 넣어줌!!
        {
            tmp = (ListNode *)malloc(sizeof(Listnode));
            if (!tmp)
                return (FALSE);
            tmp->coef = node1->coef + node2->coef;
            tmp->degree = node1->degree;
            addLLElement(ret, pos, tmp);
        }
        else if (node1->degree < node2->degree) // B degree 가 더 클 때
            addLLElement(ret, pos, node2);
        node1 = node1->pLink;
        node2 = node2->pLink;
        pos++; // 이렇게 하는 이유 ... pdf에서 경우 나눠서 하기도 했구 계속 비교하면서 degree 큰 순서대로 넣어야 될 것 같아서 if 조건 저렇게 잡앗어여
    }
    while (node1 || node2) // 나머지 
    {
        if (node1)
        {
            addLLElement(ret, pos, node1);
            node1 = node1->pLink;
        }
        else if (node2)
        {
            addLLElement(ret, pos, node2);
            node2 = node2->pLink;
        }
        pos++;
    }
}

// 대충 이런 식으로 생각해서 짜봤었는데 ?? 지금 다시 보니까 addLLElement 세번째 인자 형식이 안 맞는 것 가타여
// 포인터 달아주면 될 것 같기도 ??? ... 아닐지도