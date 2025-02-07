#pragma once

//--------------------------------------------------------------------------------------------------------------------------------

#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

class Location;

//--------------------------------------------------------------------------------------------------------------------------------

enum ConnectionDirection
{
	North,
	East,
	South,
	West
};

//--------------------------------------------------------------------------------------------------------------------------------

class Connection
{
public:
	ConnectionDirection		M_Direction;
	Location*				M_Connection { nullptr };

};

//--------------------------------------------------------------------------------------------------------------------------------

class Location
{

public:

	virtual std::string			GetDescription() const = 0;

	void						AddConnection(ConnectionDirection Direction, Location* Connection);
	int							GetNumConnections() const;
	virtual std::string			GetConnectionDescription(int connectionIndex) const;

protected:

	std::string					M_Name;

	std::vector<Connection>		M_Connections;

};

//--------------------------------------------------------------------------------------------------------------------------------
