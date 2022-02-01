#include "RenameParsingStrategy.h"
#include "MacroCommand.h"
#include <sstream>
#include <string>
using namespace std;

vector<string> RenameParsingStrategy::parse(string stringToParse)
{
	string original_file;
	string new_file;
	istringstream parse_stream(stringToParse);
	
	parse_stream >> original_file;
	parse_stream >> new_file; 

	vector<string> to_return_vector;
	string copy_string = original_file + " " + new_file;
	to_return_vector.push_back(copy_string);
	to_return_vector.push_back(original_file);

	return to_return_vector;
}