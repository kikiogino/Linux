#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"

class BasicDisplayVisitor: public AbstractFileVisitor
{
public:
	void operator () (AbstractFile* abstract_file);
	void visit_ImageFile(ImageFile* imageFile) override;
	void visit_TextFile(TextFile* textFile) override;
};