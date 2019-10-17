#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "equals.h"
#include "negate.h"
#include "and.h"
#include "or.h"
#include "conditional.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}


Expression* SubExpression::parse(istringstream& token)
{
	Expression* left;
	Expression* right;
	Expression* condition;
	char operation, paren, cond;
	
	left = Operand::parse(token);
	token >> operation;

	if (operation == '!') {
		token >> paren;
		return new Negate(left, NULL);
	}

	right = Operand::parse(token);

	if (operation == ':') {
		token >> cond;
		condition = Operand::parse(token);
		token >> paren;
		return new Conditional(left, right, condition);
	}

	switch (operation)
	{
	case '+':
		//right = Operand::parse(token);
		token >> paren;
		return new Plus(left, right);
	case '-':
		//right = Operand::parse(token);
		token >> paren;
		return new Minus(left, right);
	case '*':
		//right = Operand::parse(token);
		token >> paren;
		return new Times(left, right);
	case '/':
		//right = Operand::parse(token);
		token >> paren;
		return new Divide(left, right);
	case '>':
		//right = Operand::parse(token);
		token >> paren;
		return new GreaterThan(left, right);
	case '<':
		//right = Operand::parse(token);
		token >> paren;
		return new LessThan(left, right);
	case '=':
		//right = Operand::parse(token);
		token >> paren;
		return new Equals(left, right);
	case '|':
		//right = Operand::parse(token);
		token >> paren;
		return new Or(left, right);
	case '&':
		//right = Operand::parse(token);
		token >> paren;
		return new And(left, right);
	}
	return 0;
}

