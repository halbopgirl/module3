#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(istringstream& stream)
{
	char paren;
	int value;

	stream >> ws;
			if (isdigit(stream.peek()))
			{
				stream >> value;
				Expression* literal = new Literal(value);
				return literal;
			}
			if (stream.peek() == '(')
			{
				stream >> paren;
				cout << "new parenthese found\n";
				return SubExpression::parse(stream);
			}
			else
				return new Variable(parseName(stream));
		
	
	return 0;
}