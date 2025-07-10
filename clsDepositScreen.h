#pragma once
#include "clsScreen.h"
#include  "./My-Cpp-Libraries/clsInputValidate/clsInputValidate.h"
class clsDepositScreen :private clsScreen
{
	static string ReadAccountNumber()
	{
		cout << "\n" << setw(40) << "";
		return clsInputValidate::ReadString("Enter The client's Account Number ..");
	}
	static float _ReadDepositAmount()
	{
		return clsInputValidate::ReadPositiveNumber<float>("\nEnter deposit amount : ");
	}

	static void _PrintClientCard(clsClient Client)
	{
		cout << "\n" << setw(40) << "" << "The following is the Client's card : ";
		cout << "\n" << setw(100) << "____________________________________________________________";//60
		cout << "\n" << setw(40) << "|" << "\tFull Name      : " << Client.FullName();
		cout << "\n" << setw(40) << "|" << "\tAccount number : " << Client.AccountNumber;
		cout << "\n" << setw(40) << "|" << "\tAccount Balance: " << Client.AccountBalance;
		cout << "\n" << setw(100) << "____________________________________________________________";//60

	}

public :
	static void  ShowDepositScreen()
	{
		//cout << "\nDeposit screen will be here..";
		clsScreen::DrawScreenHeader("D E P O S I T", "S C R E E N");
		clsClient Client = clsClient::Find(ReadAccountNumber());
		char Answer = 'n';
		if (!Client.IsEmptyClientObject())
		{
			_PrintClientCard(Client);
			float DepositAmount  = _ReadDepositAmount();
			cout << "\nAre you sure do you want to perform this transaction ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				if (Client.Deposit(DepositAmount))
				{
					cout << "\nDone successfully!";
					cout << "\nnew balance : " << Client.AccountBalance;
				}
				else
					cout << "\ncouldn't perform this transaction!";

			}
			else
				cout << "\nCanceled!";
		}
		else
			cout << "\n" << setw(40) << "" << "the client with [" << Client.AccountNumber << "] was Not found!:-(";

	}
};

