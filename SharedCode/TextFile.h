#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile: public AbstractFile
{
public: 
	TextFile(std::string newName);
	std::vector<char> read() override;
	int write(std::vector<char> newVector) override;
	int append(std::vector<char> newVector) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* file_visitor) override;
	AbstractFile* clone(std::string newFileName) override;
	bool isReadOnly() override; 

private:
	std::vector<char> contents;
	std::string name;

};