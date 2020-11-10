#include "std_lib_facilities.h"

void swap_v(int a,int b)
{
	int temp =a;
	a=b;
	b=temp;
}

void swap_r(int& a,int& b)
{
	int temp =a;
	a=b;
	b=temp;
}

/*void swap_cr(const int& a,const int& b)
{
	int temp;
	temp=a,a=b;
	b=temp;
}
*/

int main()
{
	int x=7;
	int y=9;

	cout << "x= " << x << " y= " << y << endl;

	swap_v(x,y);
	cout << "x= " << x << " y= " << y << endl;

	swap_r(x,y);
	cout << "x= " << x << " y= " << y << endl;

	//swap_cr(x,y);
	cout << "x= " << x << " y= " << y << endl;

	/*swap_v(7,9);
	cout << "swap_v(7,9)"<<swap_v(7,9)<< endl;

	swap_r(7,9);
	cout << "swap_r(7,9)"<<swap_r(7,9)<< endl;

	swap_cr(7,9);
	cout << "swap_cr(7,9)"<<swap_cr(7,9)<< endl;*/
	
	const int cx=7;
	const int cy=9;
	
	cout << "cx= " << cx << " cy= " << cy << endl;
	
	swap_v(cx,cy);
	cout << "cx= " << cx << " cy= " << cy << endl;
	
	//swap_r(cx,cy);
	cout << "cx= " << cx << " cy= " << cy << endl;
	
	//swap_cr(cx,cy);
	cout << "cx= " << cx << " cy= " << cy << endl;
	
	/*swap_v(7.7,9.9);
	cout << "swap_v(7.7,9.9) " << swap_v(7.7,9.9) << endl;
	
	swap_r(7.7,9.9);
	cout << "swap_r(7.7,9.9) " << swap_r(7.7,9.9) << endl;
	
	swap_cr(7.7,9.9);
	cout << "swap_cr(7.7,9.9) " << swap_cr(7.7,9.9) << endl;
	*/
	
	
	double dx=7.7;
	double dy=9.9;
	
	cout << "dx= " << dx << " dy= " << dy << endl;
	
	swap_v(dx,dy);
	cout << "dx= " << dx << " dy= " << dy << endl;
	
	//swap_r(dx,dy);
	cout << "dx= " << dx << " dy= " << dy << endl;
	
	//swap_cr(dx,dy);
	cout << "dx= " << dx << " dy= " << dy << endl;
	
	/*swap_v(7.7,9.9);
	cout << "swap_v(7.7,9.9) "<<swap_v(7.7,9.9) << endl;
	
	swap_r(7.7,9.9);
	cout << "swap_r(7.7,9.9) "<<swap_r(7.7,9.9) << endl;
	
	swap_cr(7.7,9.9);
	cout << "swap_cr(7.7,9.9) "<<swap_v(7.7,9.9) << endl;
	*/
	
	return 0;

}
