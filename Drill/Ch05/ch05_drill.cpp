#include "std_lib_facilities.h"

int main()
try
{
	cout << "1. Success!\n";			
	cout << "2. Success!\n";			
	cout << "3. Success" << "!\n";		
	cout << "4. success" << '\n';		

	int res = 7; 					
	vector<int> v5(10);
	v5[5] = res;
	cout << "5. Success!\n";

	vector<int> v6(10); 				
	v6[5] = 7; 
	if (v6[5]==7) 
		cout << "6. Success!\n";
	
	bool cond =true; 				
	if (cond) 
		cout << "7. Success!\n"; 
	else 
		cout << "Fail!\n";

	bool c8 = true;					
	if (c8) 
		cout << "8. Success!\n"; 
	else 
		cout << "Fail!\n";

	string s = "ape";
	bool c9 = "fool"<s; 
	if (!c9) 
		cout << "9. Success!\n";

	string s10 = "ape";
	if (s10!="fool") 
		cout << "10. Success!\n";

	string s11 = "ape";
	if (s11!="fool") 
		cout << "11. Success!\n";
	
	string s12 = "ape"; 
	if (s12!="fool") 
		cout << "12. Success!\n";

	vector<char> v13(5); 
	for (int i=0; i<v13.size(); ++i) 
		cout << "13. Success!\n";

	vector<char> v14(5);
	for (int i=0; i<=v14.size(); ++i)
	  cout << "14. Success!\n";

	string s15 = "15. Success!\n";
	for (int i=0; i<s15.size(); ++i) 
		cout << s15[i];

	if (true) 
		cout << "16. Success!\n"; 
	else 
		cout << "Fail!\n";

	int x = 2000;
	int c = x; 
	if (c==2000) 
		cout << "17. Success!\n";

	string s18 = "18. Success!\n";
	for (int i=0; i<s18.size(); ++i) 
		cout << s18[i];

	vector<int> v19(5); 
	for (int i=0; i<=v19.size(); ++i)  
		cout << "19. Success!\n";

	int i = 0; 
	int j = 9; 
	while (i<10) 
		++i;
	if (j<i) 
		cout << "20. Success!\n";
		
	double x21 = 2; 
	double d21 = 5/x21+2 ; 
	if (d21==2*x21+0.5)
	 	cout << "21. Success!\n";

	 string s22 = "22. Success!\n"; 
	 for (int i=0; i<=s22.size(); ++i)
	  	cout << s22[i];	

	int i23=0; 
	int j23=0; 
	while (i23<10) ++i23; 
	if (j23<i23)
	 cout << "23. Success!\n";

	double x24 = 4; 
	double d24 = 5/(x24-2) ; 
	if (d24==x24/2+0.5)
	 cout << "24. Success!\n"; 

	cout << "25. Success!\n";  		

	return 0;
}
catch (exception&e)
{
	cerr << "error: " << e.what() <<'\n';

	return 1;
}
catch(...)
{
	cerr << "Unknown exception!\n";
	return 2;
}
