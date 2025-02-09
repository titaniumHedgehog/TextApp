#include "CommandDatabase.h"

#include "Commands/GoCommand.h"
#include "Commands/HelpCommand.h"
#include "Commands/QuitCommand.h"
#include "Commands/StatusCommand.h"

#include <algorithm>

//--------------------------------------------------------------------------------------------------------------------------------

CommandDatabase::CommandDatabase()
{
	M_CommandList.push_back(new GoCommand());
	M_CommandList.push_back(new HelpCommand());
	M_CommandList.push_back(new QuitCommand());
	M_CommandList.push_back(new StatusCommand());
}

//--------------------------------------------------------------------------------------------------------------------------------

CommandDatabase::~CommandDatabase()
{
	std::for_each(M_CommandList.begin(), M_CommandList.end(), [](Command const* TheCommand){
		delete TheCommand;
		});
}

//--------------------------------------------------------------------------------------------------------------------------------

void	CommandDatabase::ExecuteCommand(std::string const& CommandLine)
{
	size_t firstSpace{ CommandLine.find_first_of(" ") };
	std::string verb{ firstSpace>=0 && firstSpace<CommandLine.length() ? CommandLine.substr(0,firstSpace) : CommandLine };
	std::vector<std::string> params;
	if (firstSpace >= 0 && firstSpace < CommandLine.length())
	{
		size_t splitIndex{ firstSpace + 1 };
		while (splitIndex < CommandLine.length())
		{
			size_t nextSpace{ CommandLine.find(" ",splitIndex) };
			params.push_back(CommandLine.substr(splitIndex, nextSpace-splitIndex));
			splitIndex = nextSpace<CommandLine.length() ? nextSpace + 1 : CommandLine.length();
		}
	}

	if (Command * ExecuteCommand { FindCommand(verb) })
	{
		ExecuteCommand->Execute(params);
	}
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

std::vector<Command*> const* CommandDatabase::GetCommands() const
{
	return &M_CommandList;
}

//--------------------------------------------------------------------------------------------------------------------------------
