#pragma once
#include "./clsScreen.h";
#include "./My-Cpp-Libraries/clsInputValidate/clsInputValidate.h";
#include "./clsClientsListScreen.h";
#include "./clsAddNewClientScreen.h";
#include "./clsDeleteClientScreen.h";
#include "./clsUpdateClientScreen.h";
#include "./clsFindClientScreen.h";
#include "./clsTransactionsMenuScreen.h";
#include "./clsManageUsersMenuScreen.h";
#include "./clsLoginRegisterScreen.h";

class clsMainScreen :private clsScreen
{
private :
	enum enMainMenuOption
	{
		eClientsList=1,
		eAddNewClient=2,
		eDeleteClient=3,
		eUpdateClient=4,
		eFindClient=5,
		eTransaction=6,
		eManageUsers=7,
		eLoginRegister=8,
		eLogout=9
	};

	static enMainMenuOption _ReadMainMenuOption()
	{
		cout << "\n" << setw(40) << "";
		return (enMainMenuOption)clsInputValidate::ReadNumberBetween<short>(1, 9, "Choose what do you wanna do [1~9] ");
	}

	static void _GoBackToMainMenuScreen()
	{
		cout << "\n\n" << setw(40) << "" << "PRESS ANY KEY TO GO BACK TO MAIN MENU..";
		system("pause>0");
		clsMainScreen::ShowMainMenuScreen();
	}
	static void  _PerformMainMenuScreenOption(enMainMenuOption Option)
	{
		switch (Option)
		{
		case enMainMenuOption::eClientsList:
			system("cls");
			clsClientsList::ShowClientsListScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eAddNewClient:
			system("cls");
			clsAddNewClientScreen::ShowAddNewClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eDeleteClient:
			system("cls");
			clsDeleteClientScreen::ShowDeleteClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eUpdateClient:
			system("cls");
			clsUpdateClientScreen::ShowUpdateClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eFindClient:
			system("cls");
			clsFindClientScreen::ShowFindClientScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eTransaction:
			system("cls");
			clsTransactionsMenuScreen::ShowTransactionsMenuScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eManageUsers:
			system("cls");
			clsManageUsersMenuScreen::ShowManageUsersMenuScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eLoginRegister:
			system("cls");
			clsLoginRegisterScreen::ShowLoginRegisterScreen();
			_GoBackToMainMenuScreen();
			break;
		case enMainMenuOption::eLogout:
			return;
		default:
			return;
		}
	}
public:
	static  void ShowMainMenuScreen()
	{
		clsScreen::DrawScreenHeader("M A I N   M E N U", "SCREEN");
		cout		<<setw(40) << "|" << "\t[1] SHOW CLIENTS LIST";
		cout << "\n"<<setw(40) << "|" << "\t[2] ADD NEW  CLIENT(S)";
		cout << "\n"<<setw(40) << "|" << "\t[3] DELETE CLIENT";
		cout << "\n"<<setw(40) << "|" << "\t[4] UPDATE CLIENT";
		cout << "\n"<<setw(40) << "|" << "\t[5] FIND CLIENT";
		cout << "\n"<<setw(40) << "|" << "\t[6] TRANSACTIONS";
		cout << "\n"<<setw(40) << "|" << "\t[7] MANAGE USER(S)";
		cout << "\n"<<setw(40) << "|" << "\t[8] LOGING REGISTER";
		cout << "\n"<<setw(40) << "|" << "\t[9] LOGOUT";
		cout << "\n";
		cout << setw(100) << "____________________________________________________________";//60
		cout << "\n";
		_PerformMainMenuScreenOption(_ReadMainMenuOption());

	}
};

