#include <iostream>
#include "rsa.h"


using namespace std;

int main()
{   string x;
	RSA bilgi;
	
	bilgi.pAyarla(13);
	bilgi.qAyarla(23);
	bilgi.nAyarla();
    bilgi.esec(35);
	bilgi.dOlustur();

	
	
	cout << "String Giriniz:";
	cin >> x;

    bilgi.ciphermetin(x);
	
	bilgi.deciphermetin();
	
	system("pause");
	return 0;
}
