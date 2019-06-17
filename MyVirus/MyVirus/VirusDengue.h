#pragma once
#include "Virus.h"
#include <string>

class VirusDengue:public Virus
{
private:
	char m_protein[4];
public:
	VirusDengue();
	VirusDengue(const VirusDengue *virusdengue);
	char* Getprotein();
	void Setprotein(char a[4]);
	~VirusDengue();
	void DoBorn();
	list<Virus*> DoClone();
	void DoDie();
	void InitResistance();
};

