#include "ChmodCommand.h"
#include "ChmodProxy.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ChmodCommand::ChmodCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr)
{

}


int ChmodCommand::execute(string stringCommand)
{
	string file_name;
	string optional_append;
	istringstream parse_text(stringCommand);
	parse_text >> file_name;
	parse_text >> optional_append;

	AbstractFile* file_to_modify = file_system_ptr->openFile(file_name);

	if (file_to_modify == nullptr)
	{
		cout << "Original File Not Found, Chmod function exiting" << endl;
		return static_cast<int>(ChmodCommandStatus::fileNotFound);
	}
	//read only
	if (optional_append == "-")
	{
		if (file_to_modify->isReadOnly() == false)
		{
			
			AbstractFile* cloned_file = file_to_modify->clone(file_to_modify->getName());

			AbstractFile* new_chmod_proxy = new ChmodProxy(cloned_file);

			int close_result_one = file_system_ptr->closeFile(file_to_modify);
			if (close_result_one != static_cast<int>(ChmodCommandStatus::success))
			{
				return close_result_one;
			}
			
			int delete_result_one = file_system_ptr->deleteFile(file_to_modify->getName());
			if (delete_result_one != static_cast<int>(ChmodCommandStatus::success))
			{
				return delete_result_one;
			}

			int add_result_one = file_system_ptr->addFile(new_chmod_proxy->getName(), new_chmod_proxy);
			if (add_result_one != static_cast<int>(ChmodCommandStatus::success))
			{
				return add_result_one;
			}

			cout << "File was set to read-only sucessfully" << endl;
			return static_cast<int>(ChmodCommandStatus::success);
		}
		else
		{
			cout << "File was already in read-only" << endl;
			
			return static_cast<int>(ChmodCommandStatus::isReadOnlyAlready);
		}
		

	}
	// back to read write access
	else if (optional_append == "+")
	{
		if (file_to_modify->isReadOnly() == true)
		{
			ChmodProxy* original_proxy = (ChmodProxy*)file_to_modify;

			AbstractFile* original_file_to_restore = original_proxy->getFile()->clone(original_proxy->getName());

			int close_result_two = file_system_ptr->closeFile(file_to_modify);
			if (close_result_two != static_cast<int>(ChmodCommandStatus::success))
			{
				return close_result_two;
			}

			int delete_result_two = file_system_ptr->deleteFile(file_to_modify->getName());
			if (delete_result_two != static_cast<int>(ChmodCommandStatus::success))
			{
				return delete_result_two;
			}

			int add_result_two = file_system_ptr->addFile(original_file_to_restore->getName(), original_file_to_restore);
			if (add_result_two != static_cast<int>(ChmodCommandStatus::success))
			{
				return add_result_two;
			}

			cout << "File set to read-write access successfully" << endl;
			return static_cast<int>(ChmodCommandStatus::success);
		}
		else
		{
			cout << "File was already in read-write access mode" << endl;
			return static_cast<int>(ChmodCommandStatus::isReadWriteAlready);
		}

	}

	return static_cast<int>(ChmodCommandStatus::success);
}


void ChmodCommand::displayInfo()
{
	cout << "chmod changes the read-write privileges of a file." << endl;
	cout << "chmod can be invoked with the command : chmod <filename> - for read-only access" << endl;
	cout << "or chmod <filename> + for read-write access" << endl;

}

