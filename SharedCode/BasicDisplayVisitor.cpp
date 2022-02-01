// definitions of basic display visitor here

#include "BasicDisplayVisitor.h"
#include <vector>
#include <iostream>

using namespace std;

void BasicDisplayVisitor::operator() (AbstractFile* abstract_file)
{
	abstract_file->accept(this);
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imageFile)
{
	if (imageFile != nullptr) {
		int temp_size_variable = static_cast<int>(imageFile->getActualSize());
		vector<char> temp_contents = imageFile->read(); 
		for (int y = temp_size_variable - 1; y >= static_cast<int>(ImageStatus::startFullIndex); --y) {
			for (int x = static_cast<int>(ImageStatus::startFullIndex); x < temp_size_variable; ++x) {
				int index = y * temp_size_variable + x;
				cout << temp_contents[index];
			}
			cout << endl;
		}
	}
}

void BasicDisplayVisitor::visit_TextFile(TextFile* textFile)
{
	if (textFile != nullptr)
	{
		for (int i = 0; i < textFile->read().size(); ++i)
		{
			cout << textFile->read()[i];
		}

		cout << endl;
	}
	
}