#ifndef SIMLINKEDQUEUE_H
# define SIMLINKEDQUEUE_H

# define TRUE		1
# define FALSE		0

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착시간
	int serviceTime;	// 서비스 시간
	int startTime;		// 시작 시간
	int endTime;		// 종료 시각: 시시작작시시각+서서비비스스시시각  
	struct SimCustomerType	*pRLink;
	struct SimCustomerType	*pLLink;
} SimCustomer;

typedef struct LinkedCustomerType
{
	int currentElementCount;
	SimCustomer* pFrontNode;
	SimCustomer* pRearNode;
} LinkedCustomer;

void	insertCustomer(int arrivalTime, int processTime, LinkedCustomer *pDeque);
void	processArrival(int currentTime, LinkedCustomer *pArrivalDeque, LinkedCustomer *pWaitDeque);
SimCustomer	*processServiceNodeStart(int currentTime, LinkedCustomer *pWaitDeque);
SimCustomer	*processServiceNodeEnd(int currentTime, SimCustomer *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void	printSimCustomer(int currentTime, SimCustomer customer);
void	printWaitDequeStatus(int currentTime, LinkedCustomer *pWaitDeque);
void	printReport(LinkedCustomer *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif
