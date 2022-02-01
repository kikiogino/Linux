#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

enum struct MetadataDisplayVisitorStatus
{
	success = 0,
	longestFileNamePossible = 20
};

class MetadataDisplayVisitor : public AbstractFileVisitor
{
	void operator() (AbstractFile* abstract_file);
	void visit_ImageFile(ImageFile* imageFile) override;
	void visit_TextFile(TextFile* textFile) override;
};