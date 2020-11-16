#include "std_lib_facilities.h"

struct Point
{
	int x;
	int y;
	
};
bool operator==(const Point& lhs, const Point& rhs)
{
    return ((lhs.x == rhs.x && (lhs.y == rhs.y)));
}

int main()
try{
	vector<Point> original_points;

	int x=0;
	int y=0;

	while(cin >> x >> y)
	{
		original_points.push_back(Point{x,y});
	}

	for(const auto& op : original_points)
		cout << op.x << ' ' << op.y << endl;


	
	string oname="mydata.txt";
	

	ofstream ost {oname};

	if(!ost) error("can't open output file",oname);
	
	for(const auto& op : original_points)
		ost << op.x << ' ' << op.y << endl;

	ost.close();

	
	cout<<"Processed points"<<endl;

	string iname="mydata.txt";
	

	ifstream ist {iname};

	
	if(!ist) error("Can't open input file",iname);

	vector<Point> processed_points;

	while(ist >> x >> y)
	{
		processed_points.push_back(Point{x,y});
	}

	for(const auto& pp: processed_points)
		cout << pp.x << ' ' << pp.y << endl;

	//original_points[2] = Point{-1, -1};

	if(original_points != processed_points)
		cerr<<"Something wrong!";


	return 0;
}catch(exception& e)
{
	cerr << e.what()<<endl;
	return 1;
}catch(...)
{
	cerr << "Unknown error";
	return 2;
}
