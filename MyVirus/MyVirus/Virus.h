#pragma once
#include <list>
#include <fstream>
#include <iostream>
using namespace std;


class Virus
{
private:
	char *m_dna;
	int m_resistance;
public:
	Virus();
	Virus(const Virus *vr);
	void Setresistance(int resistance);
	int Getresistance();
	void LoadADNInformation();
	int ReduceResistance(int medicine_esistance);
	~Virus();
	virtual void DoBorn() {};
	virtual list<Virus*> DoClone() = 0;
	virtual void DoDie() {};
	virtual void InitResistance() {};
};

