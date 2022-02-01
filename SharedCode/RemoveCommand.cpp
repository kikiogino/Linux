#include "RemoveCommand.h"
#include <iostream>
#include <string>
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr)
{

}

int RemoveCommand::execute(string stringCommand)
{
	int result = file_system_ptr->deleteFile(stringCommand);
	if (result != static_cast<int>(RemoveCommandStatus::success))
	{
		return static_cast<int>(RemoveCommandStatus::removeUnsuccessful);
	}

	cout << "Remove successful" << endl;
	return static_cast<int>(RemoveCommandStatus::success);
}


void RemoveCommand::displayInfo()
{
	cout << "rm removes a file, rm can be invoked with the command: rm <filename>" << endl;
}

