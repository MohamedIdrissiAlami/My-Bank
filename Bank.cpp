#include "./clsLoginScreen.h"
#include "./clsMainScreen.h"
int main()
{
	while (clsLoginScreen::ShowLoginScreen())
	{
		clsMainScreen::ShowMainMenuScreen();
	}
	return 0;
}
