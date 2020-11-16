#include "std_lib_facilities.h"

int main()
{

	int birth_year=2000;

	cout << birth_year << "\t (decimal)\n"
	 << hex << birth_year << "\t (hexadecimal)\n"
	 << oct << birth_year <<"\t (octal)\n"
	 <<'\n';

	 cout << showbase << dec;

	 cout << birth_year<< "\t (decimal)\n"
	 << hex << birth_year << "\t (hexadecimal)\n"
	 << oct << birth_year <<"\t (octal)\n"
	 <<'\n';

	  cout << noshowbase << dec;

	  cout << 20 << endl;


	int a, b, c, d;

	  cin >> a >>oct >> b >> hex >> c >> d;
	cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;

	cout << dec;

	cout << 1234567.89 << "\t(defaultfloat)\n"
	 << fixed << 1234567.89 << "\t (fixed)\n"
	 << scientific << 1234567.89 << "\t (scientific)\n";

	   cout << '|' << setw(8) << "Gavallér" << '|' << setw(8) << "Bence" 
         << '|' << setw(24) << "gavallerb15@gmail.com"
         << '|' << setw(16) << "+36*********" << "|\n"
         << '|' << setw(8) << "Sütő" << '|' << setw(8) << "János"
         << '|' << setw(24) << "suto.janos@gmail.com"
         << '|' << setw(16) << "+36*********" << "|\n"
         << '|' << setw(8) << "Éles" << '|' << setw(8) << "István" 
         << '|' << setw(24) << "eles.istvan@gmail.com"
         << '|' << setw(16) << "+36*********" << "|\n"
         << '|' << setw(8) << "Elek" << '|' << setw(8) << "Péter"
         << '|' << setw(24) << "elek.peter@gmail.com"
         << '|' << setw(16) << "+36*********" << "|\n"
         << '|' << setw(8) << "Bezzegh" << '|' << setw(8) << "Szabolcs"
         << '|' << setw(24) << "bezzegh.szabi@gmail.com"
         << '|' << setw(16) << "+36*********" << "|\n";

	return 0;
}