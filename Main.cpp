#include <iostream>
#include "CString.h"
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	cout << "������� ������: ";
	string a;
	getline(cin, a);

	system("pause");
	return 0;
}