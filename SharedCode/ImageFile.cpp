// definition of ImageFile class here
#include "ImageFile.h"
#include "AbstractFileVisitor.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


ImageFile::ImageFile(std::string newName)
	:size(0), name(newName){
	}

unsigned int ImageFile::getSize()
{
	return static_cast<unsigned int>(contents.size());
}

char ImageFile::getActualSize()
{
	//char to_return = size + '0';
	//return to_return;
	return size;
}

char ImageFile::getActualChar()
{
	char to_return = size + '0';
	return to_return;
}

string ImageFile::getName()
{
	return name;
}
int ImageFile::write(std::vector<char> newVector) 
{
	size = (newVector[newVector.size() - 1]) - '0';


	if ((size*size + 1) != newVector.size()) {
		return static_cast<int>(ImageStatus::mismatchSize);
	}

	contents.clear();

	for (int i=0; i < (size*size); ++i) {
		if (newVector[i] != 'X' && newVector[i] != ' ') {
			size = 0;
			contents.clear();
			return static_cast<int>(ImageStatus::wrongCharacter);
		}
		contents.push_back(newVector[i]);
	}
	return static_cast<int>(ImageStatus::success);
}

int ImageFile::append(std::vector<char> newVector) {
	cout << "Cannot append to an image." << endl;
	return static_cast<int>(ImageStatus::cannotAppend);
}

vector<char> ImageFile::read()
{
	return contents;
	/*
	for (int y = size - 1; y >= static_cast<int>(ImageStatus::startFullIndex); --y) {
		for (int x = static_cast<int>(ImageStatus::startFullIndex); x < size; ++x) {
			int index = y * size + x;
			cout << contents[index];
		}
		cout << endl;
	}
	*/
}

void ImageFile::accept(AbstractFileVisitor* file_visitor)
{
	if (file_visitor != nullptr)
	{
		file_visitor->visit_ImageFile(this);
	}
	
}

AbstractFile* ImageFile::clone(string newFileName)
{
	AbstractFile* new_clone = new ImageFile(newFileName);
	vector<char> temp_contents = contents;
	temp_contents.push_back(getActualChar());
	new_clone->write(temp_contents);
	return new_clone;
}

bool ImageFile::isReadOnly()
{
	return false;
}