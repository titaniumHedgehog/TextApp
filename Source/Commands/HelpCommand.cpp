#include "HelpCommand.h"

#include "../TextApp.h"
#include "../CommandDatabase.h"

#include <algorithm>
#include <iostream>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

HelpCommand::HelpCommand() : Command("Help")
{

}

//--------------------------------------------------------------------------------------------------------------------------------

void	HelpCommand::Execute()
{
	std::cout << "Command List\n\n";

	if (CommandDatabase const* const Database { TextApp::GetInstance()->GetCommandDatabase() })
	{
		if (std::vector<Command*> const* Commands { Database->GetCommands() })
		{
			std::for_each(Commands->begin(), Commands->end(), [](Command const* TheCommand) {
				std::cout << ". " << TheCommand->GetVerb() << "\n";
				});
		}

		std::cout << "\n";
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

