#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct CatCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful,
	fileNotFound,
	appendUnsuccessful,
	fileTypeTag = 4
};

class CatCommand : public AbstractCommand
{
public:
	CatCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
};

