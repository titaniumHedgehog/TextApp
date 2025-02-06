// TextApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TextApp.h"
#include "Commands/Command.h"
#include "CommandDatabase.h"

//--------------------------------------------------------------------------------------------------------------------------------

int main()
{
	TextApp* TheApp = new TextApp();
	TheApp->Run();

	delete TheApp;
}

//--------------------------------------------------------------------------------------------------------------------------------

TextApp* TextApp::s_pInstance{ nullptr };

//--------------------------------------------------------------------------------------------------------------------------------

TextApp::TextApp()
{
	s_pInstance = this;
	M_Database = new CommandDatabase();
}

//--------------------------------------------------------------------------------------------------------------------------------

TextApp::~TextApp()
{
	delete M_Database;
}

//--------------------------------------------------------------------------------------------------------------------------------


void	TextApp::Run()
{
	std::cout << "Let's Play A Game\n\n";

	M_Running = true;
	while (M_Running)
	{
		std::cout << "Enter a Command\n";

		std::string commandLine;
		std::cin >> commandLine;

		if (Command * ExecuteCommand{ M_Database->FindCommand(commandLine) })
		{
			ExecuteCommand->Execute();
		}

	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void	TextApp::RequestQuit()
{
	M_Running = false;
}

//--------------------------------------------------------------------------------------------------------------------------------

CommandDatabase* TextApp::GetCommandDatabase() const
{
	return M_Database;
}

//--------------------------------------------------------------------------------------------------------------------------------

TextApp* TextApp::GetInstance()
{
	return s_pInstance;
}

//--------------------------------------------------------------------------------------------------------------------------------

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
