#pragma once
#include "clsScreen.h"
#include "./My-Cpp-Libraries/clsInputValidate/clsInputValidate.h"
class clsTransferScreen :private clsScreen
{
private:
	static string ReadAccountNumber()
	{
		cout << "\n" << setw(40) << "";
		return clsInputValidate::ReadString("Enter The client's Account Number ..");
	}
	static float _ReadTransferAmount(float SenderBalance)
	{
		float TransfertAmount = 0;

		while ((TransfertAmount = clsInputValidate::ReadPositiveNumber<float>("\nEnter transfer amount : ")) > SenderBalance)
		{
			cout << "\nthe entered amount exceeds the sender's account balance !";
			cout << "\nyou can transfer up to :  " << SenderBalance;
		}

		return TransfertAmount;
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
	static void ShowTransferScreen()
	{
		//cout << "\nTransfer screen will be here..";
		clsScreen::DrawScreenHeader("T R A N S F E R", "S C R E E N");
		cout << "\nSender : \n";
		clsClient Sender = clsClient::Find(ReadAccountNumber());
		char Answer = 'n';
		if (!Sender.IsEmptyClientObject())
		{
			_PrintClientCard(Sender);
			cout << "\n\nReceiver : \n";
			clsClient Receiver =clsClient::Find("");
			while ((Receiver = clsClient::Find(ReadAccountNumber())).IsEmptyClientObject())
			{
				cout << "\nno client with [" << Receiver.AccountNumber << "] was found! please try again ..\n";
			}
			_PrintClientCard(Receiver);

			float TransferAmount = _ReadTransferAmount(Sender.AccountBalance);
			cout << "\nAre you sure do you want to perform this transaction ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				if (Sender.Transfer(Receiver,TransferAmount))
				{
					cout << "\nDone successfully!";
					cout << "\nSender's new balance : " << Sender.AccountBalance;
					cout << "\nreceiver 's new balance : " << Receiver.AccountBalance;
				}
				else
					cout << "\ncouldn't perform this transaction!";

			}
			else
				cout << "\nCanceled!";
		}
		else
			cout << "\n" << setw(40) << "" << "the client with [" << Sender.AccountNumber << "] was Not found!:-(";
	}
};
