#include "ConnectionDirection.h"

//--------------------------------------------------------------------------------------------------------------------------------

std::map<std::string, ConnectionDirection*> ConnectionDirection::S_Directions;

//--------------------------------------------------------------------------------------------------------------------------------

ConnectionDirection* ConnectionDirection::GetOrCreateDirection(std::string const& TheDirection)
{
	std::map<std::string, ConnectionDirection*>::const_iterator FindDirection{ S_Directions.find(TheDirection) };
	if (FindDirection != S_Directions.end())
	{
		return FindDirection->second;
	}

	ConnectionDirection* NewDirection{ new ConnectionDirection(TheDirection) };
	return NewDirection;
}

//--------------------------------------------------------------------------------------------------------------------------------

ConnectionDirection::ConnectionDirection(std::string const& TheDirection) : M_Name(TheDirection)
{
	S_Directions.emplace(TheDirection, this);
}

//--------------------------------------------------------------------------------------------------------------------------------

void	ConnectionDirection::AddAlternateName(std::string const& AlternateName)
{
	M_AlterateNames.push_back(AlternateName);
}

//--------------------------------------------------------------------------------------------------------------------------------

std::string const& ConnectionDirection::GetName() const
{
	return M_Name;
}

//--------------------------------------------------------------------------------------------------------------------------------
