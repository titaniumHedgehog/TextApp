#include "GoCommand.h"

#include "../LocationDatabase.h"
#include "../TextApp.h"
#include "../Locations/Location.h"

#include <algorithm>
#include <iostream>

//--------------------------------------------------------------------------------------------------------------------------------

GoCommand::GoCommand() : Command("Go")
{

}

//--------------------------------------------------------------------------------------------------------------------------------

void	GoCommand::Execute(std::vector<std::string> const& Params)
{
	LocationDatabase* const Locations{ TextApp::GetInstance()->GetLocationDatabase() };
	Location const* const CurrentLocation{ Locations!=nullptr ? Locations->GetCurrentLocation() : nullptr };

	std::string MoveDir { ""};

	if (Params.empty())
	{
		if (CurrentLocation != nullptr)
		{
			std::cout << "Which direction do you want to go? ";
			for (int Connection = 0; Connection < CurrentLocation->GetNumConnections(); ++Connection)
			{
				if (Connection > 0)
				{
					std::cout << ",";
				}
				std::cout << CurrentLocation->GetConnectionDescription(Connection);
			}
			std::cout << "\n";

			std::cin >> MoveDir;
		}
	}
	else
	{
		MoveDir = Params[0];
	}

	if (Locations != nullptr)
	{
		if (!Locations->Move(MoveDir))
		{
			std::cout << "You can't move " << MoveDir << "\n";
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
