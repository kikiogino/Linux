#pragma once
#include "AbstractFile.h"
#include <string>

enum struct PasswordProxyStatus
{
	success,
	writeWrongPassword,
	appendWrongPassword,
	getSizeWrongPassword,
	readOnlyCannotEdit
};

class PasswordProxy : public AbstractFile
{
public:
	PasswordProxy(AbstractFile* newFile, std::string newPassword);
	~PasswordProxy();
	std::vector<char> read() override;
	int write(std::vector<char> newVector) override;
	int append(std::vector<char> newVector) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* file_visitor) override;
	AbstractFile* clone(std::string newFileName) override;
	bool isReadOnly() override;
	
protected: 
	std::string passwordPrompt();
	bool passwordMatchHelper(std::string firstString); 

private:
	AbstractFile* file;
	std::string password;
};

