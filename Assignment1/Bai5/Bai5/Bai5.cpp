#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	float a, b, c;
	float delta;

	while (true)
	{
		cout << "a = ";
		cin >> a;

		cout << "b = ";
		cin >> b;

		cout << "c = ";
		cin >> c;

		if (a == 0 && b == 0 && c == 0) break;
		else {
			delta = b * b - 4 * a * c;
			if (delta < 0) cout << "Phuong trinh vo nghiem" << endl;
			else if (delta == 0) cout << "Phuong trinh co nghiem kep la: x = " << setprecision(3) << fixed << -b / (2 * a) << endl;
			else cout << "Phuong trinh co 2 nghiem la: x1 = " << setprecision(3) << fixed << (-b - sqrt(delta)) / (2 * a) << " va x2 = " << setprecision(3) << fixed << (-b + sqrt(delta)) / (2 * a) << endl;
		}
	}

	return 0;
}