#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "./My-Cpp-Libraries/clsUtil/clsUtil.h"
class clsTotalBalancesScreen :private clsScreen
{
private:
	static void _PrintClientRecordLine(clsClient Client)
	{
		cout << right << setw(31) << "|";
		cout << left << setw(38) << Client.FullName()<<"|";
		cout << left << setw(19) << Client.AccountNumber<<"|";
		cout << left << setw(19) << Client.AccountBalance<<"|";
	}
public :
	static void  ShowTotalBalancesScreen()
	{
		//cout << "\ntotal balances screen will be here.. ";
		vector<clsClient>vClients = clsClient::GetClientsList();
		clsScreen::DrawScreenHeader("T O T A L  B A L A N C E  S", "S C R E E N");
		clsScreen::DrawHorizontalBorder(30, '_', 80);
		cout << right << setw(30) << "";
		cout << left << setw(39) << "|FULL NAME" ;
		cout << left << setw(20) << "|ACC.NUMBER" ;
		cout << left << setw(20) << "|ACC.BALANCE"<<"|";
		clsScreen::DrawHorizontalBorder(30, '_', 80);
		if (!vClients.empty())
		{
			for (clsClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				clsScreen::DrawHorizontalBorder(30, '_', 80);
			}
		}
		else
		{
			cout << right << setw(60) << "" << "no available clients in the system!";
			clsScreen::DrawHorizontalBorder(30, '_', 80);
		}
		float TotalBalances = clsClient::GetTotalBalances();
		cout << right << setw(40) << "" << "Total Number of clients : " << vClients.size() << " client(s)\n";
		cout << right << setw(40) << "" << "Total Balances : " << TotalBalances<<endl;
		cout << right << setw(40) << "" << "total balances in text : \"" << clsUtil::NumberToText((int)TotalBalances)<<"\"";
	}
};

