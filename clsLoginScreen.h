#pragma once
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsUser.h"
class clsLoginScreen :private clsScreen
{
public:
	static bool ShowLoginScreen()
	{
		clsScreen::DrawScreenHeader("L O G I N   S C R E E N");
		cout << "\n\nPLEASE LOGIN \n\tYOU HAVE (3) TRAILS : ";
		string UserName = clsInputValidate::ReadString("\n\n\tUSERNAME : ");
		string Password = clsInputValidate::ReadString("\n\tPASSWORD   : ");

		short Counter = 3;
		while (Counter > 1)
		{
			CurrentUser = clsUser::Find(UserName, Password);
			if (CurrentUser.IsExist())
			{
				CurrentUser.RegisterLogin();
				return true;
			}
			else
			{
				cout << "\nWrong UserName/Password!";
				cout << "\nattempts left : " << --Counter;
				UserName = clsInputValidate::ReadString("\n\n\tUSERNAME : ");
				Password = clsInputValidate::ReadString("\n\tPASSWORD   : ");

			}
		}
		cout << "\n\nLOCKED AFTER 3 FAILD TRIALS ,GO BACK LATER.";
		return  false;
	}
};
