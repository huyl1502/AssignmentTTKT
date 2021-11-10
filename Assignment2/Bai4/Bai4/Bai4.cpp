#include<iostream>
#include<string>

using namespace std;
string formatString(string input)
{
	string s = input;
	while (s[0] == '0')
		s.erase(0, 1);
	return s;
}
int convertToInt(string s) {
	int n = s.length();
	int num1 = 0;
	for (int i = n - 1; i >= 0; --i) {
		num1 += (int)((s[i] - '0') * pow(2, n - i - 1));
	}
	return num1;
}
int max(int a, int b) {
	return a > b ? a : b;
}
string AND(string a, string b) {
	int i, j;
	i = a.length() - 1;
	j = b.length() - 1;
	int n = max(i, j);
	char* s = new char[n + 1];
	while (i >= 0 || j >= 0) {
		if (i >= 0 && j >= 0) s[n] = a[i] & b[j];
		else if (i < 0) s[n] = b[j];
		else if (j < 0) s[n] = a[i];
		if (n == 0) break;
		n--;
		i--;
		j--;
	}
	string rs = s;
	delete[] s;
	return rs;
}
//string OR(string a, string b) {
//
//}
//string XOR(string a, string b) {
//
//}
//string NOT(string a, string b) {
//
//}
//string LEFT_SHIFT(string a, string b) {
//
//}
//string RIGHT_SHIFT(string a, string b) {
//
//}

int main() {
	string a, b;
	char opt;
	string c;

	while (true) {
		//cout << ": ";
		cout << "Nhap a = "; cin >> a;
		cout << "Nhap b = "; cin >> b;
		cout << "Bitwise operator('<' : shift left, '>' : shift right) = "; cin >> opt;



		switch (opt)
		{
		case '&':
			cout << AND(a, b) << endl;
			break;
			/*case '|':
				cout << AND(a, b) << endl;
				break;
			case '^':
				cout << AND(a, b) << endl;
				break;
			case '~':
			{
				cout << AND(a, b) << endl;
				break;
			}

			case '>':
				cout << AND(a, b) << endl;
				break;
			case '<':
				cout << AND(a, b) << endl;
				break;*/
		default:
			cout << "khong hop le" << endl;
			break;
		}
		cout << "Press Enter to continue, 'exit' or 'quit' or 'done' to Exit" << endl;
		cin.ignore();
		getline(std::cin, c);
		if (c == "exit" || c == "quit" || c == "done") exit(0);
		else {
			c.clear();
			continue;
		}


		return 0;
	}
}