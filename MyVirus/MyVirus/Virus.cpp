#include "Virus.h"



Virus::Virus()
{
}

Virus::Virus(Virus *vr)
{
	this->m_dna = vr->m_dna;
	this->m_resistance = vr->m_resistance;
}

void Virus::LoadADNInformation()
{

}

void Virus::ReduceResistance()
{

}

Virus::~Virus()
{
	if (m_dna == nullptr)
	{
		delete[]m_dna;
	}
}

void Virus::DoBorn()
{

}

void Virus::DoClone()
{

}

void Virus::DoDie()
{

}

void Virus::InitResistance()
{

}



