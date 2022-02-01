#include "ChmodProxy.h"
using namespace std;
#include <iostream>
#include <string>

ChmodProxy::ChmodProxy(AbstractFile* newFile)
	:file(newFile)
{

}

ChmodProxy::~ChmodProxy()
{
	delete file;
}

vector<char> ChmodProxy::read()
{
	return file->read();
}

int ChmodProxy::write(vector<char> newVector)
{
	cout << "File is read only, cannot write to file" << endl;
	return static_cast<int>(ChmodProxyStatus::success);
}

int ChmodProxy::append(vector<char> newVector)
{
	cout << "File is read only, cannot append to file" << endl;
	return static_cast<int>(ChmodProxyStatus::success);
}

unsigned int ChmodProxy::getSize()
{
	return file->getSize();
}

string ChmodProxy::getName()
{
	return file->getName();
}

void ChmodProxy::accept(AbstractFileVisitor* file_visitor)
{
	file->accept(file_visitor);
}

AbstractFile* ChmodProxy::clone(string newFileName)
{
	AbstractFile* new_file_clone = file->clone(newFileName);
	AbstractFile* new_password_proxy_clone = new ChmodProxy(new_file_clone);
	return new_password_proxy_clone;
}

bool ChmodProxy::isReadOnly()
{
	return true;
}

AbstractFile* ChmodProxy::getFile()
{
	return file;
}