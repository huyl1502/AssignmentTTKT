#include <iostream>

using namespace std;

int main()
{
    int c, N = 0;
    int* A = new int[N];
    int* B = new int[N];
    int* C = new int[N];
    char k;

    do {
        cout << "----------------------------------" << endl;
        cout << "1. Nhap A va B" << endl;
        cout << "2. Cong A va B" << endl;
        cout << "3. Tru A va B" << endl;
        cout << "4. Thoat chuong trinh" << endl;
        cout << "Chon: "; cin >> c;
        switch (c) {
        case 1: {
            cout << "Nhap so phan tu: "; cin >> N;
            A = new int[N];
            B = new int[N];

            cout << "Nhap mang A: " << endl;
            for (int i = 0; i < N; i++) {
                cout << "A[" << i << "] = "; cin >> A[i];
            }
            cout << "Nhap mang B: " << endl;
            for (int i = 0; i < N; i++) {
                cout << "B[" << i << "] = "; cin >> B[i];
            }
        }
              break;
        case 2: {
            if (N) {
                C = new int[N];
                for (int i = 0; i < N; i++) {
                    C[i] = A[i] + B[i];
                }
                cout << "Ket qua: ";
                for (int i = 0; i < N; i++) {
                    cout << C[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "Chua nhap du lieu" << endl;
                break;
            }
        }
            break;
        case 3: {
            if (N) {
                C = new int[N];
                for (int i = 0; i < N; i++) {
                    C[i] = A[i] - B[i];
                }
                cout << "Ket qua: ";
                for (int i = 0; i < N; i++) {
                    cout << C[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "Chua nhap du lieu" << endl;
                break;
            }
        }
            break;
        case 4: {
            cout << "Chac chan thoat" << endl;
            cout << "k. Thoat" << endl; cin >> k;
            if (k == 'k' || k == 'K') break;
            else c = 5;
        }
            break;
        }
    } while (c != 4);

    return 0;
}