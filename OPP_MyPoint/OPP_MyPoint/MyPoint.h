#pragma once
class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int x, int y);
	~MyPoint();
	void Display();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	float Distance(MyPoint p);
};

