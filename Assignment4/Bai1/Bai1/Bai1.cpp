#include <iostream>

using namespace std;

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

int bcnn(int a, int b) {
    return (a * b) / ucln(a, b);
}

int main()
{
    int c, a, b;
    do {
        cout << "----------------------------------" << endl;
        cout << "1. Tiep tuc" << endl;
        cout << "2. Thoat" << endl;
        cout << "Chon: "; cin >> c;
        switch (c) {
        case 1: {
            cout << "a = "; cin >> a;
            cout << "b = "; cin >> b;
            if (a > 0 && b > 0) {
                cout << "UCLN(" << a << ", " << b << ") = " << ucln(a, b) << endl;
                cout << "BCNN(" << a << ", " << b << ") = " << bcnn(a, b) << endl;
            }
            else cout << "Du lieu khong hop le" << endl;
        }
            break;
        case 2: break;
        }
    } while (c != 2);

    return 0;
}