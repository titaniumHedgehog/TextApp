#pragma once

//--------------------------------------------------------------------------------------------------------------------------------

class CommandDatabase;
class LocationDatabase;

//--------------------------------------------------------------------------------------------------------------------------------

class TextApp
{
public:

						TextApp();
	virtual				~TextApp();
	void				Run();
	void				RequestQuit();

	CommandDatabase*	GetCommandDatabase() const;
	LocationDatabase*	GetLocationDatabase() const;

	static TextApp*		GetInstance();

private:

	static TextApp*		s_pInstance;

	CommandDatabase*	M_CommandDatabase { nullptr };
	LocationDatabase*	M_LocationDatabase { nullptr };

	bool				M_Running{ false };

};

//--------------------------------------------------------------------------------------------------------------------------------
