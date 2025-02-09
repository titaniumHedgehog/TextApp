#include "StatusCommand.h"

#include "../Character/Character.h"
#include "../TextApp.h"

#include <iostream>

//--------------------------------------------------------------------------------------------------------------------------------

StatusCommand::StatusCommand() : Command("Status")
{

}

//--------------------------------------------------------------------------------------------------------------------------------

void	StatusCommand::Execute(std::vector<std::string> const& Params)
{
	if (Character const* TheCharacter{ TextApp::GetInstance()->GetCharacter() })
	{
		std::cout << "HP = " << TheCharacter->GetHP();
		std::cout << "\n\n";
	}
}


//--------------------------------------------------------------------------------------------------------------------------------

