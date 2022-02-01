#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr)
{

}


int DisplayCommand::execute(string stringCommand)
{
	string file_name;
	string optional_append;
	istringstream parse_text(stringCommand);
	parse_text >> file_name;
	parse_text >> optional_append;

	AbstractFile* file_to_display = file_system_ptr->openFile(file_name);

	if (file_to_display == nullptr)
	{
		cout << "File not found. Display command existing." << endl;
		return static_cast<int>(DisplayCommandStatus::openFileUnsuccessful);
	}

	if (optional_append == "-d")
	{
		vector<char> info_vector = file_to_display->read();

		for (unsigned int i = 0; i < info_vector.size(); ++i)
		{
			cout << info_vector[i];
		}
		cout << endl;

	}
	else if (optional_append != "-d")
	{
		BasicDisplayVisitor new_display_visitor;
		file_to_display->accept(&new_display_visitor);
	}

	int close_result = file_system_ptr->closeFile(file_to_display);
	
	if (close_result != static_cast<int>(DisplayCommandStatus::success))
	{
		return close_result;
	}

	return static_cast<int>(DisplayCommandStatus::success);
}


void DisplayCommand::displayInfo()
{
	cout << "ds displays a file, ds can be invoked with the command: ds <filename> for formatted" << endl;
	cout << "or ds <filename> -d for unformatted" << endl;
}


