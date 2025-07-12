#pragma once
#include "clsScreen.h";
class clsUpdateUserScreen :private clsScreen
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
			cout << "\n" << right << setw(60) << "" << "* Show Users list.";
		}
		if ((Permissions & clsUser::enPermissions::pAddNewClient) == clsUser::enPermissions::pAddNewClient)
		{
			cout << "\n" << right << setw(60) << "" << "* Add new User.";
		}
		if ((Permissions & clsUser::enPermissions::pDeleteClient) == clsUser::enPermissions::pDeleteClient)
		{
			cout << "\n" << right << setw(60) << "" << "* Delete User.";
		}
		if ((Permissions & clsUser::enPermissions::pUpdateClient) == clsUser::enPermissions::pUpdateClient)
		{
			cout << "\n" << right << setw(60) << "" << "* update User.";
		}
		if ((Permissions & clsUser::enPermissions::pFindClient) == clsUser::enPermissions::pFindClient)
		{
			cout << "\n" << right << setw(60) << "" << "* find User.";
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

	static short _ReadUserPermissions()
	{
		char Answer = 'n';
		short  Permissions = 0;
		cout << "\n\tDo you want to give him full Access ? [Y/N] ";
		cin >> Answer;
		if (Answer != tolower('y'))
		{

			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Clients list [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pShowClientsList : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Add new clients [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pAddNewClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Delete client [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pDeleteClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Update client [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pUpdateClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t*Find client [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pFindClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Transactions [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pTransactions : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Manage users [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pManageUsers : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* login register [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer) == 'y') ? clsUser::enPermissions::pLoginRegister : 0;

		}
		else
		{
			Permissions = -1;
		}
		return Permissions;

	}
	static void _ReadNewUserInfo(clsUser& User)
	{
		cout << "\nPlease fill the following formula : ";
		User.FirstName = clsInputValidate::ReadString("\n\tFirst Name      : ");
		User.LastName = clsInputValidate::ReadString("\n\tLast Name       : ");
		User.Email = clsInputValidate::ReadString("\n\tEmail           : ");
		User.Phone = clsInputValidate::ReadString("\n\tPhone           : ");
		User.Password = clsInputValidate::ReadString("\n\tPassword        : ");
		User.Permissions = _ReadUserPermissions();
	}

	static void _PrintSaveResult(clsUser::enSaveResult SaveResult)
	{
		switch (SaveResult)
		{
		case clsUser::enSaveResult::eSucceded:
			cout << "\nSaved Successfully :-)!";
			system("color 0a");//green screen
			break;
		case clsUser::enSaveResult::eFaildEmptyObject:
			cout << "\nCouldn't save : empty User  object :-(";
			system("color 0c");//red screen
			break;
		case clsUser::enSaveResult::eFailedUserExists:
			cout << "\nCouldn't save : User already exists ! :-(";
			system("color 0c");//red screen
			break;
		default:
			break;
		}
		cout << "\npress any key..";
		system("pause>0");
		system("color 0f");
	}

public:
	static void ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User screen will be here..";
		clsScreen::DrawScreenHeader("U P D A T E   U S E R", "SCREEN");
		clsUser User = clsUser::Find(_ReadUserName());
		char Answer = 'n';
		if (!User.IsEmptyUserObject())
		{
			_PrintUserCard(User);
			cout << "\nAre you sure do you want update the User above ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				_ReadNewUserInfo(User);
				_PrintSaveResult(User.Save());
			}
			else
				cout << "\nCanceled!";
		}
		else
			cout << "\n" << setw(40) << "" << "the User with [" << User.UserName << "] was Not found!:-(";

	}
};
