#pragma once

#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

class Location;

//--------------------------------------------------------------------------------------------------------------------------------

class LocationDatabase
{

public:

								LocationDatabase();
	virtual						~LocationDatabase();

	void						Update();

	Location*					GetCurrentLocation() const;
	bool						Move(std::string const& MoveDir);

protected:

	Location*					M_CurrentLocation { nullptr };
	std::vector<Location*>		M_Locations;

};

//--------------------------------------------------------------------------------------------------------------------------------
