#pragma once
#include "Command.h"

//--------------------------------------------------------------------------------------------------------------------------------

class HelpCommand : public Command
{

public:

							HelpCommand();

	virtual void			Execute(std::vector<std::string> const& Params) override;

};

//--------------------------------------------------------------------------------------------------------------------------------
