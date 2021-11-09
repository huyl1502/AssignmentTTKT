#include <iostream>
#define CURRENT_YEAR 2021

using namespace std;

class Human {
public:
    string m_cmnd;
    string m_name;
    int m_age;
    int m_birth;
    string m_job;

    void Input() {
        cout << "       CMND: "; cin >> m_cmnd;
        cout << "       Ho ten: "; cin >> m_name;
        cout << "       Nam sinh: "; cin >> m_birth;
        m_age = CURRENT_YEAR - m_birth;
        cout << "       Nghe nghiep: "; cin >> m_job;
    }

    void Display() {
        cout << "       CMND: " << m_cmnd << endl;
        cout << "       Ho ten: " << m_name << endl;
        cout << "       Tuoi: " << m_age << endl;
        cout << "       Nam sinh: " << m_birth << endl;
        cout << "       Nghe nghiep: " << m_job << endl;
    }
};

class Town {
public:
    int m_noh;
    int m_apartmentNumber;
    Human* m_mems;

    void Input() {
        cout << "   So thanh vien: "; cin >> m_noh;
        cout << "   So nha: "; cin >> m_apartmentNumber;
        m_mems = new Human[m_noh];
        for (int i = 0; i < m_noh; i++) {
            cout << "   Nhap thong tin thanh vien " << i + 1 << endl;
            m_mems[i].Input();
        }
    }

    void Display() {
        cout << "   So thanh vien: " << m_noh << endl;
        cout << "   So nha: " << m_apartmentNumber << endl;
        for (int i = 0; i < m_noh; i++) {
            cout << "   Thanh vien " << i + 1 << endl;
            m_mems[i].Display();
        }
    }
};

void findByApartmentNumber(Town* t, int N, int inp) {
    for (int i = 0; i < N; i++) {
        if (t[i].m_apartmentNumber == inp) t[i].Display();
    }
}

void findByName(Town* t, int N, string inp) {
    cout << "Ho can tim: " << endl;
    Town obj;
    for (int i = 0; i < N; i++) {
        obj = t[i];
        for (int j = 0; j < obj.m_noh; j++) {
            if (obj.m_mems[j].m_name == inp) obj.Display();
        }
    }
}

int main()
{
    int N;
    cout << "Tong so ho dan: "; cin >> N;
    Town* towns = new Town[N];

    for (int i = 0; i < N; i++) {
        cout << "Ho dan thu " << i + 1 << endl;
        towns[i].Input();
    }

    int c;

    do {
        cout << "------------------------------------------------" << endl;
        cout << "1. Danh sach cac ho dan" << endl;
        cout << "2. Tim kiem theo so nha" << endl;
        cout << "3. Tim kiem theo ten" << endl;
        cout << "4. Thoat" << endl;
        cout << "Chon: "; cin >> c;
        switch (c)
        {
        case 1: {
            for (int i = 0; i < N; i++) {
                cout << "Ho dan thu " << i + 1 << endl;
                towns[i].Display();
            }
        }
              break;
        case 2: {
            int fapartmentNumber;
            cout << "Nhap so nha can tim: "; cin >> fapartmentNumber;
            findByApartmentNumber(towns, N, fapartmentNumber);
        }
              break;
        case 3: {
            string fname;
            cout << "Nhap ten nguoi can tim: "; cin >> fname;
            findByName(towns, N, fname);
        }
              break;
        case 4: break;
        }
    } while (c != 4);
    
    return 0;
}