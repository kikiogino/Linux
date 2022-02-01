#pragma once
// Image file class declaration here
#include "AbstractFile.h"


enum struct ImageStatus {
	success,
	mismatchSize,
	wrongCharacter,
	cannotAppend,
	startFullIndex = 0,
};

class ImageFile :public AbstractFile
{
public:
	ImageFile(std::string newName);
	std::vector<char> read() override;
	int write(std::vector<char> newVector) override;
	int append(std::vector<char> newVector) override;
	unsigned int getSize() override;
	char getActualSize();
	char getActualChar();
	std::string getName() override;
	void accept(AbstractFileVisitor* file_visitor) override;
	AbstractFile* clone(std::string newFileName) override;
	bool isReadOnly() override;

protected:
	std::string name;
	std::vector<char> contents;
	char size;

};



