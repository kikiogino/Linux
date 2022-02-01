// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\SharedCode\TextFile.h"
#include "..\..\SharedCode\ImageFile.h"
#include "..\..\SharedCode\AbstractFile.h"
#include "..\..\SharedCode\BasicDisplayVisitor.h"
#include "..\..\SharedCode\MetadataDisplayVisitor.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	AbstractFile* text_file_example = new TextFile("new_text_file");

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
	vector<char> text_file_read_contents = text_file_example->read();

	for (int i = 0; i < text_file_read_contents.size(); ++i)
	{
		cout << text_file_read_contents[i];
	}

	cout << endl; 
	
	vector<char> to_append;
	to_append.push_back(' ');
	to_append.push_back('w');
	to_append.push_back('o');
	to_append.push_back('r');
	to_append.push_back('l');
	to_append.push_back('d');

	text_file_example->append(to_append);

	cout << "Text after appending:" << endl;
	text_file_read_contents = text_file_example->read();

	for (int i = 0; i < text_file_read_contents.size(); ++i)
	{
		cout << text_file_read_contents[i];
	}

	cout << endl;

	AbstractFile* image_file_example = new ImageFile("new_image_file");
	vector<char> to_image_input;
	to_image_input.push_back('X');
	to_image_input.push_back(' ');
	to_image_input.push_back('X');
	to_image_input.push_back(' ');
	to_image_input.push_back('X');
	to_image_input.push_back(' ');
	to_image_input.push_back('X');
	to_image_input.push_back(' ');
	to_image_input.push_back('X');
	to_image_input.push_back('3');

	cout << "Writing an image: " << endl;
	int image_file_write_result = image_file_example->write(to_image_input);
	cout << image_file_write_result << endl;

	cout << "Image File Name: " << image_file_example->getName() << endl;
	cout << "Image File Size: " << image_file_example->getSize() << endl;

	BasicDisplayVisitor new_display_visitor;
	text_file_example->accept(&new_display_visitor);
	image_file_example->accept(&new_display_visitor);
	
	

}
