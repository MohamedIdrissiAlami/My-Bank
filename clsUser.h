#pragma once
#include "clsPerson.h"
#include "Config.h"
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
public:
	struct stLoginInfo
	{
		string FullName = "";
		string Username = "";
		short Permissions = 0;
		string sDateTime = clsDate::GetSystemDateTimeString();
	};
private:

	static clsUser _GetEmptyUserObject(string UserName="")
	{
		return clsUser(enMode::enEmptyMode, "", "", "", "", UserName, "", 0);
	}
	static clsUser _ConvertUserLineToRecord(string UserLine)
	{
		vector<string>vSplit = clsString::Split(UserLine, Separator);
		return clsUser(enMode::enUpdateMode, vSplit[0], vSplit[1], vSplit[2], vSplit[3], vSplit[4], vSplit[5], stoi(vSplit[6]));
	}
	static vector<clsUser>_LoadUsersFromFileToVector(string FileName = UsersFileName)
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open(FileName, ios::in);//open file in read mode 
		if (MyFile.is_open())
		{
			string Line = "";
			clsUser User = _GetEmptyUserObject();
			while (getline(MyFile, Line))
			{
				User = _ConvertUserLineToRecord(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	string  _ConvertUserRecordToLine(clsUser User)
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Separator;
		UserRecord += User.LastName + Separator;
		UserRecord += User.Email + Separator;
		UserRecord += User.Phone + Separator;
		UserRecord += User.UserName + Separator;
		UserRecord += User.Password + Separator;
		UserRecord += to_string(User.Permissions);
		return UserRecord;
	}

	void _AddNewUser()
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out | ios::app);//open file in append mode 
		if (MyFile.is_open())
		{
			MyFile << _ConvertUserRecordToLine(*this) << endl;
			MyFile.close();
		}
	}

	void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out);//open file in overwrite mode
		if (MyFile.is_open())
		{
			string Line = "";
			for (clsUser& User : vUsers)
			{
				if (!User.MarkedForDelete)
				{
					Line = _ConvertUserRecordToLine(User);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	bool _UpdateUserInfo()
	{
		vector<clsUser>vUsers = _LoadUsersFromFileToVector();
		for (clsUser& C : vUsers)
		{
			if (C.UserName == this->UserName)
			{
				C = *this;
				_SaveUsersDataToFile(vUsers);
				return true;
			}
		}
		return false;
	}

	string _PrepareLoginRegisterLine(stLoginInfo LoginRegister)
	{
		string LoginLine = "";
		LoginLine += LoginRegister.FullName + Separator;
		LoginLine += LoginRegister.Username+Separator;
		LoginLine += std::to_string(LoginRegister.Permissions)+Separator;
		LoginLine += LoginRegister.sDateTime;
		return LoginLine;
	}

	static  stLoginInfo _ConvertLoginRegisterLineToRecord(string Line)
	{
		vector<string>vSplit = clsString::Split(Line, Separator);
		stLoginInfo Login;
		Login.FullName = vSplit.at(0);
		Login.Username = vSplit.at(1);
		Login.Permissions = stoi(vSplit.at(2));
		Login.sDateTime = vSplit.at(3);
		return Login;
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

	static bool IsUserExist(string UserName)
	{
		vector<clsUser>vUsers = _LoadUsersFromFileToVector();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
				return true;
		}
		// if you reached here this means the User you are looking for does'nt exist!
		return false;
	}
	bool IsExist()
	{
		return IsUserExist(this->UserName);
	}
	static clsUser  GetNewUserObject(string UserName)
	{
		return clsUser(enMode::enAddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser>vUsers = _LoadUsersFromFileToVector();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == this->UserName)
			{
				User.MarkedForDelete = true;
				_SaveUsersDataToFile(vUsers);
				*this = _GetEmptyUserObject();
				return true;
			}
		}
		return false;
	}

	static  vector<clsUser> GetUsersList()
	{
		return _LoadUsersFromFileToVector();
	}

	enum enSaveResult { eSucceded, eFaildEmptyObject, eFailedUserExists };
	enSaveResult Save()
	{
		switch (this->_Mode)
		{
		case enMode::enUpdateMode:
			if (_UpdateUserInfo())
				return enSaveResult::eSucceded;
		case enMode::enAddNewMode:
			if (!IsExist())
			{
				_AddNewUser();
				this->_Mode = enMode::enUpdateMode;
				return enSaveResult::eSucceded;
			}
			return enSaveResult::eFailedUserExists;
		default:
			return enSaveResult::eFaildEmptyObject;
		}
		return enSaveResult::eFaildEmptyObject;
	}

	void RegisterLogin()
	{
		fstream MyFile;
		stLoginInfo LoginRegister;
		LoginRegister.FullName = this->FullName();
		LoginRegister.Username = this->UserName;
		LoginRegister.Permissions = this->Permissions;
		MyFile.open(LoginRegisterFileName,ios::out|ios::app);//open file in append mode
		if (MyFile.is_open())
		{
			MyFile << _PrepareLoginRegisterLine(LoginRegister) << endl;
			MyFile.close();
		}
	}

	static vector<stLoginInfo>GetLoginLogs()
	{
		vector<stLoginInfo>vLogs;
		fstream MyFile;
		MyFile.open(LoginRegisterFileName, ios::in);//read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				vLogs.push_back(_ConvertLoginRegisterLineToRecord(Line));
			}
			MyFile.close();
		}
		return vLogs;
	}

	bool HasAccessTo(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::pFullAccess)
			return true;
		return (this->Permissions&Permission) == Permission;
	}
};