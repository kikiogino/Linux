#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct DisplayCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful,
	openFileUnsuccessful
};

class DisplayCommand : public AbstractCommand
{
public:
	DisplayCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
};