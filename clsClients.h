#pragma once
#include "My-Cpp-Libraries/clsDate/clsDate.h";
#include "My-Cpp-Libraries/clsInputValidate/clsInputValidate.h";
#include "My-Cpp-Libraries/clsString/clsString.h";
#include "My-Cpp-Libraries/clsUtil/clsUtil.h";
#include "clsPerson.h";
using  namespace std;
class clsClients :private clsPerson
{
private:
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

public:
	//get and set properties
};

