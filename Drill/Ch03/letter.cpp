#include "std_lib_facilities.h"

int main()
{

	cout << "Kérlek add meg a címzett kersztnevét!\n";

	string first_name;
	cin >> first_name;

	cout << "Hello, " << first_name << "!" << endl;
	cout << "\t" <<"Hogy vagy? Én jól vagyok. Rég találkoztunk jó lenne már összefutni valamikor.\n";
	cout << "Most kezdtem az egyetemet, ami nagyon jó és örülök neki.\n";
	cout << "Ha jössz valamikor elmehetnénk kajálni a kedvenc helyedre.\n";
	cout << "Meg a többiekkel is összefuthatnánk ők is hiányolnak!\n";

	cout << "Adj meg egy másik keresznevet!\n";

	string friend_name;
	cin >> friend_name;

	cout << "Láttad mostanában " << friend_name <<"-et ?\n"; 

	cout << "Add meg a barátod nemét! (m vagy f)\n";

	char friend_sex = 0;
	cin >> friend_sex;

		if (friend_sex =='m')
		{
			cout << "If you see " << friend_name << " please ask him to call me." << endl;
 		}

 		if (friend_sex=='f')
 		{
 			cout << "If you see " << friend_name << " please ask her to call me." << endl;
 		}

 	cout << "Add meg a barátod életkorát!\n";

 	int age = 0;
 	cin >> age;

 	if (0 >= age || age >= 110) simple_error("you're kidding!");

 	if(age < 12)
 		cout << "Jövőre " << age+1 << " leszel." << endl; 

 	if (age == 17)
 		cout << "Jövőre szavazhatsz." << endl;
 	
 	if (age > 70)
 		cout << "Élvezd a nyugdíjas éveket." << endl;
 		
 	cout << "Yours sincerely, " << endl;

 	cout <<"\n";
 	cout <<"\n";

 	cout <<"Bence\n";

	return 0;
}