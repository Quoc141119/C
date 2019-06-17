#include "Virus.h"
using namespace std;

Virus::Virus()
{
}

void Virus::Setresistance(int resistance)
{
	m_resistance = resistance;
}

int Virus::Getresistance()
{
	return m_resistance;
}

Virus::Virus(const Virus *vr)
{
	m_dna = vr->m_dna;
	m_resistance = vr->m_resistance;
}

void Virus::LoadADNInformation()
{
	ifstream fileinput;
	fileinput.open("ATGX.bin");
	if (fileinput.is_open())
	{
		char a[100];
		fileinput >> a;
		m_dna = (char *) a;
	}
	else
	{
		cout << "file isn't open";
	}
	fileinput.close();
}

int Virus::ReduceResistance(int medicien_resistance)
{
	this->m_resistance = this->m_resistance - medicien_resistance;
	return this->m_resistance;
}

Virus::~Virus()
{
}


