#pragma once

//--------------------------------------------------------------------------------------------------------------------------------

#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

class ConnectionDirection;
class Location;

//--------------------------------------------------------------------------------------------------------------------------------

class Connection
{
public:
	ConnectionDirection const*	M_Direction;
	Location*					M_Connection { nullptr };

};

//--------------------------------------------------------------------------------------------------------------------------------

class Location
{

public:

	virtual std::string			GetDescription() const = 0;

	void						AddConnection(ConnectionDirection const* Direction, Location* Connection);
	size_t						GetNumConnections() const;
	virtual std::string			GetConnectionDescription(int connectionIndex) const;
	Location*					FindLocation(std::string const& MoveDir) const;

protected:

	std::string					M_Name;

	std::vector<Connection>		M_Connections;

};

//--------------------------------------------------------------------------------------------------------------------------------
