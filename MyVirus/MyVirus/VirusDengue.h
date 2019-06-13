#pragma once
#include "Virus.h"
class VirusDengue:public Virus
{
private:
	char m_protein[4];
public:
	VirusDengue();
	char* Getm_protein();
	~VirusDengue();
	void DoBorn();
	Virus* DoClone(Virus *vr);
	void DoDie();
	void InitResistance();
};

