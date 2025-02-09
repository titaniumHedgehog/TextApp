#pragma once

//--------------------------------------------------------------------------------------------------------------------------------

class Character;
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
	Character*			GetCharacter() const;

	static TextApp*		GetInstance();

private:

	static TextApp*		s_pInstance;

	CommandDatabase*	M_CommandDatabase { nullptr };
	LocationDatabase*	M_LocationDatabase { nullptr };
	Character*			M_Character { nullptr };

	bool				M_Running{ false };

};

//--------------------------------------------------------------------------------------------------------------------------------
