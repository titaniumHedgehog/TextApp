#pragma once

#include <string>

//--------------------------------------------------------------------------------------------------------------------------------

class Command
{

public:

						Command(char const* TheVerb);
	virtual				~Command();
	virtual void		Execute() = 0;

	bool				IsVerb(char const* VerbText) const;

private:

	std::string			M_Verb;

};

//--------------------------------------------------------------------------------------------------------------------------------
