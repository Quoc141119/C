#pragma once
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	Virus(Virus *vr);
	void LoadADNInformation();
	void ReduceResistance();
	~Virus();
	virtual void DoBorn();
	virtual void DoClone();
	virtual void DoDie();
	virtual void InitResistance();
};

