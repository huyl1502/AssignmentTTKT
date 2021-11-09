#include <iostream>

using namespace std;

bool checkString(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;
        else return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    int rs = 3;

    while (rs != 0) {
        cout << "s1: ";
        cin >> s1;

        cout << "s2: ";
        cin >> s2;

        if (checkString(s1) && checkString(s2)) {
            if (s1.length() > s2.length()) {
                rs = 1;
            }
            else if (s1.length() < s2.length())
            {
                rs = 2;
            }
            else if (s1 == s2) {
                rs = rand() % (2 - 1 + 1) + 1;
            }
            else {
                for (int i = 0; i < s1.length(); i++) {
                    if (s1[i] > s2[i]) {
                        rs = 1;
                        break;
                    }
                    else if (s1[i] < s2[i]) {
                        rs = 2;
                        break;
                    }
                    else continue;
                }
            }
        }
        else {
            cout << "Khong hop le!" << endl;
            break;
        }

        if (rs == 1) cout << s1 << endl;
        else if (rs == 2) cout << s2 << endl;
    }

    return 0;
}