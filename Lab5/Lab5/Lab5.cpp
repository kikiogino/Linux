// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/AbstractFileVisitor.h"
#include "../../SharedCode/AbstractParsingStrategy.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/ChmodCommand.h"
#include "../../SharedCode/ChmodProxy.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/EditAndDisplayParsingStrategy.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/TouchCommand.h"


int main()
{
	// setting up file system, factory, command prompt
	AbstractFileSystem* file_system = new SimpleFileSystem();
	AbstractFileFactory* file_factory = new SimpleFileFactory();
	CommandPrompt cmd_prompt;
	cmd_prompt.setFileSystem(file_system);
	cmd_prompt.setFileFactory(file_factory);
	
	// setting up all the commands
	AbstractCommand* touch_command = new TouchCommand(file_system, file_factory);
	cmd_prompt.addCommand("touch", touch_command);

	AbstractCommand* ls_command = new LSCommand(file_system);
	cmd_prompt.addCommand("ls", ls_command);

	AbstractCommand* remove_command = new RemoveCommand(file_system);
	cmd_prompt.addCommand("rm", remove_command);

	AbstractCommand* cat_command = new CatCommand(file_system);
	cmd_prompt.addCommand("cat", cat_command);
	
	AbstractCommand* display_command = new DisplayCommand(file_system);
	cmd_prompt.addCommand("ds", display_command);

	AbstractCommand* copy_command = new CopyCommand(file_system);
	cmd_prompt.addCommand("cp", copy_command);

	// extra credit
	AbstractCommand* chmod_command = new ChmodCommand(file_system);
	cmd_prompt.addCommand("chmod", chmod_command);

	// setting up all the MacroCommands
	AbstractParsingStrategy* rename_parse = new RenameParsingStrategy();
	MacroCommand * rename_macro = new MacroCommand(file_system);
	rename_macro->setParseStrategy(rename_parse);
	rename_macro->addCommand(copy_command);
	rename_macro->addCommand(remove_command);
	cmd_prompt.addCommand("rn", rename_macro);

	AbstractParsingStrategy* edit_and_display_parse = new EditAndDisplayParsingStrategy();
	MacroCommand* edit_and_display_macro = new MacroCommand(file_system);
	edit_and_display_macro->setParseStrategy(edit_and_display_parse);
	edit_and_display_macro->addCommand(cat_command);
	edit_and_display_macro->addCommand(display_command);
	cmd_prompt.addCommand("ed", edit_and_display_macro);

	cmd_prompt.run();
}


