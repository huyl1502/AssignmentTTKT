#include<iostream>

using namespace std;

int toDec(int* inp, int len) {
	int rs = 0;
	for (int i = 0; i < len; i++) {
		rs += inp[i] * (pow(2, len - i - 1));
	}
	return rs;
}

void toBinary(unsigned int inp) {
	int binaryNum[32];
	int i = 0;
	while (inp > 0) {
		binaryNum[i] = inp % 2;
		inp = inp / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}

int* preProcess(string s, int len) {
	int s_len = s.length();
	int* rs = new int[len];

	if (s_len == len) {
		for (int i = 0; i < len; i++) {
			if (s[i] == '0') rs[i] = 0;
			else rs[i] = 1;
		}
		return rs;
	}

	for (int i = 0; i < len; i++) {
		rs[i] = 0;
	}
	int s_i;
	for (int i = len - 1; i >= len - s_len; i--) {
		s_i = s_len - (len - i);
		if (s[s_i] == '0') rs[i] = 0;
		else rs[i] = 1;
	}
	return rs;
}

void AND(int* a, int* b, int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] == 1 && b[i] == 1) cout << '1';
		else cout << '0';
	}
	cout << endl;
}

void OR(int* a, int* b, int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] == 0 && b[i] == 0) cout << '0';
		else cout << '1';
	}
	cout << endl;
}

void XOR(int* a, int* b, int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] == b[i]) cout << '0';
		else cout << '1';
	}
	cout << endl;
}

void NOT(int* a, int a_len, int len) {
	cout << "~a = ";
	if (a_len == len) {
		for (int i = 0; i < a_len; i++) {
			cout << 1 - a[i];
		}
	}
	else {
		for (int i = len - a_len; i < len; i++) {
			cout << 1 - a[i];
		}
	}
	cout << endl;
}

void LEFT_SHIFT(int* a, int* b, int len) {
	int db = toDec(b, len);
	int da = toDec(a, len);
	int dc = da << db;
	toBinary(dc);
	cout << endl;
}

void RIGHT_SHIFT(int* a, int* b, int len) {
	int db = toDec(b, len);
	int da = toDec(a, len);
	int dc = da >> db;
	toBinary(dc);
	cout << endl;
}

int main() {
	string c, sa, sb, bopt;
	int* a; int* b;
	int length;

	do {
		cout << "-----------------------" << endl;
		cout << "c. Continue" << endl;
		cout << "e. Exit" << endl;
		cout << "Enter: "; cin >> c;
		if (c == "exit" || c == "quit" || c == "done") break;
		
		cout << "Input: " << endl;
		cout << "a = "; cin >> sa;
		cout << "b = "; cin >> sb;
		cout << "bitwise operator = "; cin >> bopt;

		length = max(sa.length(), sb.length());
		int* a = preProcess(sa, length);
		int* b = preProcess(sb, length);

		if (bopt == "&") AND(a, b, length);
		else if (bopt == "|") OR(a, b, length);
		else if (bopt == "^") XOR(a, b, length);
		else if (bopt == "~") {
			NOT(a, sa.length(), length);
			NOT(b, sb.length(), length);
		}
		else if (bopt == "<<") LEFT_SHIFT(a, b, length);
		else if (bopt == ">>") RIGHT_SHIFT(a, b, length);
	} while (c != "e");
	
	return 0;
}