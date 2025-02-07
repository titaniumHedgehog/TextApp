#include "Location.h"

//--------------------------------------------------------------------------------------------------------------------------------

void	Location::AddConnection(ConnectionDirection Direction, Location* Connection)
{
	M_Connections.push_back({ Direction,Connection });
}

//--------------------------------------------------------------------------------------------------------------------------------

int		Location::GetNumConnections() const
{
	return M_Connections.size();
}

//--------------------------------------------------------------------------------------------------------------------------------

std::string		Location::GetConnectionDescription(int connectionIndex) const
{
	if (connectionIndex >= 0 && connectionIndex < M_Connections.size())
	{
		Connection const& theConnection { M_Connections[connectionIndex] };
		switch (theConnection.M_Direction)
		{

		case ConnectionDirection::North:
			return "North";

		case ConnectionDirection::East:
			return "East";

		case ConnectionDirection::South:
			return "South";

		case ConnectionDirection::West:
			return "West";

		}
	}

	return "";
}

//--------------------------------------------------------------------------------------------------------------------------------
