#include <iostream>
#include <algorithm>

using namespace std;

bool checkCondition(int n, int m, int n1, int m1) {
    if (n < 1 || n > 1000 || m < 1 || m > 1000 || n1 < 1 || n1 > 1000 || m1 < 1 || m1 > 1000)
        return false;
}

int main()
{
    int n, m, n1, m1;

    do {
        cout << "Nhap n: ";
        cin >> n;

        cout << "Nhap m: ";
        cin >> m;

        cout << "Nhap n1: ";
        cin >> n1;

        cout << "Nhap m1: ";
        cin >> m1;
    } while (!checkCondition(n, m, n1, m1));

    int nor = max(n, n1);
    int noc = max(m, m1);

    int** A = new int*[nor];
    int** B = new int* [nor];
    int** R = new int* [nor];
    for (int i = 0; i < nor; i++) {
        A[i] = new int[noc];
        B[i] = new int[noc];
        R[i] = new int[noc];
    }

    for (int i = 0; i < nor; i++) {
        for (int j = 0; j < noc; j++) {
            A[i][j] = B[i][j] = R[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < nor; i++) {
        for (int j = 0; j < noc; j++) {
            R[i][j] = A[i][j] + B[i][j];
            cout << R[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}