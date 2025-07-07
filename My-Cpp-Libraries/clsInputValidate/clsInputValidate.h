#pragma once
#include <iostream>
#include <string>
#include "../clsString/clsString.h";
#include "../clsDate/clsDate.h";

class clsInputValidate
{

public:

	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	template <typename T>
	static T ReadNumber(std::string Message="", std::string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number=0;
			std::cout << Message;
		while (!(std::cin >> Number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To,std::string Message="", std::string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = 0;
		do
		{
			if (!IsNumberBetween<T>((Number= ReadNumber<T>(Message)), From, To))
				std::cout << ErrorMessage;
		} while (!IsNumberBetween<T>(Number, From, To));
		return Number;
	}

	template <typename T>
	static T ReadPositiveNumber(std::string Message = "")
	{
		T Number = 0;
		do
		{
			if ((Number = ReadNumber<T>(Message)) < 0)
				std::cout << "\nTry again with a positive number..";
		} while (Number<0);
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static std::string ReadString(std::string Message = "")
	{
		std::cout << Message;
		std::string S1;
		getline(std::cin >> std::ws, S1);
		return S1;
	}
	
	static char ReadChar(std::string Message = "")
	{
		std::cout << Message;
		char Ch = ' ';
		std::cin >> Ch;
		return Ch;
	}
};

