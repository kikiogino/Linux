// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

AbstractFile* SimpleFileFactory::createFile(std::string fileName)
{
	string extension;

	for (int i = static_cast<int>(fileName.size()) - 4; i < static_cast<int>(fileName.size()); ++i)
	{
		extension = extension + fileName[i];
	}

	if (extension == ".txt")
	{
		AbstractFile* newTextFile = new TextFile(fileName);
		return newTextFile;
	}

	else if (extension == ".img")
	{
		AbstractFile* newImageFile = new ImageFile(fileName);
		return newImageFile;
	}

	return nullptr;
}
