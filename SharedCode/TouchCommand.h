#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum struct TouchCommandStatus
{
	success,
	createUnsuccessful,
	addUnsuccessful
};

class TouchCommand : public AbstractCommand
{
public:
	TouchCommand(AbstractFileSystem* newFileSystemPtr, AbstractFileFactory* newFileFactoryPtr);
	int execute(std::string stringCommand) override;
	void displayInfo() override;
private:
	AbstractFileSystem* file_system_ptr;
	AbstractFileFactory* file_factory_ptr;
};