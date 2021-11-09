#include <iostream>

using namespace std;

int cong(int a, int b) {
    return a + b;
}

float tru(int* a, int* b) {
    return 0;
}

float nhan(int* a, int* b) {
    return 0;
}

float chia(int* a, int* b) {
    return 0;
}

float chiaDu(int* a, int* b) {
    return 0;
}

int main()
{
    char c;
    int a, b;
    char opt;

    do {
        cout << "c.Continue" << endl << "e.Exit" << endl;
        cin >> c;

        cin >> a >> opt >> b;

        if (opt == '+') {
            cout << cong(a, b) << endl;
        }
        
    } while (c != 'e');

    return 0;
}