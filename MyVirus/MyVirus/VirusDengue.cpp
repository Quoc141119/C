#include "VirusDengue.h"
#include <cstdlib>
#include <string>


VirusDengue::VirusDengue():Virus()
{
	VirusDengue::DoBorn();
	VirusDengue::InitResistance();
}

VirusDengue::VirusDengue(const VirusDengue *virusdengue):Virus(virusdengue)
{
	for (int i = 0; i < strlen(virusdengue->m_protein); i++)
	{
		this->m_protein[i] = virusdengue->m_protein[i];
	}
}

char* VirusDengue::Getprotein()
{
	return this->m_protein;
}

void VirusDengue::Setprotein(char a[4])
{
	strcpy_s(this->m_protein, a);
}

void VirusDengue::DoBorn()
{
	Virus::LoadADNInformation();
	int rd = rand() % 3 + 1;
	if (rd == 1)
	{
		cout << "NS3 ";
		Setprotein("NS3");
	}
	else
	{
		if (rd == 2)
		{
			cout << "NS5 ";
			Setprotein("NS5");
		}
		else
		{
			cout << "E ";
			Setprotein("E");
		}
	}
}

list<Virus *> VirusDengue::DoClone()
{
	cout << "clone VirusDengue\n";
	VirusDengue *newvr = new VirusDengue(this);
	list<Virus *> newlistvr;
	newlistvr.push_back(newvr);
	newvr = new VirusDengue(this);
	newlistvr.push_back(newvr);
	return newlistvr;
}


void VirusDengue::DoDie()
{
	delete this;
}


void VirusDengue::InitResistance()
{
	if (Getprotein() == "NS3")
	{
		Setresistance(rand() % 10 + 1);
	}
	else
	{
		if (strcmp(Getprotein(),"NS5"))
		{
			Setresistance(rand() % 10 + 11);
		}
		else
		{
			Setresistance(rand() % 10 + 21);
		}
	}
}

VirusDengue::~VirusDengue()
{
}
