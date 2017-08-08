#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <math.h>
#define boyut 512

using namespace std;

extern int i = 0;

extern int sayac = 0;

int ebob(int m,int n )
{
	int r=0;
	if (m > 0 && n > 0){
		if (m > n)
		{
			while (n != 0)
			{
				r = m%n;
				m = n;
				n = r;
			}
			return m;
		}
		if (n > m)
		{
			while (m != 0)
			{
				r = n%m;
				n = m;
				m = r;
			}
			return n;
		}
	}

}
int mod(int a, int b, int n) // a^b % n 
{
	int sonuc = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
			{sonuc = (sonuc * a) % n;}
		  b = b >> 1;
		a  = (a* a) % n;
	}
	return sonuc;
}
int modHesapla(int x, int y){
	int z=0;
	if (x > y){
		z = x%y;
			
	}

return z;
}

class RSA {
	
public:
	RSA();



	int pAyarla(int);

	int qAyarla(int);

	int nAyarla();

	int qnAyarla();

	int esec(int );

	int dOlustur();

	string ciphermetin(string );             //

	void deciphermetin();

private :
	
	int p;
	
	int q;
	
	int n;
	
	int qn;
	
	int e;
	
	int d;
	
	int dizi[26];

	char *harf;

	int cipherdizi[boyut];

	int decipherdizi[boyut];
	
	string s;
};


RSA::RSA(){
	 p = 0;
	 q = 0;
	 n = 1;
	 qn = 1;
	 e = 1;// eğer yanlış tanımlama olursa yapıcı e yi 1 yapsın.
	 d = 2;
	 string s = "";
	 dizi[26] = { 0 };
	 cipherdizi[boyut] = { 0 };
	 decipherdizi[boyut] = { 0 };
	 

	 harf = new char[26];

	 harf[0] = 'a'; harf[1] = 'b'; harf[2] = 'c'; harf[3] = 'd'; harf[4] = 'e';
	 harf[5] = 'f'; harf[6] = 'g'; harf[7] = 'h'; harf[8] = 'i'; harf[9] = 'j'; 
     harf[10] = 'k'; harf[11] = 'l';harf[12] = 'm';harf[13] = 'n';harf[14] = 'o';
	 harf[15] = 'p'; harf[16] = 'q'; harf[17] = 'r'; harf[18] = 's';harf[19] = 't';
	 harf[20] = 'u';harf[21] = 'v';harf[22] = 'w';harf[23] = 'x';harf[24] = 'y';harf[25] = 'z';
}
int RSA::pAyarla(int h){
	
	for (i = 1; i <= h; i++)
	{ 
		if (h%i == 0) 
		   { sayac++; } 
	}
	if (sayac == 2)
	{
		p = h;
	}
	else
	{
		cout << "p yanlis cikti" << endl;
		abort();
	}
	return h;
	
}
int RSA::qAyarla(int y)
{
	sayac = 0;

	for (i = 1; i <= y; i++)
	{
		if (y%i == 0)
		{
			sayac++;
		}
	}
	if (sayac == 2)
	{
		q = y;
	}
	else
	{
		cout << "q yanlis cikti" << endl;
		abort();
	}
	return y;
}

int RSA::nAyarla(){
	
	
	n = p*q;
	//cout << "n degeri=" << n<<endl;

	return n;
	}


int RSA::qnAyarla(){
	

	qn = (p-1)*(q-1);
	cout << "Q(n)degeri=" << qn << endl;
	return qn;
}


int RSA::esec(int t){
	
	int z = qnAyarla();


	if (t<z && t>1 && ebob(t, z) == 1)
	{  
		cout << "e degeri="<<t<<endl;
	}
	else
	{
		cout << "Yanlis e degeri girdiniz...";
			abort();
		//t = 3;   // 2 atamadım çünkü asalların çarpımından çift bir sayı çıkacak ve p ve q hesaplamasından Q(n) bulunabilecekti.
		//cout << "e sayisi qn ve 1 i asti.Yeni e atandi="  <<t<< endl;
	}
	e = t;
	return t;
}

int RSA::dOlustur()
{
	int z = 0;
	for (i = 0; i < 1000; i++)
	{
		z = modHesapla((e*d), qn);
	
		if (z != 1)
		{
			d++; 
		}
		if (z == 1 && e!=d)
		{
			cout << "d degeri=" << d<<endl;
			break;
		}
		
	}
	return d;

}


string RSA::ciphermetin(string f){

	int nn = nAyarla();
	

	char *y = new char[f.length() + 1];
	strcpy(y, f.c_str());
    
	double *ddizi = new double[f.length() + 1];

	
	for (i = 0; i < f.length(); i++)
	{
		cout << y[i];
	
	}
	cout << endl;
	//ASCII degerine dönderdik.
	for (i = 0; i < f.length(); i++){
		switch (y[i])
		{
		case 'a':
			
		{	dizi[0]= y[i]-87;
		ddizi[i] = dizi[0];

		break;
		}
		case 'b':
		{	dizi[1] = y[i]-87;
		ddizi[i] = dizi[1];
	
		break;
		}
		case 'c':
		{	dizi[2] = y[i]-87;
		ddizi[i] = dizi[2];
	
		
		break;
		}
		case 'd':
		{	dizi[3] = y[i]-87;
		ddizi[i] = dizi[3];
	
		break;
		}
		case 'e':
		{	dizi[4] = y[i]-87;
		ddizi[i] = dizi[4];
		
		break;
		}
		case 'f':
		{	dizi[5] = y[i]-87;
		ddizi[i] = dizi[5];
		
		break;
		}
		case 'g':
		{	dizi[6] = y[i]-87;
		ddizi[i] = dizi[6];
		
		break;
		}
		case 'h':
		{	dizi[7] = y[i]-87;
		ddizi[i] = dizi[7];
		break;
		}
		case 'i':
		{	dizi[8] = y[i]-87;
		ddizi[i] = dizi[8];
		
		break;
		}
		case 'j':   //10
		{	dizi[9] = y[i]-87;
		ddizi[i] = dizi[9];
	
		break;
		}
		case 'k':
		{	dizi[10] = y[i]-87;
		ddizi[i] = dizi[10];
	
		break;
		}
		case 'l':
		{	dizi[11] = y[i]-87;
		ddizi[i] = dizi[11];
		
		break;
		}
		case 'm':
		{	dizi[12] = y[i]-87;
		ddizi[i] = dizi[12];
		
		break;
		}
		case 'n':
		{	dizi[13] = y[i]-87;
		ddizi[i] = dizi[13];
		
		break;
		}
		case 'o':
		{	dizi[14] = y[i]-87;
		ddizi[14] = dizi[14];
	
		break;
		}
		case 'p':
		{	dizi[15] = y[i]-87;
		ddizi[i] = dizi[15];
		
		break;
		}
		case 'q':
		{	dizi[16] = y[i]-87;
		ddizi[i] = dizi[16];
	
		break;
		}
		case 'r':
		{	dizi[17] = y[i]-87;
		ddizi[i] = dizi[17];
		
		break;
		}
		case 's':
		{	dizi[18] = y[i]-87;
		ddizi[i] = dizi[18];
		
		break;
		}
		case 't': //20
		{	dizi[19] = y[i]-87;
		ddizi[i] = dizi[19];
	
		break;
		}
		case 'u':
		{	dizi[20] = y[i]-87;
		ddizi[i] = dizi[20];
		
		break;
		}
		case 'v':
		{	dizi[21] = y[i]-87;
		ddizi[i] = dizi[21];
	
		break;
		}
		case 'w':
		{	dizi[22] = y[i]-87;
		ddizi[i] = dizi[22];
		
		break;
		}
		case 'x':
		{	dizi[23] = y[i]-87;
		ddizi[i] = dizi[23];
		
		break;
		}
		case 'y':
		{	dizi[24] = y[i]-87;
		ddizi[i] = dizi[24];
	
		break;
		}
		case 'z':
		{	dizi[25] = y[i]-87;
		ddizi[i] = dizi[25];
		
		break;
		}
		default:
		{	cout << "Yanlis deger girildi...\n";
		break;
		}
			
		}
	}
	cout << "\n";
	cout << "Sifresiz metin=\n";
	for (i = 0; i < f.length(); i++)
{
		cout << ddizi[i];
	
}
	cout << "\n";
	
	cout << "Ciphermetin==\n";
	for (i = 0; i < f.length(); i++)
{
		
		 cipherdizi[i] = mod((int)ddizi[i], e, nn);
		cout <<cipherdizi[i];
}	
	
	cout << "\n";
	s = f;
	return f;
}

void RSA::deciphermetin(){
	
	int *xdizi = new int[s.length() + 1];
	char*dcdizi = new char[s.length() + 1];
	int yy = nAyarla();
	cout << "Aciga cikarilmis sifre:\n";
	for (i = 0; i < s.length(); i++)
	{
		decipherdizi[i] = mod(cipherdizi[i], d, yy);
			cout << decipherdizi[i];
	}
	for (i = 0; i < s.length(); i++){
		switch (decipherdizi[i])
		{
		case 10:
		{
				   dcdizi[i]= harf[0];
		break;
		}
		case 11:
		{	
				   dcdizi[i]= harf[1];
		
		break;
		}
		case 12:
		{	
				   dcdizi[i]= harf[2];
		break;
		}
		case 13:
		{	
					dcdizi[i]= harf[3];
		break;
		}
		case 14:
		{
					dcdizi[i]= harf[4];
		break;
		}
		case 15:
		{	
					dcdizi[i]= harf[5];
		break;
		}
		case 16:
		{	
					dcdizi[i]= harf[6];
		break;
		}
		case 17:
		{	
					dcdizi[i]= harf[7];
		break;
		}
		case 18:
		{	
					dcdizi[i]= harf[8];
		break;
		}
		case 19:   //10
		{	
		
				dcdizi[i]= harf[9];
		break;
		}
		case 20:
		{	
					dcdizi[i]= harf[10];
		break;
		}
		case 21:
		{	
					dcdizi[i]= harf[11];
		break;
		}
		case 22:
		{	
					dcdizi[i]= harf[12];
		break;
		}
		case 23:
		{	
					dcdizi[i]= harf[13];
		break;
		}
		case 24:
		{	
					dcdizi[i]= harf[14];
		break;
		}
		case 25:
		{	
					dcdizi[i]= harf[15];
		break;
		}
		case 26:
		{	
					dcdizi[i]= harf[16];
		break;
		}
		case 27:
		{	
					dcdizi[i]= harf[17];
		break;
		}
		case 28:
		{	
					dcdizi[i]= harf[18];
		break;
		}
		case 29: //20
		{	
					  dcdizi[i]= harf[19];
		break;
		}
		case 30:
		{	
					dcdizi[i]= harf[20];
		break;
		}
		case 31:
		{	
					dcdizi[i]= harf[21];
		break;
		}
		case 32:
		{
					dcdizi[i]= harf[22];
		break;
		}
		case 33:
		{	
					dcdizi[i]= harf[23];
		break;
		}
		case 34:
		{	
					dcdizi[i]= harf[24];
		break;
		}
		case 35:
		{	
					dcdizi[i]= harf[25];
		break;
		}
		default:
		{	cout << "Yanlis deger girildi...\n";
		break;
		}

		}
	}
	cout << "\nAciga cikarilmis metin" << endl;
	for (i = 0; i < s.length(); i++)
	{
		cout << dcdizi[i];


	}
	cout << endl;
}
