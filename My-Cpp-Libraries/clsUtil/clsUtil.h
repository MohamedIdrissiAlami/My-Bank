#pragma once
#include <iostream>
#include <string>
#include "../clsDate/clsDate.h";

class clsUtil
{
   
public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  std::string GenerateWord(enCharType CharType, short Length)

    {
        std::string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static std::string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        std::string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            std::cout << "Key [" << i << "] : ";
            std::cout << GenerateKey(CharType) << "\n";
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(std::string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(std::string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(std::string& A, std::string& B)
    {
        std::string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(std::string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static std::string  Tabs(short NumberOfTabs)
    {
        std::string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            std::cout << t;
        }
        return t;

    }

    static std::string  EncryptText(std::string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static std::string  DecryptText(std::string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static std::string NumberToText(int Number)
    {
        if (Number == 0)
            return "";
        if (Number > 0 && Number < 10)
        {
            std::string sNumber[9] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
            return sNumber[Number - 1];
        }
        if (Number >= 10 && Number < 20)
        {
            std::string sNumber[10] = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return sNumber[Number % 10 - 1];
        }
        if (Number >= 20 && Number < 100)
        {
            std::string sNumber[10] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return sNumber[Number / 10] + " " + NumberToText(Number % 10);
        }
        if (Number < 1000 && Number >= 100)
        {
            return NumberToText(int(Number / 100)) + " Hundred " + NumberToText(Number % 100);
        }
        if (Number >= 1000 && Number < 1000000)
        {
            return NumberToText(int(Number / 1000)) + " Thousand , " + NumberToText(Number % 1000);
        }
        if (Number >= 1000000 && Number < 1000000000)
        {
            return NumberToText(int(Number / 1000000)) + " Million , " + NumberToText(Number % 1000000);
        }
        if (Number >= 1000000000 && Number <= 4000000000)
        {
            return NumberToText(int(Number / 1000000000)) + " Billon , " + NumberToText(Number % 1000000000);
        }

        if (Number > 4000000000)
        {
            return " Zero ";
        }

    }


};

