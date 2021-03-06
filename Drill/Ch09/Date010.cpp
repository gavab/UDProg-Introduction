#include "std_lib_facilities.h"

namespace UDChrono{

class Year{
	static constexpr int min=1800;
	static constexpr int max=2077;
public:
	class Invalid{};
	Year(int x): y{x} {if(x<min || x>max) throw Invalid{};}
	int year() {return y;}
	void increment() {y++;}
private:
	int y;
};

Year operator++(Year& year)
{
	year.increment();
}

ostream& operator<<(ostream& os, Year year)
{
	return os << year.year();
}

const vector<string> months=
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

enum class Month{
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m= (m==Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Date{
	Year year;
	Month month;
	int day;
public:
	class Invalid {}; 
	Date():year(Year{2001}), month(Month::jan), day(1) {}
	Date(Year y, Month m, int d): year(y), month(m), day(d) {if(!is_valid()) throw Invalid{};}
	bool is_valid();
	void add_day(int n);
	Year get_year() const {return year;}
	Month get_month() const {return month;}
	int get_day() const {return day;}

};

bool Date::is_valid()
{
	if(day <1 || day >31)
		return false;

	return true;	
}


/*Date::Date(int y, int m, int d)
{
	if(y>0)
		year=y;
	else
		error("invaid year");
	if(m<=12&& m>0)
		month=m;
	else
		error("invaid month");
	if(d>0 && d<=31)
		day=d;
	else
		error("invaid day");

}
*/
void Date::add_day(int n)
{
	day += n;
	if(day>31)
	{
		++month;
		day-=31;
		if(month==Month::jan)
		{
			++year;
		}
	}
}

} // UDChrono end!
int main()
try{

	UDChrono::Date today {UDChrono::Year{1978},UDChrono::Month::jun,25};
	
	cout << "Date:" << today.get_year() << ". " << today.get_month() << ' ' << today.get_day() << '.' << endl;
	
	//today.add_day(1);


	UDChrono::Date tomorrow {today};

	tomorrow.add_day(1);

	cout << "Date:" << tomorrow.get_year() << ". " << tomorrow.get_month() << ' ' << tomorrow.get_day() << '.' << endl;

	/*cout << "Vector!\n";
	vector<UDChrono::Date> dates(10);
	for(const auto& date : dates)
		cout << "Date:" << date.get_year() << ". " << date.get_month() << ' ' << date.get_day() << '.' << endl;

*/
	

	return 0;
}catch(UDChrono::Date::Invalid)
	{
		cerr << "Invaid date"<< endl;
		return 1;
	}
catch(UDChrono::Year::Invalid)
{
	cerr << "Invaid date"<< endl;
	return 1;
}	 
	 
catch(exception& e)
	{
		cerr << e.what()<< endl;
		return 2;
	}	