#pragma once

#include "AbstractParsingStrategy.h"
#include <vector>
#include <string>

class RenameParsingStrategy : public AbstractParsingStrategy
{
public:
	std::vector<std::string> parse(std::string stringToParse) override;
};
