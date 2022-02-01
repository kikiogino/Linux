#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* newFileSystemPtr, AbstractFileFactory* newFileFactoryPtr)
	:file_system_ptr(newFileSystemPtr), file_factory_ptr(newFileFactoryPtr)
{
	
}


int TouchCommand::execute(string stringCommand)
{
	if (stringCommand.find("-p") != stringCommand.npos)
	{
		string actual_file_name;
		istringstream parse_text(stringCommand);
		parse_text >> actual_file_name; 
		
		AbstractFile* new_password_file = file_factory_ptr->createFile(actual_file_name);

		if (new_password_file != nullptr)
		{
			
			cout << "What is the password?" << endl;
			string password;
			cin >> password;

			PasswordProxy* new_file_proxy = new PasswordProxy(new_password_file, password);

			int result = file_system_ptr->addFile(actual_file_name, new_file_proxy);
			if (result != static_cast<int>(TouchCommandStatus::success))
			{
				cout << "Password Protected File was created successfully, but was not added successfully" << endl;
				delete new_file_proxy;
				return static_cast<int>(TouchCommandStatus::addUnsuccessful);
			}

		}
		else
		{
			cout << "File for Password Protection was not created successfully." << endl;
			return static_cast<int>(TouchCommandStatus::createUnsuccessful);
		}
		

	}
	else {
		AbstractFile* new_file = file_factory_ptr->createFile(stringCommand);

		if (new_file != nullptr)
		{

			int result = file_system_ptr->addFile(stringCommand, new_file);
			if (result != static_cast<int>(TouchCommandStatus::success))
			{
				cout << "File was created successfully, but was not added successfully" << endl;
				delete new_file;
				return static_cast<int>(TouchCommandStatus::addUnsuccessful);
			}

		}
		else
		{
			cout << "File was not created successfully." << endl;
			return static_cast<int>(TouchCommandStatus::createUnsuccessful);
		}
	}
	
	cout << "File created successfully." << endl;
	return static_cast<int>(TouchCommandStatus::success);
}


void TouchCommand::displayInfo()
{
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

