#pragma once
#include <iostream>
class clsPerson
{
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _Phone;

public:
	clsPerson(std::string FirstName, std::string LastName, std::string Email, std::string Phone)
	{
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->Email = Email;
		this->Phone = Phone;
	}
	//get and set properties :
	void SetFirstName(std::string FirstName)
	{
		this->_FirstName = FirstName;
	}
	std::string GetFirstName()
	{
		return this->_FirstName;
	}

	void  SetLastName(std::string LastName)
	{
		this->_LastName = LastName;
	}
	std::string GetLastName()
	{
		return this->_LastName;
	}

	void SetEmail(std::string  Email)
	{
		this->_Email = Email;
	}
	std::string GetEmail()
	{
		return this->_Email;
	}

	void SetPhone(std::string Phone)
	{
		this->_Phone = Phone;
	}
	std::string GetPhone()
	{
		return this->_Phone;
	}

	//get and set properties through '=' : 
	__declspec(property(get = GetFirstName, put = SetFirstName)) std::string FirstName;
	__declspec(property(get = GetLastName, put = SetLastName)) std::string  LastName;
	__declspec(property(get = GetEmail, put = SetEmail)) std::string Email;
	__declspec(property(get = GetPhone, put = SetPhone)) std::string Phone;


	std::string  FullName()
	{
		return this->FirstName + " " + this->LastName;
	}
};

