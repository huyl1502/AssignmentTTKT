#include <iostream>

using namespace std;

void inDaoNguoc(int* arr, int len) {
    for (int i = len - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

void tongPhanTu(int* arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    cout << sum;
}

void timMinMax(int* arr, int len) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    cout << "Phan tu nho nhat: " << min << endl;
    cout << "Phan tu lon nhat: " << max << endl;
}

int main()
{
    int N;
    cout << "So phan tu: ";
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    return 0;
}