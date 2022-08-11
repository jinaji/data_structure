#include "linkedlist.h"
#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

// 괄호 발견하는대로 노드로 만들고 회수

void	makeNode(char c, LinkedStack *brac)
{
	StackNode	tmp;

	tmp.data = c;
	pushLS(brac, tmp);
}

void	checkMatch(char c, LinkedStack *brac)
{
	char	data = brac->pTopElement->data;

	if (c == ')' && data == '(')
		popLS(brac);
	else if (c == '}' && data == '{')
		popLS(brac);
	else if (c == ']' && data == '[')
		popLS(brac);
	else
	{
		printf("Error\n");
		exit (1);
	}
}

void	checkBracket(char *str, LinkedStack *brac)
{
	int	i = 0;

	brac = createLinkedStack();
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			makeNode(str[i], brac);
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			checkMatch(str[i], brac);
		i++;
	}
	if (!isLinkedStackEmpty(brac))
	{
		printf("Error\n");
		exit (1);
	}
}

int main(int ac, char **av)
{
	LinkedStack	*brac;
	LinkedStack	*ret;
	int	i = 0;

	(void)ac;
	ret = createLinkedStack();
	while (av[i])
	{
		checkBracket(av[i], brac);
		i++;
	}
	printf("ok\n");
}
