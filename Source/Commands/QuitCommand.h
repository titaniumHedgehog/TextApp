#pragma once

#include "Command.h"

//--------------------------------------------------------------------------------------------------------------------------------

class QuitCommand : public Command
{

public:

					QuitCommand();

	virtual void	Execute(std::vector<std::string> const& Params) override;

};

//--------------------------------------------------------------------------------------------------------------------------------

