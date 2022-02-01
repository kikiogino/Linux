#include "EditAndDisplayParsingStrategy.h"
#include "MacroCommand.h"
#include <sstream>
#include <string>
using namespace std;

vector<string> EditAndDisplayParsingStrategy::parse(string stringToParse)
{

	vector<string> to_return_vector;
	to_return_vector.push_back(stringToParse);
	to_return_vector.push_back(stringToParse);

	return to_return_vector;
}