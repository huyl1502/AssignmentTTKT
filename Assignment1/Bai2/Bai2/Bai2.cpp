#include <iostream>

using namespace std;

int main()
{
    int n, m;
    
    cout << "So phan tu mang 1: ";
    cin >> n;

    cout << "So phan tu mang 2: ";
    cin >> m;

    int* a1 = new int[n];
    int* a2 = new int[m];
    int* rs = new int[n + m];

    for (int i = 0; i < n; i++) {
        cout << "a1[" << i << "] = ";
        cin >> a1[i];
        rs[i] = a1[i];
    }

    for (int i = 0; i < m; i++) {
        cout << "a2[" << i << "] = ";
        cin >> a2[i];
        rs[i + n] = a2[i];
    }

    int noc = n + m;
    int tg;

    for (int i = 1; i < noc; i++) {
        if ((rs[i] + rs[i - 1]) % 2 == 1) continue;
        for (int j = i + 1; j < noc; j++) {
            if ((rs[i - 1] + rs[j]) % 2 == 1) {
                tg = rs[i];
                rs[i] = rs[j];
                rs[j] = tg;
                break;
            }
        }
    }

    cout << "Ket qua: ";
    for (int i = 0; i < noc; i++) {
        cout << rs[i] << " ";
    }

    return 0;
}