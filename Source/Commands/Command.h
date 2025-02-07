#pragma once

#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------------------

class Command
{

public:

						Command(char const* TheVerb);
	virtual				~Command();
	virtual void		Execute(std::vector<std::string> const& Params) = 0;

	bool				IsVerb(char const* VerbText) const;
	std::string const&	GetVerb() const;

private:

	std::string			M_Verb;

};

//--------------------------------------------------------------------------------------------------------------------------------
