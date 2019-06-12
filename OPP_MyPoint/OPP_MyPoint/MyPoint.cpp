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

void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

float MyPoint::Distance(MyPoint p)
{
	return sqrt(pow((this->GetX() - p.GetX()), 2) + pow((this->GetY() - p.GetY()), 2));
}

MyPoint::~MyPoint()
{
}
