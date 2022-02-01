#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct CopyCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful,
	openFileUnsuccessful,
	fileTypeTag = 4
};

class CopyCommand : public AbstractCommand
{
public:
	CopyCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
};