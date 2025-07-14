#pragma once
#include <iomanip>
#include <iostream>
#include "Global.h"
using  namespace std;
class clsScreen
{
private :
	static void _PrintAccessDeniedMessage()
	{
		DrawScreenHeader("A C C E S S  D E N I E D","Contact your admin!");
	} 
public :

	static void DrawScreenHeader(string Title, string SubTitle = "")
	{
		system("cls");
		cout << "\n";
		DrawHorizontalBorder(40, '_', 60);
		cout << "\n";
		cout << right<<setw(40) << "|" << setw(40) << Title;
		cout << "\n\n";
		cout << right<<setw(40) << "|" << setw(35) << SubTitle;
		cout << "\n";
		DrawHorizontalBorder(40, '_', 60);
		cout << "\n";

	}


	static void DrawHorizontalBorder(short Margin, char chUnit , short BorderLength)
	{
		string Line = "";
		for (short i = 1; i <= BorderLength; i++)
			Line += chUnit;
		cout << "\n" << setw(Margin) <<"" << Line << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.HasAccessTo(Permission))
		{
			_PrintAccessDeniedMessage();
			return false;
		}
		return true;
	}
};

