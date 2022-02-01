#pragma once
#include "AbstractFile.h"
#include <string>

enum struct ChmodProxyStatus
{
	success,
	writeWrongPassword,
	appendWrongPassword,
	getSizeWrongPassword,
	readOnlyCannotEdit
};

class ChmodProxy : public AbstractFile
{
public:
	ChmodProxy(AbstractFile* newFile);
	~ChmodProxy();
	std::vector<char> read() override;
	int write(std::vector<char> newVector) override;
	int append(std::vector<char> newVector) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* file_visitor) override;
	AbstractFile* clone(std::string newFileName) override;
	bool isReadOnly() override; 
	AbstractFile* getFile();

private:
	AbstractFile* file;
};

