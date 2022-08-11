#ifndef _STACK_CALC_
#define _STACK_CALC_

typedef enum PrecedenceType {
	lparen,
	rparen,
	times,
	divide,
	plus,
	minus,
	operand
} Precedence;

typedef struct ExprTokenType { 
	float value;
	Precedence type; 
	} ExprToken;

// void calcExpr(ExprToken *pExprTokens, int tokenCount);
// int pushLSExprToken(LinkedStack* pStack, ExprToken data);
// void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
// int inStackPrecedence(Precedence oper);
// int outStackPrecedence(Precedence oper);
// void printToken(ExprToken element);

#endif