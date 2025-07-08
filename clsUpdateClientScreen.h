#pragma once
#include "clsScreen.h";
class clsUpdateClientScreen :private clsScreen
{
private:
	static string ReadAccountNumber()
	{
		cout << "\n" << setw(40) << "";
		return clsInputValidate::ReadString("Enter The client's Account Number ..");
	}

	static void _PrintClientCard(clsClient Client)
	{
		cout << "\n" << setw(40) << "" << "The following is the Client's card : ";
		cout << "\n" << setw(100) << "____________________________________________________________";//60
		cout << "\n" << setw(40) << "|" << "\tFull Name      : " << Client.FullName();
		cout << "\n" << setw(40) << "|" << "\tEmail          : " << Client.Email;
		cout << "\n" << setw(40) << "|" << "\tPhone          : " << Client.Phone;
		cout << "\n" << setw(40) << "|" << "\tAccount number : " << Client.AccountNumber;
		cout << "\n" << setw(40) << "|" << "\tPin Code       : " << Client.PinCode;
		cout << "\n" << setw(40) << "|" << "\tAccount Balance: " << Client.AccountBalance;
		cout << "\n" << setw(100) << "____________________________________________________________";//60

	}

	static void _ReadNewClientInfo(clsClient& Client)
	{
		cout << "\nPlease fill the following formula : ";
		Client.FirstName = clsInputValidate::ReadString("\n\tFirst Name      : ");
		Client.LastName = clsInputValidate::ReadString("\n\tLast Name       : ");
		Client.Email = clsInputValidate::ReadString("\n\tEmail           : ");
		Client.Phone = clsInputValidate::ReadString("\n\tPhone           : ");
		Client.PinCode = clsInputValidate::ReadString("\n\tPin code        : ");
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
	static void ShowUpdateClientScreen()
	{
		//cout << "\nUpdate client screen will be here..";
			clsScreen::DrawScreenHeader("U P D A T E   C L I E N T", "SCREEN");
			clsClient Client = clsClient::Find(ReadAccountNumber());
			char Answer = 'n';
			if (!Client.IsEmptyClientObject())
			{
				_PrintClientCard(Client);
				cout << "\nAre you sure do you want update the client above ? [Y/N] ";
				cin >> Answer;
				if (tolower(Answer) == 'y')
				{
					_ReadNewClientInfo(Client);
					_PrintSaveResult(Client.Save());
				}
				else
					cout << "\nCanceled!";
			}
			else
				cout << "\n" << setw(40) << "" << "the client with [" << Client.AccountNumber << "] was Not found!:-(";
		
	}
};
