// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>
using namespace std;


void MetadataDisplayVisitor::operator () (AbstractFile* abstract_file)
{
	abstract_file->accept(this);
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile)
{
	unsigned int longest_piece = static_cast<int>(MetadataDisplayVisitorStatus::longestFileNamePossible);
	if (imageFile != nullptr)
	{
		cout << left << setw(longest_piece) << imageFile->getName();
		cout << left << setw(longest_piece) << "image";
		cout << left << setw(longest_piece) << imageFile->getSize(); 
		cout << endl;
	}
}

void MetadataDisplayVisitor::visit_TextFile(TextFile* textFile)
{
	unsigned int longest_piece = static_cast<int>(MetadataDisplayVisitorStatus::longestFileNamePossible);
	if (textFile != nullptr)
	{
		cout << setw(longest_piece) << textFile->getName();
		cout << setw(longest_piece) << "text";
		cout << setw(longest_piece) << textFile->getSize();
		cout << endl;
	}
}