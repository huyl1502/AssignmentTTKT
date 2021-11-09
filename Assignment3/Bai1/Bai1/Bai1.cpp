#include <iostream>

using namespace std;

class CGoods {
public:
    char m_cCode[4];
    char m_cName[20];
    char m_cUnit[10];
    float m_fUPrice, m_fValue;
    int m_nNumberOfGood;

    void input() {
        cout << "Input code : "; cin >> m_cCode;
        cout << "Input name : "; cin >> m_cName;
        cout << "Input unit to calculate : "; cin >> m_cUnit;
        cout << "Input unit price : "; cin >> m_fUPrice;
        cout << "Input number of good : "; cin >> m_nNumberOfGood;
    }

    void calcValue() {
        m_fValue = m_fUPrice * m_nNumberOfGood;
    }
};

class NCGoods : public CGoods {
public:
    float m_fShippingUnitPrice, m_fTransCost;

    void transportationCosts() {
        m_fTransCost = m_fShippingUnitPrice * m_nNumberOfGood;
    }
    void input() {
        CGoods::input();
        cout << "Input shipping unit price : "; cin >> m_fShippingUnitPrice;
    }
    void payment() {
        CGoods::calcValue();
        transportationCosts();
        cout << "Payment: " << m_fValue + m_fTransCost;
    }
};

int main()
{
    NCGoods goods;
    goods.input();
    goods.payment();
    return 0;
}