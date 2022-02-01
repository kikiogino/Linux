#pragma once
// declaration of the file visitor interface here
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>

class AbstractFileVisitor
{
public:
	virtual void visit_ImageFile(ImageFile* imageFile) = 0;
	virtual void visit_TextFile(TextFile* textFile) = 0;
};