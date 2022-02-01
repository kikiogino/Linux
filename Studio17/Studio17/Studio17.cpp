// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>
using namespace std;


int main()
{
	
	AbstractFile * image_file_example = new ImageFile("new_image_file");
	vector<char> to_input;
	to_input.push_back('X');
	to_input.push_back(' ');
	to_input.push_back('X');
	to_input.push_back(' ');
	to_input.push_back('X');
	to_input.push_back(' ');
	to_input.push_back('X');
	to_input.push_back(' ');
	to_input.push_back('X');
	to_input.push_back('3');

	cout << "Writing an image: " << endl;
	int image_file_write_result = image_file_example->write(to_input);
	cout << image_file_write_result << endl;

	cout << "Image File Name: " << image_file_example->getName() << endl;
	cout << "Image File Size: " << image_file_example->getSize() << endl;
	cout << "Image: " << endl;

	cout << "Reading an image: " << endl; 
	image_file_example->read();
	

	vector<char> to_append;
	to_append.push_back('X');
	to_append.push_back(' ');
	to_append.push_back('X');
	to_append.push_back(' ');
	to_append.push_back('X');
	to_append.push_back(' ');
	to_append.push_back('X');
	to_append.push_back(' ');
	to_append.push_back('X');
	to_append.push_back('3');

	//image_file_example->append(to_append);

	SimpleFileSystem new_simple_file_system;


	cout << "SimpleFileSystem addFile: " << new_simple_file_system.addFile("new_image_file.img", image_file_example) << endl;;

	cout << "SimpleFileSystem createFile text.txt: " << new_simple_file_system.createFile("text.txt") << endl;


	cout << "SimpleFileSystem deleteFile text.txt: " << new_simple_file_system.deleteFile("text.txt") << endl;

	AbstractFile* opened_file = new_simple_file_system.openFile("new_image_file.img");
	opened_file->read();

	vector<char> to_rewrite;
	to_rewrite.push_back(' ');
	to_rewrite.push_back(' ');
	to_rewrite.push_back(' ');
	to_rewrite.push_back(' ');
	to_rewrite.push_back('X');
	to_rewrite.push_back(' ');
	to_rewrite.push_back(' ');
	to_rewrite.push_back(' ');
	to_rewrite.push_back(' ');
	to_rewrite.push_back('3');

	cout << "Image rewrite on opened file: " << opened_file->write(to_rewrite) << endl;;

	opened_file->read();

	new_simple_file_system.openFile("text.txt");

	cout << "File system createFile music.mp3 - should be wrong: " << new_simple_file_system.createFile("music.mp3") << endl;
	
	cout << "File system closeFile opened_file: " << new_simple_file_system.closeFile(opened_file) << endl;



}

