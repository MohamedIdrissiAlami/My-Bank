#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsLoginRegisterScreen :private clsScreen
{
private:
	static void  _PrintLoginRegisterRecord(clsUser::stLoginInfo Login)
	{
		cout << setw(20) << "";
		cout <<"|"<< left << setw(29) << Login.FullName;
		cout <<"|"<< left << setw(23) << Login.Username;
		cout <<"|"<< left << setw(14) << Login.Permissions;
		cout <<"|"<< left << setw(29) << Login.sDateTime << "|";

	}
public:
	static void ShowLoginRegisterScreen()
	{
		//cout << "\nlogin register screen will be here..";
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pLoginRegister))
			return;

		clsScreen::DrawScreenHeader("LOGIN REGISTER", "SCREEN");
		vector<clsUser::stLoginInfo>vLogins = clsUser::GetLoginLogs();

		clsScreen::DrawHorizontalBorder(20, '_', 100);
		cout << setw(20) << "";
		cout << left << setw(30) << "|FULL NAME ";
		cout << left << setw(24) << "|USERNAME";
		cout << left << setw(15) << "|PERMISSIONS";
		cout << left << setw(30) << "|Date and Time"<<"|";
		clsScreen::DrawHorizontalBorder(20, '_', 100);
		if (!vLogins.empty())
		{
			for (clsUser::stLoginInfo& Login : vLogins)
			{
				_PrintLoginRegisterRecord(Login);
				clsScreen::DrawHorizontalBorder(20,'_',100);
			}
		}
		else
		{
			cout <<"\n"<<setw(40)<<"" << "that's strange ,the login register is empty !";
			clsScreen::DrawHorizontalBorder(20,'_',100);
		}
	}
};

