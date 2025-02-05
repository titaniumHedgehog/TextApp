#include "CommandDatabase.h"

#include <algorithm>
#include "Commands/QuitCommand.h"

//--------------------------------------------------------------------------------------------------------------------------------

CommandDatabase::CommandDatabase()
{
	M_CommandList.push_back(new QuitCommand());
}

//--------------------------------------------------------------------------------------------------------------------------------

CommandDatabase::~CommandDatabase()
{
	std::for_each(M_CommandList.begin(), M_CommandList.end(), [](Command const* TheCommand){
		delete TheCommand;
		});
}

//--------------------------------------------------------------------------------------------------------------------------------

Command* CommandDatabase::FindCommand(std::string const& FindThis)
{
	auto FoundIt{ std::find_if(M_CommandList.begin(), M_CommandList.end(), [FindThis](Command const* CheckCommand) {
		return CheckCommand->IsVerb(FindThis.c_str()); }) };

	if (FoundIt != M_CommandList.end())
	{
		return *FoundIt;
	}

	return nullptr;
}

//--------------------------------------------------------------------------------------------------------------------------------
