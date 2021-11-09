#include <iostream>

using namespace std;

struct Employee {
	string name;
	int gender;
	int workingYears;
	int level;
};

int main()
{
	int N;
	Employee es[100];

	cout << "So luong nhan vien: ";
	cin >> N;

	for (int i = 0; i < N; i++) {
		cout << "Ten nhan vien " << i + 1 << ": ";
		cin >> es[i].name;

		cout << "Gioi tinh (Nam: 0, nu: 1): ";
		cin >> es[i].gender;

		cout << "So nam lam viec: ";
		cin >> es[i].workingYears;

		do {
			cout << "Level: ";
			cin >> es[i].level;
		} while (es[i].level < 15);
	}

	cout << endl << "Danh sach nhan vien: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "Nhan vien " << i + 1 << ": " << endl;
		cout << "	Ten: " << es[i].name << endl;
		if (es[i].gender == 0) cout << "	Gioi tinh: Nam" << endl;
		else cout << "	Gioi tinh: Nu" << endl;
		cout << "	So nam lam viec: " << es[i].workingYears << endl;
		cout << "	Level: " << es[i].level << endl;
	}

	return 0;
}