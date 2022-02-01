#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct RemoveCommandStatus
{
	success,
	removeUnsuccessful
};

class RemoveCommand : public AbstractCommand
{
public:
	RemoveCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
};


