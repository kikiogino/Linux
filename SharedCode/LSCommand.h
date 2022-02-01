#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct LSCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful,
	longestPieceStartValue = 20
};

class LSCommand : public AbstractCommand
{
public:
	LSCommand(AbstractFileSystem* newFileSystemPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
};