#include "LocationDatabase.h"
#include "Locations/Location.h"
#include "Locations/StartLocation.h"

#include <algorithm>

//--------------------------------------------------------------------------------------------------------------------------------

LocationDatabase::LocationDatabase()
{
	M_Locations.push_back(new StartLocation());

	M_CurrentLocation = M_Locations[0];
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
		M_CurrentLocation->Update();
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
