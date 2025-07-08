#pragma once
#include "My-Cpp-Libraries/clsDate/clsDate.h";
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h";
#include "My-Cpp-Libraries/clsString/clsString.h";
#include "My-Cpp-Libraries/clsUtil/clsUtil.h";
#include "clsPerson.h";
#include "Global.h";
#include <fstream>
using  namespace std;
class clsClient :public clsPerson
{
private:
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	enum enMode{enAddNewMode,enUpdateMode,enEmptyMode};
	enMode _Mode;

	static clsClient _GetEmptyClientObject()
	{
		return clsClient(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}
	static clsClient _ConvertClientLineToRecord(string ClientLine)
	{
		vector<string>vClient = clsString::Split(ClientLine, Separator);
		return clsClient(enMode::enUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stof(vClient[6]));
	}
	static vector<clsClient>_LoadClientsFromFileToVector(string FileName = ClientsFileName)
	{
		vector<clsClient>vClients;
		fstream MyFile;
		MyFile.open(FileName,ios::in);//open file in read mode 
		if (MyFile.is_open())
		{
			string Line = "";
			clsClient Client = _GetEmptyClientObject();
			while (getline(MyFile, Line))
			{
				Client = _ConvertClientLineToRecord(Line);
				vClients.push_back(Client);
			}
		}
		return vClients;
	}
	
public:
	clsClient(enMode Mode,string FirstName, string LastName, string  Email, string Phone, string AccountNumber, string  PinCode, float AccountBalance)
		:
		clsPerson(FirstName, LastName, Email, Phone)
	{
		this->AccountNumber = AccountNumber;
		this->PinCode = PinCode;
		this->AccountBalance = AccountBalance;
		this->_Mode=Mode;
	}
	//get and set properties
	void SetAccountNumber(string AccountNumber)
	{
		this->_AccountNumber = AccountNumber;
	}
	string GetAccountNumber()
	{
		return this->_AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		this->_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return this->_PinCode;
	}

	void SetAccountBalance(float AccountBalance)
	{
		this->_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return this->_AccountBalance;
	}

	//access properties through '='
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	
	bool IsEmptyClientObject()
	{
		return this->_Mode==enMode::enEmptyMode;
	}
	static clsClient Find(string AccountNumber, string PinCode)
	{
		vector<clsClient>vClients = _LoadClientsFromFileToVector();
		for (clsClient& Client : vClients)
		{
			if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
			{
				return Client;
			}
		}
		return _GetEmptyClientObject();
	}
	static clsClient Find(string AccountNumber)
	{
		vector<clsClient>vClients = _LoadClientsFromFileToVector();
		for (clsClient& Client : vClients)
		{
			if (Client.AccountNumber == AccountNumber)
			{
				return Client;
			}
		}
		return _GetEmptyClientObject();
	}

};

