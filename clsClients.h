#pragma once
#include "My-Cpp-Libraries/clsDate/clsDate.h";
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h";
#include "My-Cpp-Libraries/clsString/clsString.h";
#include "My-Cpp-Libraries/clsUtil/clsUtil.h";
#include "clsPerson.h";
using  namespace std;
class clsClient :private clsPerson
{
private:
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

public:
	clsClient(string FirstName, string LastName, string  Email, string Phone, string AccountNumber, string  PinCode, float AccountBalance)
		:
		clsPerson(FirstName, LastName, Email, Phone)
	{
		this->AccountNumber = AccountNumber;
		this->PinCode = PinCode;
		this->AccountBalance = AccountBalance;
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
		this->_PinCode;
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
	__declspec(property(get = GetAccountNumber, put = SetAccountBalance)) float AccountBalance;


};

