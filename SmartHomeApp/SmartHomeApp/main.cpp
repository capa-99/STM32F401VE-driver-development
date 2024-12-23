#include "SmartHomeApp.h"

int main()
{
	SmartHome* myHome = new SmartHome();
	
	myHome->sendCode(CODE_LIGHT_BALCONY | ON);



	string a;
	cin >> a;

	return 0;
}