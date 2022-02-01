// define methods of SimpleFileSystem class here

#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <set>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int SimpleFileSystem::addFile(std::string fileName, AbstractFile* ptr)
{
	if (files.find(fileName) != files.end()) 
	{
		return static_cast<int>(SimpleFileStatus::alreadyExists);
	}

	if (ptr == nullptr)
	{
		return static_cast<int>(SimpleFileStatus::isANullPointer);
	}

	files.insert(pair<string, AbstractFile*>(fileName, ptr));

	return static_cast<int>(SimpleFileStatus::success);

}

AbstractFile* SimpleFileSystem::openFile(std::string fileName)
{
	if (files.find(fileName) == files.end())
	{
		return nullptr;
	}

	if (files.find(fileName) != files.end() && openFiles.find(files[fileName]) != openFiles.end())
	{
		return nullptr;
	}

	openFiles.insert(files[fileName]);
	return files[fileName];
}

int SimpleFileSystem::closeFile(AbstractFile* toCloseFile)
{
	if (openFiles.find(toCloseFile) == openFiles.end())
	{
		return static_cast<int>(SimpleFileStatus::fileNotOpen);
	}

	openFiles.erase(openFiles.find(toCloseFile));
	return static_cast<int>(SimpleFileStatus::success);
}

int SimpleFileSystem::deleteFile(std::string fileName)
{
	if (files.find(fileName) == files.end())
	{
		return static_cast<int>(SimpleFileStatus::fileNotExist);
	}

	if (files.find(fileName) != files.end() && openFiles.find(files[fileName]) != openFiles.end())
	{
		return static_cast<int>(SimpleFileStatus::alreadyOpen);
	}

	delete files[fileName];
	files.erase(fileName);

	return static_cast<int>(SimpleFileStatus::success);
}

set<string> SimpleFileSystem::getFileNames()
{
	map<string, AbstractFile*>::iterator file_map_ptr = files.begin();
	set<string> to_return_set;

	while (file_map_ptr != files.end())
	{
		to_return_set.insert(file_map_ptr->first);
		++file_map_ptr;
	}

	return to_return_set;
}
