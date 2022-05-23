#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(const char* fName)
{
	char ch;
	ofstream f(fName, ios::binary);

	char x;
	do
	{
		cout << "Input char(ENG) >> ";
		cin >> x;
		f.write((char*)&x, sizeof(x));
		cout << "continue? (1(yes)/0(no)): "; cin >> ch;
	} while (ch == '1');
}

void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	ifstream f(fName, ios::binary);
	char x;
	while (f.read((char*)&x, sizeof(x)))
		cout << x << endl;
	cout << endl;
}

int Process(const char* fName, const char* tName)
{
	ifstream f(fName, ios::binary);
	ofstream t(tName, ios::binary);
	char x;
	int n = 0;
	while (f.read((char*)&x, sizeof(x)))

		if (x == 'i' || x == 'n' || x == 'f' || x == 'o' || x == 'r' 
			|| x == 'm' || x == 'a' || x == 't' || x == 'c' ) 
		{
			n ++;
			t.write((char*)&x, sizeof(x));
		}
	return n;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[6] = "f.dat";
	char tname[6] = "t.dat";

	Create(fname);
	Print(fname);
	Process(fname, tname);
	Print(tname);

	cin.get();
	return 0;
}

