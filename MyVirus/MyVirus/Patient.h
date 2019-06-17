#pragma once
#include "Virus.h"
#include "VirusDengue.h"
#include "VirusFlu.h"
#include <cstdlib>


using namespace std;

class Patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
public:
	int Getresistance();
	int Getsizeofvr();
	int SumResistanceofvirus();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
//	void DoDie();
	int GetState();
	Patient();
	~Patient();
};

