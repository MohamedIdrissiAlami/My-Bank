#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsAddNewUserScreen :private clsScreen
{
private:
	static string _ReadNewUserUserName()
	{
		string UserName = ""; ;
		while (clsUser::IsUserExist(UserName = clsInputValidate::ReadString("\nEnter Username for the new User  : ")))
		{
			cout << "\nthe User with [" << UserName << "] already exists!";
		}
		return UserName;
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
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pShowClientsList : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Add new clients [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pAddNewClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Delete client [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pDeleteClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Update client [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pUpdateClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t*Find client [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pFindClient : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Transactions [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pTransactions : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* Manage users [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pManageUsers : 0;


			cout << "\n\tDo you want to give him access to :  ";
			cout << "\n\t\t* login register [Y/N] ?  ";
			cin >> Answer;
			Permissions += (tolower(Answer)=='y') ? clsUser::enPermissions::pLoginRegister : 0;

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
		User.LastName  = clsInputValidate::ReadString("\n\tLast Name       : ");
		User.Email     = clsInputValidate::ReadString("\n\tEmail           : ");
		User.Phone     = clsInputValidate::ReadString("\n\tPhone           : ");
		User.Password  = clsInputValidate::ReadString("\n\tPassword        : ");
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

	static void ShowAddNewUserScreen()
	{
		//cout << "\nadd new User screen will be here ..";
		string UserName = "";
		char AddMore = 'n';
		do
		{
			clsScreen::DrawScreenHeader("ADD NEW Users", "SCREEN");
			cout << "\n";
			UserName = _ReadNewUserUserName();
			clsUser NewUser = clsUser::GetNewUserObject(UserName);
			_ReadNewUserInfo(NewUser);
			_PrintSaveResult(NewUser.Save());
			cout << "\ndo you want to add more Users [Y/N]..";
			cin >> AddMore;

		} while (AddMore == 'y' || AddMore == 'Y');

	}
};

