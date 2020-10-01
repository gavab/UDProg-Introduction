#include "std_lib_facilities.h"

int main()
{
	constexpr double cm_to_meter = 0.01;
	constexpr double in_to_m = 0.0254;
	constexpr double ft_to_m=0.3048;
	

	vector<double> adatok;

	string unit="";
	
	double meterben=0;	
	double ertek=0;
	double max_ertek=numeric_limits<double>::lowest();
	double min_ertek=numeric_limits<double>::max();
	double sum=0;

	cout <<"Írd be az értékeket mértékegységekkel! (elfogadott mértékegységek: cm,m,ft,in)\n"; 
	
	while(cin >> ertek >> unit)
	{
		if(unit != "cm" && unit != "m" && unit != "in" && unit != "ft")
				cout << "Wrong or invalid unit" << endl;
		
		
		else
		{
			if (unit=="cm")
				meterben=ertek*cm_to_meter;
			
			else if(unit=="m")
				meterben=ertek;
			
			else if(unit=="in")
				meterben=ertek*in_to_m;
			
			else if(unit=="ft")
				meterben=ertek*ft_to_m;

			if (meterben > max_ertek || meterben == max_ertek )
			{		
				max_ertek = meterben;
			}	

			if (meterben < min_ertek || meterben == min_ertek)
			{			
				min_ertek = meterben;
			}

			sum +=meterben;

			adatok.push_back(meterben);
		
		}
	}

	cout << "Smallest value= " << min_ertek << "m" << endl;
	cout <<"Largest value= " << max_ertek << "m" << endl;
	cout << "Sum of value= " << sum << "m" << endl;
	cout <<"Numbers of value " << adatok.size() << endl;

	sort(adatok);

	for (auto a :adatok)
		cout << a << " m" <<endl;
	

	return 0;
}