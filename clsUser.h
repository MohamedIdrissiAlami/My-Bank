#pragma once
#include "My-Cpp-Libraries/clsDate/clsDate.h"
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h"
#include "My-Cpp-Libraries/clsString/clsString.h"
#include "My-Cpp-Libraries/clsUtil/clsUtil.h"
#include "clsPerson.h"
#include "Global.h"
#include <fstream>
using  namespace std;
class clsUser:public clsPerson
{
private:
	string _UserName;
	string _Password;
	short _Permissions;
	enum enMode { enAddNewMode, enUpdateMode, enEmptyMode };
	enMode _Mode;
	bool MarkedForDelete = false;

	static clsUser _GetEmptyUserObject(string UserName="")
	{
		return clsUser(enMode::enEmptyMode, "", "", "", "", UserName, "", 0);
	}
	static clsUser _ConvertUserLineToRecord(string UserLine)
	{
		vector<string>vSplit = clsString::Split(UserLine, Separator);
		return clsUser(enMode::enUpdateMode, vSplit[0], vSplit[1], vSplit[2], vSplit[3], vSplit[4], vSplit[5], stoi(vSplit[6]));
	}

public :

	clsUser(enMode Mode, string FirstName, string LastName, string  Email, string Phone, string UserName, string  Password, float Permissions)
		:
		clsPerson(FirstName, LastName, Email, Phone)
	{
		this->UserName = UserName;
		this->Password = Password;
		this->Permissions = Permissions;
		this->_Mode = Mode;
	}

	enum enPermissions{pNothing=0,pShowClientsList =1,pAddNewClient=2,pDeleteClient=4,pUpdateClient=8,pFindClient=16,pTransactions=32,pManageUsers=64,pLoginRegister=128,pFullAccess=-1};
	//get and set properties
	void SetUserName(string UserName)
	{
		this->_UserName = UserName;
	}
	string GetUserName()
	{
		return this->_UserName;
	}

	void SetPassword(string Password)
	{
		this->_Password = Password;
	}
	string GetPassword()
	{
		return this->_Password;
	}

	void SetPermissions(short Permissions)
	{
		this->_Permissions = Permissions;
	}
	short GetPermissions()
	{
		return this->_Permissions;
	}

	//access properties through '='
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	 static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			clsUser User = _GetEmptyUserObject();
			while (getline(MyFile, Line))
			{
				if ((User = _ConvertUserLineToRecord(Line)).UserName==UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return clsUser::_GetEmptyUserObject(UserName);
	}
	 static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			clsUser User = _GetEmptyUserObject();
			while (getline(MyFile, Line))
			{
				if ((User = _ConvertUserLineToRecord(Line)).UserName==UserName&&User.Password==Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return clsUser::_GetEmptyUserObject(UserName);
	}
	bool IsEmptyUserObject()
	{
		return this->_Mode == enMode::enEmptyMode;
	}
};