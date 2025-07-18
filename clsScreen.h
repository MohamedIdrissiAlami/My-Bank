#pragma once
#include <iomanip>
#include "Global.h"
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h"

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
		cout << "\n" << setw(40) << ""<<"Current user : "<<CurrentUser.FullName();
		cout << "\n" << setw(40) << "" << "Current date : " << clsDate::DateToString(clsDate::GetSystemDate());
		DrawHorizontalBorder(40, '_', 60);
		cout << right<<setw(40) << "|" << setw(40) << Title;
		cout << "\n";
		cout << right<<setw(40) << "|" << setw(35) << SubTitle;
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

