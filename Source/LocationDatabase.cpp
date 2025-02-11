#include "LocationDatabase.h"
#include "Locations/ConnectionDirection.h"
#include "Locations/CorridorLocation.h"
#include "Locations/FightingPitLocation.h"
#include "Locations/PitCellLocation.h"
#include "Locations/Location.h"
#include "Locations/StartLocation.h"

#include <algorithm>
#include <iostream>

//--------------------------------------------------------------------------------------------------------------------------------

LocationDatabase::LocationDatabase()
{
	Location* Start{ new StartLocation() };
	M_Locations.push_back(Start);

	Location* Corridor0 { new CorridorLocation() };
	Location* Corridor1{ new CorridorLocation() };
	Location* PitCell{ new PitCellLocation() };
	Location* FightingPit{ new FightingPitLocation() };

	Start->AddConnection(ConnectionDirection::GetOrCreateDirection("North"), Corridor0);
	Corridor0->AddConnection(ConnectionDirection::GetOrCreateDirection("South"), Start);
	Corridor0->AddConnection(ConnectionDirection::GetOrCreateDirection("East"), Corridor1);
	Corridor1->AddConnection(ConnectionDirection::GetOrCreateDirection("West"), Corridor0);
	Corridor1->AddConnection(ConnectionDirection::GetOrCreateDirection("Down"), PitCell);
	PitCell->AddConnection(ConnectionDirection::GetOrCreateDirection("CellDoor"), FightingPit);

	M_CurrentLocation = Start;
}

//--------------------------------------------------------------------------------------------------------------------------------

LocationDatabase::~LocationDatabase()
{
	std::for_each(M_Locations.begin(), M_Locations.end(), [](Location const* TheLocation) {
		delete TheLocation;
		});
}

//--------------------------------------------------------------------------------------------------------------------------------

void	LocationDatabase::Update()
{
	if (M_CurrentLocation != nullptr)
	{
		std::cout << M_CurrentLocation->GetDescription() << "\n";
		std::cout << "Exits:\n";
		// output connections
		for (int connection = 0; connection < M_CurrentLocation->GetNumConnections(); ++connection)
		{
			std::cout << M_CurrentLocation->GetConnectionDescription(connection) << "\n";
		}
		std::cout << "\n";

	}
}

//--------------------------------------------------------------------------------------------------------------------------------

Location* LocationDatabase::GetCurrentLocation() const
{
	return M_CurrentLocation;
}

//--------------------------------------------------------------------------------------------------------------------------------

bool	LocationDatabase::Move(std::string const& MoveDir)
{
	if (M_CurrentLocation != nullptr)
	{
		Location* NewLocation{ M_CurrentLocation->FindLocation(MoveDir) };
		if (NewLocation != nullptr)
		{
			M_CurrentLocation = NewLocation;
			return true;
		}
	}

	return false;
}

//--------------------------------------------------------------------------------------------------------------------------------
