#include <cctype> 
#include <string> 
#include <sstream>
using namespace std;

#include "parse.h"

string parseName(istringstream& token)
{
	char alnum;
	string name = "";

	token >> ws;

	while (isalnum(token.peek()))
	{
		token >> alnum;
		name += alnum;
	}
	return name;
}