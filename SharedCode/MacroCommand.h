#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

enum struct MacroCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful,
	exitWithoutSaving
};

class MacroCommand : public AbstractCommand
{
public:
	MacroCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
	void addCommand(AbstractCommand* newCommand);
	void setParseStrategy(AbstractParsingStrategy* newParseStrategy);

private:
	AbstractFileSystem* file_system_ptr;
	std::vector<AbstractCommand*> order_of_commands;
	AbstractParsingStrategy* abstract_parsing_strategy;
};