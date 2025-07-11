#pragma once
#include "My-Cpp-Libraries/clsDate/clsDate.h"
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h"
#include "My-Cpp-Libraries/clsString/clsString.h"
#include "My-Cpp-Libraries/clsUtil/clsUtil.h"
#include "clsPerson.h"
#include "Global.h"
#include <fstream>
using  namespace std;
class clsUser:clsPerson
{
private:
	string _UserName;
	string _Password;
	short _Permissions;
	enum enMode { enAddNewMode, enUpdateMode, enEmptyMode };
	enMode _Mode;
	bool MarkedForDelete = false;

	clsUser(enMode Mode, string FirstName, string LastName, string  Email, string Phone, string UserName, string  Password, float Permissions)
		:
		clsPerson(FirstName, LastName, Email, Phone)
	{
		this->UserName = UserName;
		this->Password = Password;
		this->Permissions = Permissions;
		this->_Mode = Mode;
	}
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

	void SetPermissions(float Permissions)
	{
		this->_Permissions = Permissions;
	}
	float GetPermissions()
	{
		return this->_Permissions;
	}

	//access properties through '='
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	__declspec(property(get = GetPermissions, put = SetPermissions)) float Permissions;

};

