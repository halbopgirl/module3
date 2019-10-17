#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"


SymbolTable symbolTable;

void parseAssignments(istringstream& token); 

int main() {
	ifstream file("testfile.txt");
	if (file) {
		Expression* expression;
		char paren, comma;
		string line;
		while (getline(file, line, ';')) {
			if (line.empty()) {
				getline(file, line);
			}
			istringstream token(line);
			cout << line << endl;
			token >> paren;
			expression = SubExpression::parse(token);
			token >> comma;
			parseAssignments(token);
			cout << "Value = " << expression->evaluate() << "\n";
		}
		file.close();
	} else {
		Expression* expression;
		char paren, comma;
		string line;
		getline(cin, line);
		istringstream token(line);
		cout << "File not found.\nEnter expression: ";
		token >> paren;
		expression = SubExpression::parse(token);
		token >> comma;
		parseAssignments(token);
		cout << "Value = " << expression->evaluate() << endl;
	}
	return 0;
}

void parseAssignments(istringstream& token) {
	char assignop, delimiter; 
	string variable;
	int value;
	do {
		variable = parseName(token);
		token >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',' && token);
}



