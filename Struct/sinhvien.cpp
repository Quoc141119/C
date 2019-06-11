#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int Menu();
void Input();
void Display();
int CheckId(int);
int CheckScore(float);
void SaveFile();
void LoadFile();

struct Student{
	int id;
	string name;
	float score;
};

Student sv[100];

int Menu() {
	int choose;
	cout << "----------------------MENU----------------------\n";
	cout << setw(10) << right << "1." << " Input\n";
	cout << setw(10) << right << "2." << " Display\n";
	cout << setw(10) << right << "3." << " Save to file\n";
	cout << setw(10) << right << "4." << " Load from file\n";
	cout << setw(10) << right << "0." << " Exit\n";
	cout << "------------------------------------------------\n";
	cout << "Choose: ";
	cin >> choose;
	return choose;
}

void Input() {
	Student *student = sv;
	int id;
	string name;
	float score;
	int max;
	cout << "Input number of student: ";
	cin >> max;
	for (int i = 0; i < max; i++) {
		do {
			cout << "ID: ";
			cin >> id;
		} while (CheckId(id) == 1);
		student->id = id;
		cin.ignore();
		cout << "Name: ";
		getline(cin, student->name);
		do {
			cout << "Score: ";
			cin >> score;
		} while (CheckScore(score) == 1);
		student->score = score;
		student++;
	}
}

void Display() {
	Student *student = sv;
	cout << setw(10) << left << "ID" << setw(20) << left << "NAME" << setw(10) << left << "SCORE" << endl;
	while(student->id != NULL) {
		cout << setw(10) << left << student->id << setw(20) << left << student->name << setw(10) << left << student->score << endl;
		student++;
	}
}

int CheckId(int id) {
	Student *student = sv;
	while (student->id != NULL) {
		if (student->id == id) {
			cout << "Id already.\n";
			return 1;
		}
		student++;
	}
	return 0;
}

int CheckScore(float score) {
	if (score<0.0 || score>10.0) {
		cout << "score not invalid.\n";
		return 1;
	}
	return 0;
}

void SaveFile() {
	Student *student = sv;
	ofstream outfile;
	outfile.open("Text.txt", ios::out);
	if (outfile.is_open()) {
		while (student->id != NULL) {
			outfile << student->id << " " << student->name << " " << student->score << endl;
			student++;
		}
	}
	else {
		cout << "file can't be open.\n";
	}
	outfile.close();
}

void LoadFile() {
	Student *student = sv;
	string line;
	ifstream infile;
	infile.open("Text.txt", ios::in);
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile >> line;
			int id = atoi(line.c_str());
			student->id = id;
			infile >> line;
			student->name = line;
			infile >> line;
			float score = atoi(line.c_str());
			student->score = score;
			student++;
		}
	}
	else {
		cout << "file can't be open.\n";
	}
	infile.close();
}

int main() {
	int choose = Menu();
	switch (choose) {
		case 0:
			break;
		case 1:
			Input();
			break;
		case 2:
			Display();
			break;
		case 3:
			SaveFile();
			break;
		case 4:
			LoadFile();
			break;
	}

	system("pause");
	return 1;
}