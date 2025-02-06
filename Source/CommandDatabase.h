#pragma once

//--------------------------------------------------------------------------------------------------------------------------------

#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

class Command;

//--------------------------------------------------------------------------------------------------------------------------------

class CommandDatabase
{

public:

									CommandDatabase();
									~CommandDatabase();

	Command*						FindCommand(std::string const& FindThis);
	std::vector<Command*> const*	GetCommands() const;

private:

	std::vector<Command*>			M_CommandList;

};
