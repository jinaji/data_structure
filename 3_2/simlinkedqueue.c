#include "simlinkedqueue.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isLinkedCustomerFull(LinkedCustomer* pDeque)
{
	return (FALSE);
}

int isLinkedCustomerEmpty(LinkedCustomer* pDeque)
{
	if (!pDeque)
		return (FALSE);
	return (pDeque->currentElementCount == 0);
}

LinkedCustomer* createLinkedCustomer()
{
	LinkedCustomer	*tmp;

	tmp = (LinkedCustomer *)malloc(sizeof(LinkedCustomer));
	if (!tmp)
		return (FALSE);
	memset(tmp, 0, (sizeof(LinkedCustomer)));
	return (tmp);
}

int insertFrontLD(LinkedCustomer* pDeque, SimCustomer element)
{
	SimCustomer	*tmp;

	if (!pDeque)
		return (FALSE);
	tmp = (SimCustomer *)malloc(sizeof(SimCustomer));
	if (!tmp)
		return (FALSE);
	*tmp = element;
	if (pDeque->currentElementCount == 0)
	{
		pDeque->pFrontNode = tmp;
		pDeque->pRearNode = tmp;
	}
	else
	{
		tmp->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = tmp;
		pDeque->pFrontNode = tmp;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedCustomer* pDeque, SimCustomer element)
{
	SimCustomer	*tmp;

	if (!pDeque)
		return (FALSE);
	tmp = (SimCustomer *)malloc(sizeof(SimCustomer));
	if (!tmp)
		return (FALSE);
	*tmp = element;
	if (isLinkedCustomerEmpty(pDeque))
	{
		pDeque->pFrontNode = tmp;
		pDeque->pRearNode = tmp;
	}
	else
	{
		pDeque->pRearNode->pRLink = tmp;
		tmp->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = tmp;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

SimCustomer* deleteFrontLD(LinkedCustomer* pDeque)
{
	SimCustomer	*front;

	if (!pDeque || isLinkedCustomerEmpty(pDeque))
		return (FALSE);
	if (pDeque->currentElementCount == 1)
	{
		front = pDeque->pFrontNode;
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
	}
	else
	{
		front = pDeque->pFrontNode;
		front->pRLink->pLLink = 0;
		pDeque->pFrontNode = front->pRLink;
	}
	pDeque->currentElementCount--;
	return (front);
}

SimCustomer* deleteRearLD(LinkedCustomer* pDeque)
{
	SimCustomer	*rear;

	if (!pDeque || isLinkedCustomerEmpty(pDeque))
		return (FALSE);
	if (pDeque->currentElementCount == 1)
	{
		rear = pDeque->pFrontNode;
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
	}
	else
	{
		rear = pDeque->pRearNode;
		rear->pLLink->pRLink = 0;
		pDeque->pRearNode = rear->pLLink;
	}
	pDeque->currentElementCount--;
	return (rear);
}

SimCustomer* peekFrontLD(LinkedCustomer* pDeque)
{
	return (pDeque->pFrontNode);
}

SimCustomer* peekRearLD(LinkedCustomer* pDeque)
{
	return (pDeque->pRearNode);
}

void deleteLinkedCustomer(LinkedCustomer* pDeque)
{
	while (pDeque->pFrontNode)
		free(deleteFrontLD(pDeque));
	memset(pDeque, 0, sizeof(LinkedCustomer));
	free (pDeque);
}

void	clearLinkdeDeque(LinkedCustomer* pDeque)
{
	while (!isLinkedCustomerEmpty(pDeque))
		free(deleteFrontLD(pDeque));
}

////////////////////////////////////////////////////////////////////////////////////////

void	insertCustomer(int arrivalTime, int processTime, LinkedCustomer *pDeque)
{
	SimCustomer	tmp;

	if (!pDeque || isLinkedCustomerFull(pDeque))
		return ;
	tmp.status = arrival;
	tmp.arrivalTime = arrivalTime;
	tmp.serviceTime = processTime;
	tmp.endTime = 0;
	tmp.pLLink = 0;
	tmp.pRLink = 0;
	tmp.startTime = 0;
	insertFrontLD(pDeque, tmp);
}

void	processArrival(int currentTime, LinkedCustomer *pArrivalDeque, LinkedCustomer *pWaitDeque)
{
	insertCustomer(currentTime, pArrivalDeque->pRearNode->serviceTime, pWaitDeque);
	deleteRearLD(pArrivalDeque);
}

SimCustomer	*processServiceNodeStart(int currentTime, LinkedCustomer *pWaitDeque)
{
	if (!pWaitDeque->pRearNode)
		return (0);
	pWaitDeque->pRearNode->status = start;
	pWaitDeque->pRearNode->startTime = currentTime;
	pWaitDeque->pRearNode->endTime = currentTime + pWaitDeque->pRearNode->serviceTime;
	return (deleteRearLD(pWaitDeque));
}

SimCustomer	*processServiceNodeEnd(int currentTime, SimCustomer *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	(*pServiceUserCount)--;
	pServiceNode->status = end;
	*pTotalWaitTime += pServiceNode->startTime - pServiceNode->arrivalTime;
	return (pServiceNode);
}

void	printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("now is %d\n", currentTime);
	printf("arrival time is %d, service time is %d\n", customer.arrivalTime, customer.serviceTime);
}

void	printWaitDequeStatus(int currentTime, LinkedCustomer *pWaitDeque)
{
	if (!pWaitDeque->pRearNode)
	{
		printf ("now is %d\n", currentTime);
		printf("no one is waiting\n");
		return ;
	}
	printf ("now is %d\n", currentTime);
	printf("%d is waiting %d\n", pWaitDeque->currentElementCount, currentTime - pWaitDeque->pRearNode->arrivalTime);
}

void	printReport(LinkedCustomer *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	SimCustomer	*tmp;
	int	i = 1;

	tmp = pWaitQueue->pRearNode;
	while (tmp->pLLink)
	{
		printf ("%d is on service\n", serviceUserCount);
		printf ("waiting number %d\n", i);
		printf ("arrival time: %d\n", tmp->arrivalTime);
		printf ("service time: %d\n", tmp->serviceTime);
		i++;
		tmp = tmp->pLLink;
	}
	printf ("waitinglist : %d\n", i);
	printf ("total waittime is %d\n", totalWaitTime);
}

int main()
{
	LinkedCustomer	*pArrivalDeque;
	LinkedCustomer	*pWaitDeque;
	int				pServiceUserCount = 0;
	int				pTotalWaitTime = 0;
	SimCustomer		*tmp;

	pArrivalDeque = createLinkedCustomer();
	pWaitDeque = createLinkedCustomer();
	insertCustomer(0, 3, pArrivalDeque);
	insertCustomer(2, 2, pArrivalDeque);
	insertCustomer(4, 1, pArrivalDeque);
	insertCustomer(6, 1, pArrivalDeque);
	insertCustomer(8, 3, pArrivalDeque);
	for (int currentTime = 0; ; currentTime++)
	{
		if (pArrivalDeque->pRearNode && (currentTime == pArrivalDeque->pRearNode->arrivalTime))
			processArrival(currentTime, pArrivalDeque, pWaitDeque);
		if (pServiceUserCount && tmp->endTime == currentTime)
			free(processServiceNodeEnd(currentTime, tmp, &pServiceUserCount, &pTotalWaitTime));
		if (pServiceUserCount == 0)
		{
			tmp = processServiceNodeStart(currentTime, pWaitDeque);
			pServiceUserCount++;
		}
		if (!tmp)
			break ;
	}
	printf("wait %d\n", pTotalWaitTime);
}
