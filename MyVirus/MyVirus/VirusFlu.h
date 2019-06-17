#pragma once
#include "Virus.h"

class VirusFlu : public Virus
{
private:
	int m_color;
public:
	VirusFlu();
	VirusFlu(const VirusFlu *virusflu);
	void Setcolor(int _color);
	int Getcolor();
	~VirusFlu();
	void DoBorn() override;
	list<Virus *> DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

