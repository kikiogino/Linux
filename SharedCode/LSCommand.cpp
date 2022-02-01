#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include "AbstractFile.h" // might cause circular inclusion error
#include <iostream>
#include <string>
#include <iterator>
#include <iomanip>
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* newFileSystemPtr)
	:file_system_ptr(newFileSystemPtr)
{

}


int LSCommand::execute(string stringCommand)
{
	set<string> to_display_ptr = file_system_ptr->getFileNames();
	unsigned int longest_piece = static_cast<int>(LSCommandStatus::longestPieceStartValue);

	if (stringCommand == "")
	{
		unsigned int item_number = 0;
		set<string>::iterator set_display_iterator = to_display_ptr.begin();

		while (set_display_iterator != to_display_ptr.end())
		{
			cout << left << setw(longest_piece) << *set_display_iterator;
			++set_display_iterator;
			++item_number;
			if (item_number % 2 == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
	}

	else if (stringCommand == "-m")
	{
		set<string>::iterator set_display_iterator = to_display_ptr.begin();
		MetadataDisplayVisitor display_visitor; 
		
		while (set_display_iterator != to_display_ptr.end())
		{
			AbstractFile* to_open_file = file_system_ptr->openFile(*set_display_iterator);
			to_open_file->accept(&display_visitor);
			int close_result = file_system_ptr->closeFile(to_open_file);

			if (close_result != static_cast<int>(LSCommandStatus::success))
			{
				cout << "Close file unsuccessful, LS Command exiting" << endl;
				return close_result;
			}

			++set_display_iterator;
		}
	}

	return static_cast<int>(LSCommandStatus::success);
}


void LSCommand::displayInfo()
{
	cout << "ls displays a list of the files in the directory, ls can be invoked with the command: 'ls' or 'ls -m'." << endl;
}

