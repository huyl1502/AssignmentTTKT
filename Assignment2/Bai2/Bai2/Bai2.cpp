#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
template<class T>
T cong(const T& a, const T& b) {
	return a + b;
}
template<class T>
T tru(const T& a, const T& b) {
	return a - b;
}
template<class T>
T nhan(const T& a, const T& b) {
	return a * b;
}
template<class T>
void chia(const T& a, const T& b) {
	if (b != 0)
		cout << (float)a / b << setprecision(7) << fixed << endl;
	else cout << "khong chia duoc" << endl;
}
int mod(const int& a, const int& b) {
	return a % b;
}

int main()
{
	int a, b;
	char opt;
	char c;

	do {
		cout << "-----------------------" << endl;
		cout << "c. Continue" << endl;
		cout << "e. Exit" << endl;
		cout << "Chon: "; cin >> c;

		if (c == 'c') {
			cout << "Nhap phep tinh: ";
			cin >> a >> opt >> b;

			switch (opt)
			{
			case '+':
				cout << cong(a, b) << endl;
				break;
			case '-':
				cout << tru(a, b) << endl;
				break;
			case '*':
				cout << nhan(a, b) << endl;
				break;
			case '/':
			{
				chia(a, b);
				break;
			}

			case '%':
				cout << mod(a, b) << endl;
				break;

			default:
				cout << "khong hop le" << endl;
				break;
			}
		}
	} while (c != 'e');

	return 0;
}