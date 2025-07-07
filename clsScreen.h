#pragma once
#include <iomanip>
#include <iostream>
using  namespace std;
class clsScreen
{
public :
	static void DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\n";
		cout << setw(100) << "____________________________________________________________";//60
		cout << "\n\n";
		cout << setw(40) << "|" << setw(40) << Title;
		cout << "\n\n";

		cout << setw(40) << "|" << setw(35) << SubTitle;
		cout << "\n\n";
		cout << setw(100) << "____________________________________________________________";//60
		cout << "\n\n";


	}
};

