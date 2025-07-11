#pragma once
#include "clsScreen.h";
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersMenuScreen :private clsScreen
{
private:
	enum enManageUsersMenuOption
	{
		eUsersList = 1,
		eAddNewUser = 2,
		eDeleteUser = 3,
		eUpdateUser = 4,
		eFindUser = 5,
		eExit = 6
	};
	static void _GoBackToManageUsersMenuScreen()
	{
		cout << "\n\n" << setw(40) << "" << "PRESS ANY KEY TO GO BACK TO Manage users MENU..";
		system("pause>0");
		clsManageUsersMenuScreen::ShowManageUsersMenuScreen();
	}

	static enManageUsersMenuOption _ReadManageUsersMenuOption()
	{
		cout << "\n" << setw(40) << "";
		return (enManageUsersMenuOption)clsInputValidate::ReadNumberBetween<short>(1, 6, "Choose what do you wanna do [1~6] ");
	}

	static void  _PerformManageUsersMenuOption(enManageUsersMenuOption Option)
	{
		switch (Option)
		{
		case enManageUsersMenuOption::eUsersList:
			system("cls");
			clsUsersListScreen::ShowUsersListScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enManageUsersMenuOption::eAddNewUser:
			system("cls");
			clsAddNewUserScreen::ShowAddNewUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enManageUsersMenuOption::eDeleteUser:
			system("cls");
			clsDeleteUserScreen::ShowDeleteUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case enManageUsersMenuOption::eUpdateUser:
			system("cls");
			clsUpdateUserScreen::ShowUpdateUserScreen();
			_GoBackToManageUsersMenuScreen();
		case enManageUsersMenuOption::eFindUser:
			system("cls");
			clsFindUserScreen::ShowFindUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		default:
			return;
		}
	}
public :
	static void ShowManageUsersMenuScreen()
	{
		//cout << "\nManage users menu screen will be here..";
		clsScreen::DrawScreenHeader("M A N A G E  U S E R S", "MENU SCREEN");
		cout <<			setw(40) << "|" << "\t[1] SHOW USERS LIST";
		cout << "\n" << setw(40) << "|" << "\t[2] ADD NEW USER(S)";
		cout << "\n" << setw(40) << "|" << "\t[3] DELETE USER";
		cout << "\n" << setw(40) << "|" << "\t[4] UPDATE USER INFO";
		cout << "\n" << setw(40) << "|" << "\t[5] FIND USER";
		cout << "\n" << setw(40) << "|" << "\t[6] EXIT";
		cout << "\n";
		clsScreen::DrawHorizontalBorder(40, '_', 60);
		_PerformManageUsersMenuOption(_ReadManageUsersMenuOption());
	}
};
