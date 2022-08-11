#include "linkedlist.h"
#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

int	checkOper(char c, LinkedStack *ret)
{
	StackNode	tmp;
	int			temp1;
	int			temp2;
	int			res = 0;

	tmp.data = c - 48;
	if (c == '+' && ret->currentElementCount >= 2)
	{
		temp2 = popLS(ret)->data;
		temp1 = popLS(ret)->data;
		res = (temp2 + temp1);
		tmp.data = res;
	}
	else if (c == '-' && ret->currentElementCount >= 2)
	{
		temp2 = popLS(ret)->data;
		temp1 = popLS(ret)->data;
		res = (temp2 - temp1);
		tmp.data = res;
	}
	else if (c == '*' && ret->currentElementCount >= 2)
	{
		temp2 = popLS(ret)->data;
		temp1 = popLS(ret)->data;
		res = (temp2 * temp1);
		tmp.data = res;
	}
	else if (c == '/' && ret->currentElementCount >= 2)
	{
		temp2 = popLS(ret)->data;
		temp1 = popLS(ret)->data;
		res = (temp2 / temp1);
		tmp.data = res;
	}
	pushLS(ret, tmp);
	return (TRUE);
}

int main(int ac, char **av)
{
	LinkedStack	*ret;
	int	i = 0;

	if (ac != 2)
		exit (1);
	ret = createLinkedStack();
	while (av[1][i])
	{
		checkOper(av[1][i], ret);
		i++;
	}
	printf("%d\n", ret->pTopElement->data);
}
