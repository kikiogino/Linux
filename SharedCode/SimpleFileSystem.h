#pragma once
// declaration of SimpleFileSystem class goes here
#include <string>
#include <map>
#include <set>
#include "AbstractFileSystem.h"

enum struct SimpleFileStatus
{
	success,
	alreadyExists,
	isANullPointer,
	fileNotOpen,
	fileNotExist,
	alreadyOpen,
	unknownExtension
};

class SimpleFileSystem : public AbstractFileSystem 
{
public:
	int addFile(std::string fileName, AbstractFile* ptr) override;
	int deleteFile(std::string fileName) override;
	AbstractFile* openFile(std::string fileName) override;
	int closeFile(AbstractFile * toCloseFile) override;
	std::set<std::string> getFileNames() override;

private:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;

};