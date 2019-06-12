#include "Mypoint.h"
#include <iostream>
using namespace std;


int main()
{
	MyPoint *p1 = new MyPoint(1, 5);
	MyPoint *p2 = new MyPoint(6, 2);
	p1->Display();
	cout << p1->Distance(*p2) << endl;
	system("pause");
	return 0;
}