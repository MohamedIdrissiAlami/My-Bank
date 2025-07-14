#pragma once
#include "clsScreen.h"
#include "clsClient.h";
class clsFindClientScreen :private clsScreen
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
public:
	static void ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here..";
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
			return;

		clsScreen::DrawScreenHeader("F I N D   C L I E N T", "SCREEN");
		clsClient Client = clsClient::Find(ReadAccountNumber());
		if (!Client.IsEmptyClientObject())
		{
			cout << "\n" << setw(40) << "" << "Found :-)";
			_PrintClientCard(Client);
		}
		else
			cout << "\n" << setw(40) << "" << "the client with ["<<Client.AccountNumber<<"] was Not found!:-(";
	}
};

