//  Define the TextFile class here

#include "TextFile.h"
#include "AbstractFileVisitor.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

TextFile::TextFile(string newName) 
	:name(newName)
{
	
}


int TextFile::write(vector<char> newVector)
{
	contents = newVector;
	return 0;
}

int TextFile::append(vector<char> newVector)
{
	for (int i = 0; i < newVector.size(); ++i)
	{
		contents.push_back(newVector[i]);
	}
	return 0;
}

unsigned int TextFile::getSize()
{
	return static_cast<unsigned int>(contents.size());
}

string TextFile::getName()
{
	return name;
}

vector<char> TextFile::read()
{
	return contents;

}

void TextFile::accept(AbstractFileVisitor* file_visitor)
{
	if (file_visitor != nullptr)
	{
		file_visitor->visit_TextFile(this);
	}
	
}

AbstractFile* TextFile::clone(string newFileName)
{
	AbstractFile* new_clone = new TextFile(newFileName);
	new_clone->write(contents);
	return new_clone; 
}

bool TextFile::isReadOnly()
{
	return false;
}
