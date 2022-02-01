#include "CatCommand.h"
#include "PasswordProxy.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr)
{

}


int CatCommand::execute(string stringCommand)
{
	string file_name; 
	string optional_append;
	istringstream parse_text(stringCommand);
	parse_text >> file_name;
	parse_text >> optional_append;
	
	cout << "Current contents of the file:" << endl;
	AbstractFile* file_to_modify = file_system_ptr->openFile(file_name);
	if (file_to_modify == nullptr)
	{ 
		cout << "Original File Not Found, Cat function exiting" << endl;
		return static_cast<int>(CatCommandStatus::fileNotFound);
	}

	string filetype = file_to_modify->getName().substr(file_to_modify->getName().size() - static_cast<int>(CatCommandStatus::fileTypeTag));

	if (optional_append == "-a")
	{
		
		vector<char> info_vector = file_to_modify->read(); 
		
		for (unsigned int i = 0; i < info_vector.size(); ++i)
		{
			cout << info_vector[i];
		}
		cout << endl;
		cout << "End of contents of file. To append to the file please type below." << endl;
		cout << "To save and quit, please type ':wq', to quit without saving please type ':q'." << endl;
		
		string temp_line = "";
		vector<char> temp_vector; 
		getline(cin, temp_line);
		while (temp_line != ":wq" && temp_line != ":q")
		{
			for (unsigned int string_character = 0; string_character < temp_line.size(); ++string_character)
			{
				temp_vector.push_back(temp_line[string_character]);
			}

			
			getline(cin, temp_line);

			if (temp_line != ":wq" && temp_line != ":q" && filetype != ".img") {
				temp_vector.push_back('\n');
			}
			
		}

		if (temp_line == ":q")
		{
			temp_vector.clear(); 
			cout << "Cat command existing, data not saved." << endl;
			
			int result = file_system_ptr->closeFile(file_to_modify);
			if (result != static_cast<int>(CatCommandStatus::success))
			{
				return result;
			}
			
			return static_cast<int>(CatCommandStatus::success);
		}
		else if (temp_line == ":wq")
		{
			int append_result = file_to_modify->append(temp_vector);
			if (append_result != static_cast<int>(CatCommandStatus::success))
			{
				cout << "Append operation not supported in file. Cat command returning" << endl;
				
				int result = file_system_ptr->closeFile(file_to_modify);
				if (result != static_cast<int>(CatCommandStatus::success))
				{
					return result;
				}

				int result_one = file_system_ptr->closeFile(file_to_modify);
				if (result_one != static_cast<int>(CatCommandStatus::success))
				{
					return result_one;
				}

				return static_cast<int>(CatCommandStatus::appendUnsuccessful);
			}

			cout << "Additional information appended to file. Cat command returning." << endl;
			temp_vector.clear(); 

			int result = file_system_ptr->closeFile(file_to_modify);
			if (result != static_cast<int>(CatCommandStatus::success))
			{
				return result;
			}

			return static_cast<int>(CatCommandStatus::success);
		}

	}
	else if (optional_append != "-a") 
	{
		cout << "running -a command. To overwrite the file with new content, type in the field below." << endl;
		cout << "Type ':wq' in a new line to save and quit, or ':q' to quit without saving." << endl;

		string temp_line = "";
		vector<char> temp_vector;
		getline(cin, temp_line);
		while (temp_line != ":wq" && temp_line != ":q")
		{
			for (unsigned int string_character = 0; string_character < temp_line.size(); ++string_character)
			{
				temp_vector.push_back(temp_line[string_character]);
			}

			getline(cin, temp_line);
			
			if (temp_line != ":wq" && temp_line != ":q" && filetype != ".img") {
				temp_vector.push_back('\n');
			}

		}

		if (temp_line == ":q")
		{
			temp_vector.clear();
			cout << "Cat command existing, data not saved." << endl;

			int result = file_system_ptr->closeFile(file_to_modify);
			if (result != static_cast<int>(CatCommandStatus::success))
			{
				
				int result = file_system_ptr->closeFile(file_to_modify);
				if (result != static_cast<int>(CatCommandStatus::success))
				{
					return result;
				}

				return result;
			}

			return static_cast<int>(CatCommandStatus::success);
		}
		else if (temp_line == ":wq")
		{
			int result = file_to_modify->write(temp_vector);
			if (result != static_cast<int>(CatCommandStatus::success))
			{
				
				int result = file_system_ptr->closeFile(file_to_modify);
				if (result != static_cast<int>(CatCommandStatus::success))
				{
					return result;
				}

				cout << "Failed to overwrite to file. Cat command returning" << endl;
				return result;
			}

			cout << "New information overwritten to file. Cat command returning." << endl;
			temp_vector.clear();

			int result_two = file_system_ptr->closeFile(file_to_modify);
			if (result_two != static_cast<int>(CatCommandStatus::success))
			{
				return result_two;
			}

			return static_cast<int>(CatCommandStatus::success);
		}

	}
	
	int result = file_system_ptr->closeFile(file_to_modify);
	if (result != static_cast<int>(CatCommandStatus::success))
	{
		return result;
	}

	return static_cast<int>(CatCommandStatus::success);
}


void CatCommand::displayInfo()
{
	cout << "cat creates a file, cat can be invoked with the command: cat <filename>" << endl;
	cout << "or cat <filename> -a to overwrite contents of file." << endl;

}

