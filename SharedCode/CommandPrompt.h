#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <string>

enum struct CommandPromptStatus
{
	success,
	addCommandUnsuccessfulKeyExist,
	userQuit,
};



class CommandPrompt
{
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem* file_system_ptr);
	void setFileFactory(AbstractFileFactory* file_factory_ptr);
	int addCommand(std::string new_string, AbstractCommand* abstract_command_ptr);
	int run();
	
protected:
	void listCommands();
	std::string prompt();

private:
	std::map<std::string, AbstractCommand*> command_prompt_map;
	AbstractFileSystem* abstract_file_system_ptr;
	AbstractFileFactory* abstract_file_factory_ptr;
};
