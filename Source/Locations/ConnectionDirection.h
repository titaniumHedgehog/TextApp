#pragma once

#include <map>
#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

class ConnectionDirection
{

public:

	static ConnectionDirection* GetOrCreateDirection(std::string const& TheDirection);
								ConnectionDirection(std::string const& TheDirection);
	void						AddAlternateName(std::string const& AlternateName);

	std::string const&			GetName() const;
	bool						MatchesDir(std::string const& MoveDir) const;

private:

	std::string					M_Name;
	std::vector<std::string>	M_AlternateNames;

	static std::map<std::string, ConnectionDirection*> S_Directions;

};

//--------------------------------------------------------------------------------------------------------------------------------
