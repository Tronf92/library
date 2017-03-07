#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <string.h>
using namespace std;
void introducere_date();
int numar;

char nume_fisier[100],s3[103];

class meniu{
public:
	void initializare();
	void schimbare();

};

class piese{
public:
	int ID;
	int pret;
	char vanzator[100];
	char tip[100];
};
piese piesa;

void meniu::initializare(){
	do{
		cout << "1.Piesa noua. " << endl;
		cout << "0.Iesire. " << endl;
	}while(numar!=0);
}
void meniu::schimbare(){
	cin >> numar;
	switch (numar)
	{
	case 0:
		break;
	case 1:
		introducere_date();
		break;

	default:
		cout << "Optiune gresita" << endl;
		break;
	}
}

class file{
public:
	void create(){
		cout << "introdu numele fisierului" << endl;
		fflush(stdin);
		gets(nume_fisier);
		strcpy(s3,nume_fisier);
		strcpy(s3,"txt");
		ofstream ofs;
		ofs.open(nume_fisier, ios::app);
		ofs  << piesa.ID << endl << piesa.pret << endl << piesa.vanzator << endl << piesa.tip << endl;
		time_t now = time(0);
		tm *lctime=localtime(&now);
		ofs << asctime(lctime);
		ofs.close();
		

	}
};

void introducere_date(){
	cout << "Introdu codul piesei. " << endl;
	cin >> piesa.ID;
	cout << "Introdu pretul piesei. " << endl;
	cin >> piesa.pret;
	cout << "Introdu vanzatorul. " << endl;
	fflush(stdin);
	gets(piesa.vanzator);
	cout << "Introdu modelul piesei. " << endl;
	fflush(stdin);
	gets(piesa.tip);
}

int main(){
	meniu mn;
	file ofs;
	mn.initializare();
	mn.schimbare();
	
	ofs.create();
	

	system("pause");
	return 0;

}

	

	