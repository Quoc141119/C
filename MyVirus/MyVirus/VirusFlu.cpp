#include "VirusFlu.h"
#include <cstdlib>
using namespace std;



VirusFlu::VirusFlu():Virus()
{
	VirusFlu::DoBorn();
	VirusFlu::InitResistance();
}

VirusFlu::VirusFlu(const VirusFlu *virusflu):Virus(virusflu)
{
	this->m_color = virusflu->m_color;
}

void VirusFlu::Setcolor(int _color)
{
	this->m_color = _color;
}

int VirusFlu::Getcolor()
{
	return this->m_color;
}

void VirusFlu::DoBorn()
{
	Virus::LoadADNInformation();
	int rd = rand() % 2 + 1;
	if (rd == 1)
	{
		m_color = 0x0000ff;
	}
	else
	{
		m_color = 0xff0000;
	}
}


list<Virus *> VirusFlu::DoClone()
{
	cout << "clone VirusFlu\n";
	Virus *newvr = new VirusFlu(this);
	list<Virus*> newlistvr;
	newlistvr.push_back(newvr);
	return newlistvr;
}

void VirusFlu::DoDie()
{
	delete this;
}


void VirusFlu::InitResistance()
{
	if (Getcolor() == 0x0000ff)
	{
		cout << "blue  ";
		Setresistance(rand() % 6 + 10);
	}
	else
	{

		cout << "red  ";
		Setresistance(rand() % 11 + 10);
	}
}

VirusFlu::~VirusFlu()
{
}
