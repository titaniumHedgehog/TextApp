#include "Location.h"
#include "ConnectionDirection.h"

#include <algorithm>

//--------------------------------------------------------------------------------------------------------------------------------

void	Location::AddConnection(ConnectionDirection const* Direction, Location* Connection)
{
	M_Connections.push_back({ Direction,Connection });
}

//--------------------------------------------------------------------------------------------------------------------------------

size_t		Location::GetNumConnections() const
{
	return M_Connections.size();
}

//--------------------------------------------------------------------------------------------------------------------------------

std::string		Location::GetConnectionDescription(int connectionIndex) const
{
	if (connectionIndex >= 0 && connectionIndex < M_Connections.size())
	{
		Connection const& theConnection { M_Connections[connectionIndex] };
		if (ConnectionDirection const* const direction{ theConnection.M_Direction })
		{
			return direction->GetName();
		}
	}

	return "";
}

//--------------------------------------------------------------------------------------------------------------------------------

Location* Location::FindLocation(std::string const& MoveDir) const
{
	Location* FoundIt{ nullptr };
	std::for_each(M_Connections.begin(), M_Connections.end(), [&](Connection const& Direction) {
		if (Direction.M_Direction->MatchesDir(MoveDir))
		{
			FoundIt = Direction.M_Connection;
		}
		});

	return FoundIt;
}

//--------------------------------------------------------------------------------------------------------------------------------
