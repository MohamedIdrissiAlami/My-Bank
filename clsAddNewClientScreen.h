#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsAddNewClientScreen :private clsScreen
{
private:
	static string _ReadNewClientAccountNumber()
	{
		string AccountNumber = ""; ;
		while (clsClient::IsClientExist(AccountNumber= clsInputValidate::ReadString("\nEnter Account Number for the new client  : ")))
		{
			cout << "\nthe client with [" << AccountNumber << "] already exists!";
			
		}
		return AccountNumber;
	}
	static void _ReadNewClientInfo(clsClient& Client)
	{
		cout << "\nPlease fill the following formula : ";
		Client.FirstName      = clsInputValidate::ReadString               ("\n\tFirst Name      : ");
		Client.LastName       = clsInputValidate::ReadString               ("\n\tLast Name       : ");
		Client.Email          = clsInputValidate::ReadString               ("\n\tEmail           : ");
		Client.Phone          = clsInputValidate::ReadString               ("\n\tPhone           : ");
		Client.PinCode        = clsInputValidate::ReadString               ("\n\tPin code        : ");
		Client.AccountBalance = clsInputValidate::ReadPositiveNumber<float>("\n\tAccount Balance : ");
	}
	static void _PrintSaveResult(clsClient::enSaveResult SaveResult)
	{
		switch (SaveResult)
		{
		case clsClient::enSaveResult::eSucceded:
			cout << "\nSaved Successfully :-)!";
			system("color 0a");//green screen
			break;
		case clsClient::enSaveResult::eFaildEmptyObject:
			cout << "\nCouldn't save : empty client  object :-(";
			system("color 0c");//red screen
			break;
		case clsClient::enSaveResult::eFailedClientExists:
			cout << "\nCouldn't save : client already exists ! :-(";
			system("color 0c");//red screen
			break;
		default:
			break;
		}
		cout << "\npress any key..";
		system("pause>0");
		system("color 0f");
	}
public :
	
	static void ShowAddNewClientScreen()
	{
		//cout << "\nadd new client screen will be here ..";
		string AccountNumber = "";
		char AddMore = 'n';
		do
		{
			clsScreen::DrawScreenHeader("ADD NEW CLIENTS", "SCREEN");
			cout << "\n";
			AccountNumber = _ReadNewClientAccountNumber();
			clsClient NewClient = clsClient::GetNewClientObject(AccountNumber);
			_ReadNewClientInfo(NewClient);
			_PrintSaveResult(NewClient.Save());
			cout << "\ndo you want to add more clients [Y/N]..";
			cin >> AddMore;

		} while (AddMore=='y'||AddMore=='Y');

	}
};

