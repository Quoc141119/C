#include <stdio.h>
#include <cstdlib>
#include "Patient.h"

int main()
{
	Patient p;
	char t = 0;
	while (p.GetState() == 1)
	{
		if (p.Getsizeofvr() == 0)
		{
			break;
		}
		printf("Take Medicine (0 = NO, 1 = YES: ");
		cin >> t;
		if (t == 49)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "medicine_resistance: " << medicine_resistance << endl;
			p.TakeMedicine(medicine_resistance);
			cout << "Patient resistance: " << p.Getresistance() << endl;
		}
		else if(t==48)
		{
			break;
		}
		else
		{
			cout << "Input again: ";
			continue;
		}
	}
	if (p.GetState() == 0)
	{
		cout << "Patient dead\n";
	}
	else
	{
		cout << "Patient live\n";
	}
	system("pause");
}