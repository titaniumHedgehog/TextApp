#include "ConnectionDirection.h"

#include <algorithm>

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
	M_AlternateNames.push_back(AlternateName);
}

//--------------------------------------------------------------------------------------------------------------------------------

std::string const& ConnectionDirection::GetName() const
{
	return M_Name;
}

//--------------------------------------------------------------------------------------------------------------------------------

bool	ConnectionDirection::MatchesDir(std::string const& MoveDir) const
{
	if (_stricmp(MoveDir.c_str(), M_Name.c_str()) == 0)
	{
		return true;
	}

	std::for_each(M_AlternateNames.begin(), M_AlternateNames.end(), [MoveDir](std::string const& alternateName) {
		if (_stricmp(MoveDir.c_str(), alternateName.c_str()))
		{
			return true;
		}});

	return false;
}

//--------------------------------------------------------------------------------------------------------------------------------
