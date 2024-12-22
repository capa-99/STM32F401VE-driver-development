#include "SmartHomeApp.h"

int main()
{
	COMPort* port = new COMPort();
	
	/*uint16_t code = 0x21;
	DWORD bytesWritten;
	if (!WriteFile(hSerial, &code, sizeof(code), &bytesWritten, NULL)) {
		cerr << "Error writing to COM4" << endl;
	}
	cout << "Sent: " << code << endl;*/

	string a;
	cin >> a;

	return 0;
}