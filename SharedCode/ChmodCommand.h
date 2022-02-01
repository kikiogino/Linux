#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct ChmodCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful,
	fileNotFound,
	appendUnsuccessful,
	isReadOnlyAlready,
	isReadWriteAlready,
	fileTypeTag = 4
};

class ChmodCommand : public AbstractCommand
{
public:
	ChmodCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
};

