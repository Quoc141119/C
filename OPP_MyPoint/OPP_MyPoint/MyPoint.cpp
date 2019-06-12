#include "MyPoint.h"
#include <iostream>
#include <math.h>


MyPoint::MyPoint(int x, int y)
{
	this->SetX(x);
	this->SetY(y);
}

MyPoint::MyPoint()
{
}

void MyPoint::Display()
{
	std::cout << mPosX << " " << mPosY << std::endl;
}

MyPoint::~MyPoint()
{
}
