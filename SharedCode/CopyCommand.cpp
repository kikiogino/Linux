#include "CopyCommand.h"
#include "PasswordProxy.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr)
{

}


int CopyCommand::execute(string stringCommand)
{
	string original_file_name;
	string new_copy_file_name;
	istringstream parse_text(stringCommand);
	parse_text >> original_file_name;
	parse_text >> new_copy_file_name;

	string file_extension = original_file_name.substr(original_file_name.size() - static_cast<int>(CopyCommandStatus::fileTypeTag));

	new_copy_file_name += file_extension;

	AbstractFile* original_file_ptr = file_system_ptr->openFile(original_file_name);
	
	if (original_file_ptr == nullptr)
	{
		cout << "File not found - exiting copy command" << endl;
		return static_cast<int>(CopyCommandStatus::openFileUnsuccessful);
	}

	AbstractFile* clone_file_ptr = original_file_ptr->clone(new_copy_file_name);
	int close_result = file_system_ptr->closeFile(original_file_ptr);

	if (close_result != static_cast<int>(CopyCommandStatus::success))
	{
		return close_result;
	}

	int add_result = file_system_ptr->addFile(clone_file_ptr->getName(), clone_file_ptr);

	if (add_result != static_cast<int>(CopyCommandStatus::success))
	{
		return add_result;
	}

	cout << "Copy successful" << endl;
	return static_cast<int>(CopyCommandStatus::success);
}


void CopyCommand::displayInfo()
{
	cout << "cp copies a file, cp can be invoked with the command: touch <file_to_copy> <new_name_with_no_extension>" << endl;
}

