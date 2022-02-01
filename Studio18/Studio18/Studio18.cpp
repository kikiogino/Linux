// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\AbstractFileSystem.h"
#include "..\..\SharedCode\AbstractFileFactory.h"
#include "..\..\SharedCode\TextFile.h"
#include "..\..\SharedCode\ImageFile.h"
#include <iostream>
using namespace std;

int main()
{
	AbstractFileSystem* new_system_var = new SimpleFileSystem(); 
	AbstractFileFactory* new_factory = new SimpleFileFactory();

	AbstractFile* temp_text_var = new_factory->createFile("new_text.txt");
	cout << "Add text file generated from the file factory function result: " << new_system_var->addFile("new_text.txt", temp_text_var) << endl;


	AbstractFile* temp_image_var = new_factory->createFile("new_image.img");
	cout << "Add image file generated from the file factory function result: " << new_system_var->addFile("new_image.img", temp_image_var) << endl;

	AbstractFile* temp_music_var = new_factory->createFile("new_music.mp3");
	cout << "Add music file generated from the file factory function result - should fail: " << new_system_var->addFile("new_music.mp3", temp_music_var) << endl;

	vector<char> to_text_input;
	to_text_input.push_back('h');
	to_text_input.push_back('e');
	to_text_input.push_back('l');
	to_text_input.push_back('l');
	to_text_input.push_back('o');

	AbstractFile* opened_text_image = new_system_var->openFile("new_text.txt");
	opened_text_image->write(to_text_input);

	cout << "Text File Name: " << opened_text_image->getName() << endl;
	cout << "Text File Size: " << opened_text_image->getSize() << endl;

	cout << "Text:" << endl;
	opened_text_image->read();


	AbstractFile* opened_image_file = new_system_var->openFile("new_image.img");
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
	int image_file_write_result = opened_image_file->write(to_input);
	cout << image_file_write_result << endl;

	cout << "Image File Name: " << opened_image_file->getName() << endl;
	cout << "Image File Size: " << opened_image_file->getSize() << endl;
	cout << "Image: " << endl;

	cout << "Reading an image: " << endl;
	opened_image_file->read();

	cout << "Close text file (should be successful): " << new_system_var->closeFile(opened_text_image) << endl;
	cout << "Close image file (should be successful): " << new_system_var->closeFile(opened_image_file) << endl;

}
