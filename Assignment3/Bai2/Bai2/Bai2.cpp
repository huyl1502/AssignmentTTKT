#include <iostream>

using namespace std;

class String {
public:
    int m_length;
    char* m_str;

    String() {
        m_length = 0;
        m_str = NULL;
    }

    String(const String& str) {
        m_length = str.m_length;
        m_str = new char[m_length + 1];
        strcpy(m_str, str.m_str);
    }

    ~String() {
        m_length = 0;
        delete[] m_str;
    }
    
    int length(const char* str) {
        int count = 0;
        while (str[count] != '\0') {
            count++;
        }
        return count;
    }

    void strcpy(char*& str1, const char* str2)
    {
        int len = length(str2);
        str1 = new char[len + 1];
        int i;
        for (i = 0; i < len; i++)
        {
            str1[i] = str2[i];
        }
        str1[i] = '\0';
    }

    String operator + (String const& str) {
        String rs;
        rs.m_length = m_length + str.m_length;
        rs.m_str = new char[rs.m_length + 1];
        int i, j, k;
        for (i = 0; i < m_length; i++) {
            rs.m_str[i] = m_str[i];
        }
        for (j = 0; j < str.m_length; j++) {
            k = j + m_length;
            rs.m_str[k] = str.m_str[j];
        }
        rs.m_str[rs.m_length] = '\0';
        return rs;
    }

    bool operator == (String const& str) {
        for (int i = 0; i < m_length; i++) {
            if (m_str[i] == str.m_str[i]) continue;
            else return false;
        }
        return true;
    }

    void reverse() {
        int tg_len = m_length;
        char* tg_str = new char[tg_len + 1];
        strcpy(tg_str, m_str);
        for (int i = 0; i < m_length; i++) {
            m_str[i] = tg_str[m_length - 1 - i];
        }
    }

    friend ostream& operator << (ostream& os, const String& str);
    friend istream& operator >> (istream& is, const String& str);
};

ostream& operator<<(ostream& os, const String& str)
{
    os << str.m_str;
    return os;
}
istream& operator>>(istream& is, String& str)
{
    cout << "Nhap Chieu Dai Chuoi: ";
    is >> str.m_length;
    str.m_str = new char[str.m_length + 1];
    is.ignore();
    is.getline(str.m_str, str.m_length + 1);
    return is;
}


int main()
{
    String a;
    cin >> a;

    a.reverse();

    String b;
    cin >> b;

    String c = a + b;
    cout << c;

    return 0;
}