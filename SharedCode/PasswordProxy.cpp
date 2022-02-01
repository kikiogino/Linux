#include "PasswordProxy.h"
using namespace std; 
#include <iostream>
#include <string>

PasswordProxy::PasswordProxy(AbstractFile* newFile, string newPassword)
	:file(newFile), password(newPassword)
{
	
}

PasswordProxy::~PasswordProxy()
{
	delete file;
}

string PasswordProxy::passwordPrompt()
{
	cout << "Input a password: " << endl; 
	string passwordString; 
	cin >> passwordString;
	return passwordString; 
}

bool PasswordProxy::passwordMatchHelper(string firstString)
{
	return (firstString == this->password);
}

vector<char> PasswordProxy::read()
{
	vector<char> vector_contents;
	string user_input_password = passwordPrompt(); 
	if (passwordMatchHelper(user_input_password)) {
		vector_contents = file->read();
	}
	else
	{
		cout << "Wrong Password" << endl;
		return vector_contents;
	}

	return vector_contents;
}

int PasswordProxy::write(vector<char> newVector)
{
	string user_input_password = passwordPrompt();
	if (passwordMatchHelper(user_input_password)) {
		int write_result = file->write(newVector);

		if (write_result != static_cast<int>(PasswordProxyStatus::success))
		{
			return write_result;
		}
	}
	else 
	{
		cout << "Wrong Password. Password Proxy creation terminated." << endl;
		return static_cast<int>(PasswordProxyStatus::writeWrongPassword);
	}

	return static_cast<int>(PasswordProxyStatus::success);
}

int PasswordProxy::append(vector<char> newVector)
{
	string user_input_password = passwordPrompt();
	if (passwordMatchHelper(user_input_password)) {

		int append_result = file->append(newVector);
		if (append_result != static_cast<int>(PasswordProxyStatus::success))
		{
			return append_result;
		}
	}
	else
	{
		cout << "Wrong Password" << endl;
		return static_cast<int>(PasswordProxyStatus::appendWrongPassword);
	}

	return static_cast<int>(PasswordProxyStatus::success);
}

unsigned int PasswordProxy::getSize()
{
	return file->getSize();
}

string PasswordProxy::getName()
{
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* file_visitor)
{
	string user_input_password = passwordPrompt();
	if (passwordMatchHelper(user_input_password)) {
		file->accept(file_visitor);
	}
	else
	{
		cout << "Wrong Password" << endl;
	}
}

AbstractFile* PasswordProxy::clone(string newFileName)
{
	AbstractFile* new_file_clone = file->clone(newFileName);
	AbstractFile* new_password_proxy_clone = new PasswordProxy(new_file_clone, password);
	return new_password_proxy_clone;
}

bool PasswordProxy::isReadOnly()
{
	return false;
}