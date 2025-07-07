#pragma once
#include "clsScreen.h";
class clsUpdateClientScreen :private clsScreen
{
public :
	static void ShowUpdateClientScreen()
	{
		cout << "\nUpdate client screen will be here..";
	}
};

