#pragma once
#include "./clsScreen.h"
class clsUsersListScreen : private clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(10) << "";
		cout << "|" << left << setw(34) << User.FullName();
		cout << "|" << left << setw(29) << User.Email;
		cout << "|" << left << setw(13) << User.Phone;
		cout << "|" << left << setw(19) << User.UserName;
		cout << "|" << left << setw(14) << User.Password;
		cout << "|" << left << setw(14) << User.Permissions << "|";

	}
public:
	static void  ShowUsersListScreen()
	{
		//cout << "\nUsers list will be here ..";
		vector<clsUser> vUsers = clsUser::GetUsersList();
		clsScreen::DrawScreenHeader("C L I E N T S   L I S T", "(" + to_string(vUsers.size()) + ") User(S)");
		clsScreen::DrawHorizontalBorder(10, '_', 130);
		cout << setw(10) << "";
		cout << left << setw(35) << "|FULL NAME";
		cout << left << setw(30) << "|EMAIL";
		cout << left << setw(14) << "|PHONE";
		cout << left << setw(20) << "|USERNAME";
		cout << left << setw(15) << "|PASSWORD";
		cout << left << setw(15) << "|PERMISSIONS" << "|";
		clsScreen::DrawHorizontalBorder(10, '_', 130);
		if (!vUsers.empty())
		{
			for (clsUser& C : vUsers)
			{
				_PrintUserRecordLine(C);
				clsScreen::DrawHorizontalBorder(10, '_', 130);
			}

		}
		else
		{
			cout << right << setw(60) << "" << "no available Users in the system!";
			clsScreen::DrawHorizontalBorder(10, '_', 130);
		}


	}
};

