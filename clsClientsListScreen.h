#pragma once
#include "./clsScreen.h"
#include "clsClient.h"
class clsClientsList : private clsScreen
{
private :
	static void _PrintClientRecordLine(clsClient Client)
	{
		cout <<setw(10) << "";
		cout << "|"<< left << setw(34) <<Client.FullName();
		cout << "|"<< left << setw(29) <<Client.Email;
		cout << "|"<< left << setw(13) <<Client.Phone;
		cout << "|"<< left << setw(19) <<Client.AccountNumber;
		cout << "|"<< left << setw(9) <<Client.PinCode;
		cout << "|"<< left << setw(19) <<Client.AccountBalance << "|";

	}
public  :
	static void  ShowClientsListScreen()
	{
		//cout << "\nclients list will be here ..";
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pShowClientsList))
			return;
		vector<clsClient> vClients = clsClient::GetClientsList();
		clsScreen::DrawScreenHeader("C L I E N T S   L I S T", "(" + to_string(vClients.size()) + ") CLIENT(S)");
		clsScreen::DrawHorizontalBorder(10, '_', 130);
		cout << setw(10) << "";
		cout << left << setw(35) << "|FULL NAME";
		cout << left << setw(30) << "|EMAIL";
		cout << left << setw(14) << "|PHONE";
		cout << left << setw(20) << "|ACC.NUMBER";
		cout << left << setw(10) << "|PIN CODE";
		cout << left << setw(20) << "|ACC.BALANCE"<<"|";
		clsScreen::DrawHorizontalBorder(10, '_', 130);
		if (!vClients.empty())
		{
			for (clsClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				clsScreen::DrawHorizontalBorder(10, '_', 130);
			}

		}
		else
		{
			cout << right << setw(60) << "" << "no available clients in the system!";
			clsScreen::DrawHorizontalBorder(10, '_', 130);
		}


	}
};

