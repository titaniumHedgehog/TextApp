#pragma once
#include "Command.h"

//--------------------------------------------------------------------------------------------------------------------------------

class StatusCommand : public Command
{
public:
					StatusCommand();

	virtual void	Execute(std::vector<std::string> const& Params) override;

};

//--------------------------------------------------------------------------------------------------------------------------------
