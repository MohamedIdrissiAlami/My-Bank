#pragma once
#include "clsScreen.h";
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTotalBalancesScreen.h"
class clsTransactionsMenuScreen : private clsScreen
{
private:
	enum enTransactionsMenuOption
	{
		eDeposit = 1,
		eWithdraw = 2,
		eTransfert = 3,
		eTotalBalances = 4,
		eExit
	};
	static void _GoBackToTransactionsMenuScreen()
	{
		cout << "\n\n" << setw(40) << "" << "PRESS ANY KEY TO GO BACK TO TRANSACTIONOS MENU..";
		system("pause>0");
		clsTransactionsMenuScreen::ShowTransactionsMenuScreen();
	}

	static enTransactionsMenuOption _ReadTransactionsMenuOption()
	{
		cout << "\n" << setw(40) << "";
		return (enTransactionsMenuOption)clsInputValidate::ReadNumberBetween<short>(1, 5, "Choose what do you wanna do [1~5] ");
	}

	static void  _PerformTransactionMenuOption(enTransactionsMenuOption Option)
	{
		switch (Option)
		{
		case enTransactionsMenuOption::eDeposit:
			system("cls");
			clsDepositScreen::ShowDepositScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		case enTransactionsMenuOption::eWithdraw:
			system("cls");
			clsWithdrawScreen::ShowWithdrawScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		case enTransactionsMenuOption::eTransfert:
			system("cls");
			clsTransferScreen::ShowTransferScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		case enTransactionsMenuOption::eTotalBalances:
			system("cls");
			clsTotalBalancesScreen::ShowTotalBalancesScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		default:
			return;
		}
	}

public :
	static void ShowTransactionsMenuScreen()
	{
		//cout << "\nTransactions menu screen will be here.. ";
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pTransactions))
			return;

		clsScreen::DrawScreenHeader("T R A N S A C T I O N S  M E N U", "SCREEN");
		cout <<         setw(40) << "|" << "\t[1] D E P O S I T";
		cout << "\n" << setw(40) << "|" << "\t[2] W I T H R A W";
		cout << "\n" << setw(40) << "|" << "\t[3] T R A N S F E R T";
		cout << "\n" << setw(40) << "|" << "\t[4] T O T A L   B A L A N C E S";
		cout << "\n" << setw(40) << "|" << "\t[5] E X I T";
		cout << "\n";
		clsScreen::DrawHorizontalBorder(40, '_', 60);
		_PerformTransactionMenuOption(_ReadTransactionsMenuOption());
	}
};

