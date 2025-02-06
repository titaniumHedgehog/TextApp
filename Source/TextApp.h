#pragma once

//--------------------------------------------------------------------------------------------------------------------------------

class CommandDatabase;

//--------------------------------------------------------------------------------------------------------------------------------

class TextApp
{
public:

						TextApp();
	virtual				~TextApp();
	void				Run();
	void				RequestQuit();

	CommandDatabase*	GetCommandDatabase() const;

	static TextApp*		GetInstance();

private:

	static TextApp*		s_pInstance;

	CommandDatabase*	M_Database{ nullptr };

	bool				M_Running{ false };

};

//--------------------------------------------------------------------------------------------------------------------------------
