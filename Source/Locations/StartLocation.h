#pragma once
#include "Location.h"

//--------------------------------------------------------------------------------------------------------------------------------

class StartLocation : public Location
{

public:

								StartLocation();

	virtual std::string			GetDescription() const override;

};

//--------------------------------------------------------------------------------------------------------------------------------
