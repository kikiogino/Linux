#pragma once
#include "AbstractFile.h"
#include <string>
#include <set>

// declaration of the interface all file systems provide goes here

class AbstractFileSystem 
{
public:
	virtual int addFile(std::string fileName, AbstractFile* ptr) = 0;
	virtual int deleteFile(std::string fileName) = 0;
	virtual AbstractFile* openFile(std::string fileName) = 0;
	virtual int closeFile(AbstractFile * toCloseFile) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};