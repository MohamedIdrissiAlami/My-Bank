#pragma once
#include "clsScreen.h"
class clsFindUserScreen :private clsScreen
{
private:

	static string _ReadUserName()
	{
		cout << "\n" << setw(40) << "";
		return clsInputValidate::ReadString("Enter The User's username ..");
	}

	static void _PrintUserPermissions(short Permissions)
	{
		cout << "\n" << right << setw(40) << "\tthis user has access to : ";
		if ((clsUser::enPermissions)Permissions == clsUser::enPermissions::pNothing)
		{
			cout << "\n" << right << setw(60) << "" << "* has no permissions.";
			return;
		}
		if ((clsUser::enPermissions)Permissions == clsUser::enPermissions::pFullAccess)
		{
			cout << "\n" << right << setw(60) << "" << "* full access.";
			return;
		}
		if ((Permissions & clsUser::enPermissions::pShowClientsList) == clsUser::enPermissions::pShowClientsList)
		{
			cout << "\n" << right << setw(60) << "" << "* Show clients list.";
		}
		if ((Permissions & clsUser::enPermissions::pAddNewClient) == clsUser::enPermissions::pAddNewClient)
		{
			cout << "\n" << right << setw(60) << "" << "* Add new client.";
		}
		if ((Permissions & clsUser::enPermissions::pDeleteClient) == clsUser::enPermissions::pDeleteClient)
		{
			cout << "\n" << right << setw(60) << "" << "* Delete client.";
		}
		if ((Permissions & clsUser::enPermissions::pUpdateClient) == clsUser::enPermissions::pUpdateClient)
		{
			cout << "\n" << right << setw(60) << "" << "* update client.";
		}
		if ((Permissions & clsUser::enPermissions::pFindClient) == clsUser::enPermissions::pFindClient)
		{
			cout << "\n" << right << setw(60) << "" << "* find client.";
		}
		if ((Permissions & clsUser::enPermissions::pTransactions) == clsUser::enPermissions::pTransactions)
		{
			cout << "\n" << right << setw(60) << "" << "* transactions.";
		}
		if ((Permissions & clsUser::enPermissions::pManageUsers) == clsUser::enPermissions::pManageUsers)
		{
			cout << "\n" << right << setw(60) << "" << "* manage users.";
		}
		if ((Permissions & clsUser::enPermissions::pLoginRegister) == clsUser::enPermissions::pLoginRegister)
		{
			cout << "\n" << right << setw(60) << "" << "* Show login register.";
		}
	}

	static void _PrintUserCard(clsUser User)
	{
		cout << "\n" << setw(40) << "" << "The following is the User's card : ";
		clsScreen::DrawHorizontalBorder(40, '_', 60);
		cout << "\n" << setw(40) << "|" << "\tFull Name      : " << User.FullName();
		cout << "\n" << setw(40) << "|" << "\tEmail          : " << User.Email;
		cout << "\n" << setw(40) << "|" << "\tPhone          : " << User.Phone;
		cout << "\n" << setw(40) << "|" << "\tUsername : " << User.UserName;
		cout << "\n" << setw(40) << "|" << "\tPassword       : " << User.Password;
		_PrintUserPermissions(User.Permissions);
		clsScreen::DrawHorizontalBorder(40, '_', 60);


	}
public:
	static void ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will be here..";
		clsScreen::DrawScreenHeader("F I N D   U S E R", "SCREEN");
		clsUser User = clsUser::Find(_ReadUserName());
		if (!User.IsEmptyUserObject())
		{
			cout << "\n" << setw(40) << "" << "Found :-)";
			_PrintUserCard(User);
		}
		else
			cout << "\n" << setw(40) << "" << "the User with [" << User.UserName << "] was Not found!:-(";
	}
};

