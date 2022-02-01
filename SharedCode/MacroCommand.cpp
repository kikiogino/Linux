#include "MacroCommand.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr), abstract_parsing_strategy(nullptr)
{

}

int MacroCommand::execute(string stringCommand)
{
	cout << "Macro Command running in progress" << endl;
	vector<string> command_vector = abstract_parsing_strategy->parse(stringCommand);
	
	for (int i = 0; i < command_vector.size(); ++i)
	{
		int result = order_of_commands[i]->execute(command_vector[i]);

		if (result != static_cast<int>(MacroCommandStatus::success))
		{
			return result;
		}

	}

	cout << "Macro Command completed" << endl;
	return static_cast<int>(MacroCommandStatus::success);
}

void MacroCommand::displayInfo()
{
	cout << "Macro command allows for a series of commands to run at the same time." << endl;

}

void MacroCommand::addCommand(AbstractCommand* newCommand)
{
	order_of_commands.push_back(newCommand);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* newParseStrategy)
{
	abstract_parsing_strategy = newParseStrategy;
}


