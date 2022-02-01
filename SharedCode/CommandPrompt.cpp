#include "CommandPrompt.h"
#include <map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

CommandPrompt::CommandPrompt()
	:abstract_file_system_ptr(nullptr), abstract_file_factory_ptr(nullptr)
{

}

void CommandPrompt::setFileSystem(AbstractFileSystem* file_system_ptr)
{
	abstract_file_system_ptr = file_system_ptr;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* file_factory_ptr)
{
	abstract_file_factory_ptr = file_factory_ptr;
}

int CommandPrompt::addCommand(string new_string, AbstractCommand* abstract_command_ptr)
{
	bool is_unsuccessful_insert = command_prompt_map.insert(make_pair(new_string, abstract_command_ptr)).second == false;

	if (is_unsuccessful_insert)
	{
		return static_cast<int>(CommandPromptStatus::addCommandUnsuccessfulKeyExist);
	}

	return static_cast<int>(CommandPromptStatus::success);
}

void CommandPrompt::listCommands()
{
	map<string, AbstractCommand*>::iterator map_iterator = command_prompt_map.begin();

	while (map_iterator != command_prompt_map.end())
	{
		cout << map_iterator->first << endl;
		++map_iterator;
	}

}

string CommandPrompt::prompt()
{
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$ ";

	string resultString; 
	getline(cin >> ws, resultString);

	return resultString;

}

int CommandPrompt::run()
{
	string promptMessage = "";
	while (1) {
		
		promptMessage = "";
		promptMessage = prompt();

		if (promptMessage == "q")
		{
			cout << "User has quit the program" << endl;
			return static_cast<int>(CommandPromptStatus::userQuit);
		}

		else if (promptMessage == "help")
		{
			listCommands();
		}

		else
		{
			// if the command is one word only
			if (promptMessage.find(' ') == promptMessage.npos)
			{
				//command is found
				if (command_prompt_map.find(promptMessage) != command_prompt_map.end())
				{
					int run_result = command_prompt_map[promptMessage]->execute("");

					if (run_result != static_cast<int>(CommandPromptStatus::success))
					{
						cout << "Command failed. Please try again." << endl;
					}

				}
				else
				{
					cout << "Command not found. Please try again." << endl;
				}

			}
			else //two words
			{
				istringstream input_stream(promptMessage);
				string first_word;
				input_stream >> first_word;

				// if first word is help
				if (first_word == "help")
				{
					string second_word;
					input_stream >> second_word;

					if (command_prompt_map.find(second_word) != command_prompt_map.end())
					{
						command_prompt_map[second_word]->displayInfo();
					}
					else
					{
						cout << "Help command not found. Please try again." << endl;
					}

				}
				else //first word is NOT help
				{
					string newMessage = promptMessage.substr(first_word.size() + 1);
					if (command_prompt_map.find(first_word) != command_prompt_map.end())
					{
						
						int second_run_result = command_prompt_map[first_word]->execute(newMessage);
						if (second_run_result != static_cast<int>(CommandPromptStatus::success))
						{
							cout << "Command failed to run. Please try again." << endl;
						}

					}
					else
					{
						cout << "First word command not found. Please try again." << endl;
					}

				}
			}
		}
	}
	
	return static_cast<int>(CommandPromptStatus::success);
	
}