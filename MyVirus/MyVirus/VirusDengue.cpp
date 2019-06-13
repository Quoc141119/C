#include "VirusDengue.h"
#include <cstdlib>
#include <string>


VirusDengue::VirusDengue():Virus()
{
	DoBorn();
	InitResistance();
}

char* VirusDengue::Getm_protein()
{
	return m_protein;
}

void VirusDengue::DoBorn()
{
	LoadADNInformation();
	int rd = rand() % 3 + 1;
	if (rd == 1)
	{
		strcpy(m_protein, "NS3");
	}
	else
	{
		if (rd == 2)
		{
			strcpy(m_protein, "NS5");
		}
		else
		{
			strcpy(m_protein, "E");
		}
	}
}
Virus* VirusDengue::DoClone(Virus *vr)
{

}

void VirusDengue::DoDie()
{

}

void VirusDengue::InitResistance()
{
	if (Getm_protein() == "NS3")
	{
		Setm_resistance(rand() % 10 + 1);
	}
	else
	{
		if (strcmp(Getm_protein(),"NS5"))
		{
			Setm_resistance(rand() % 10 + 11);
		}
		else
		{
			Setm_resistance(rand() % 10 + 21);
		}
	}
}

VirusDengue::~VirusDengue()
{
}
