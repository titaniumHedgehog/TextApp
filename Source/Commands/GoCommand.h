#pragma once

#include "Command.h"

//--------------------------------------------------------------------------------------------------------------------------------

class GoCommand : public Command
{

public:

							GoCommand();
	virtual void			Execute(std::vector<std::string> const& Params) override;

};

//--------------------------------------------------------------------------------------------------------------------------------
