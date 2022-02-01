#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <string>
#include <vector>

class AbstractFileVisitor;

class AbstractFile
{
public:
	virtual ~AbstractFile() = default;
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char> newVector) = 0;
	virtual int append(std::vector<char> newVector) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual void accept(AbstractFileVisitor* file_visitor) = 0;
	virtual AbstractFile* clone(std::string newFileName) = 0;
	virtual bool isReadOnly() = 0;

};