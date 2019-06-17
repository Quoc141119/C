#include "Patient.h"
#include "Virus.h"



int Patient::Getresistance()
{
	return this->m_resistance;
}

int Patient::Getsizeofvr()
{
	return this->m_virusList.size();
}

int Patient::SumResistanceofvirus()
{
	int sum = 0;
	auto vr = this->m_virusList.begin();
	int size = m_virusList.size();
	for (int i = 0; i < size; i++)
	{
		sum += (*vr)->Getresistance();
	}
	return sum;
}

void Patient::InitResistance()
{
	m_resistance = rand() % 8001 + 1000;
}

void Patient::DoStart()
{
	int total = rand() % 11 + 10;
	this->m_state = 1;
	for (int i = 0; i < total; i++)
	{
		Virus *vr;
		int typevr = rand() % 2 + 1;
		if (typevr == 1)
		{
			vr = new VirusFlu();
			cout << "VirusFlu ";
			cout << vr->Getresistance() << endl;
		}
		else
		{
			vr = new VirusDengue();
			cout << "VirusDengue ";
			cout << vr->Getresistance() << endl;
		}
		m_virusList.push_back(vr);
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	if (this->SumResistanceofvirus() > this->m_resistance)
	{
		this->m_state = 0;
		return;
	}
	auto vr = this->m_virusList.begin();
	int size = m_virusList.size();
	for (int i = 0; i < size; i++)
	{
		if ((*vr)->ReduceResistance(medicine_resistance) > 0)
		{
			cout << "HP: " << (*vr)->Getresistance() << " ";
			list<Virus*> listclone = (*vr)->DoClone();
			this->m_virusList.insert(m_virusList.end(), listclone.begin(), listclone.end());
			vr++;
		}
		else
		{
			(*vr)->DoDie();
			this->m_virusList.erase(vr++);
		}
	}
}

int Patient::GetState()
{
	return this->m_state;
}

Patient::Patient()
{
	Patient::DoStart();
	Patient::InitResistance();
}


Patient::~Patient()
{
}
