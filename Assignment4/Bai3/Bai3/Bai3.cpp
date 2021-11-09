#include <iostream>

using namespace std;

unsigned int sumDigit(unsigned int n) {
    unsigned int rs = 0;
    while (n != 0) {
        rs += n % 10;
        n /= 10;
    }
    return rs;
}

unsigned int reverse(unsigned int n) {
    unsigned int rs = 0;
    while (n != 0) {
        rs *= 10;
        rs += n % 10;
        n /= 10;
    }
    return rs;
}

bool isPerfect(unsigned int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n) return true;
    return false;
}

bool isPrime(unsigned int n) {
    if (n < 2) return false;
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count == 0) return true;
    else return false;
}

void factor(unsigned int n) {
    cout << "n = ";

    int dem;

    for (int i = 2; i <= n; i++) {
        dem = 0;
        while (n % i == 0) {
            ++dem;
            n /= i;
        }
        if (dem) {
            cout << i;
            if (dem > 1) cout << "^" << dem;
            if (n > i) {
                cout << " * ";
            }
        }
    }
    cout << endl;
}

int main()
{
    unsigned int c, n = 0;
    
    do {
        cout << "----------------------------------" << endl;
        cout << "1. Nhap n" << endl;
        cout << "2. Tong cac chu so cua n" << endl;
        cout << "3. So co cac chu so nguoc voi n" << endl;
        cout << "4. Kiem tra so hoan hao" << endl;
        cout << "5. Kiem tra so nguyen to" << endl;
        cout << "6. Phan tich n thanh thua so nguyen to" << endl;
        cout << "7. Thoat" << endl;
        cout << "Chon: "; cin >> c;
        switch (c) {
        case 1: {
            cout << "Nhap n: "; cin >> n;
            cout << "So vua nhap: " << n << endl;
        }
              break;
        case 2: {
            if (n > 0) cout << "Tong cac chu so cua n: " << sumDigit(n) << endl;
            else cout << "So da nhap khong hop le" << endl;
        }
              break;
        case 3: {
            if (n > 0) cout << "So co cac chu so nguoc voi n: " << reverse(n) << endl;
            else cout << "So da nhap khong hop le" << endl;
        }
              break;
        case 4: {
            if (n > 0) {
                if (isPerfect(n)) cout << "n la so hoan hao" << endl;
                else cout << "n khong la so hoan hao" << endl;
            }
            else cout << "So da nhap khong hop le" << endl;
        }
              break;
        case 5: {
            if (n > 0) {
                if (isPrime(n)) cout << "n la so nguyen to" << endl;
                else cout << "n khong la so nguyen to" << endl;
            }
            else cout << "So da nhap khong hop le" << endl;
        }
              break;
        case 6: {
            if (n > 0) factor(n);
            else cout << "So da nhap khong hop le" << endl;
        }
              break;
        case 7: break;
        }
    } while (c != 7);

    return 0;
}