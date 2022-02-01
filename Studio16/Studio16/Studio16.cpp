// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\AbstractFile.h"
#include <iostream>

using namespace std;


int main()
{
	AbstractFile * text_file_example = new TextFile("new_text_file");

	vector<char> to_input;
	to_input.push_back('h');
	to_input.push_back('e');
	to_input.push_back('l');
	to_input.push_back('l');
	to_input.push_back('o');

	text_file_example->write(to_input);

	cout << "Text File Name: " << text_file_example->getName() << endl;
	cout << "Text File Size: " << text_file_example->getSize() << endl;

	cout << "Text:" << endl;
	text_file_example->read();

	vector<char> to_append;
	to_append.push_back(' ');
	to_append.push_back('w');
	to_append.push_back('o');
	to_append.push_back('r');
	to_append.push_back('l');
	to_append.push_back('d');

	text_file_example->append(to_append);

	cout << "Text after appending:" << endl;
	text_file_example->read();


	
}


