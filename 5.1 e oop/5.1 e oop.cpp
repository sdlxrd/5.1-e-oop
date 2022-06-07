#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
	cout << "Number of Objects: ";
	bool result;
	Money a, b;
	double x;
	cout << Object::Count() << endl;
	do
	{
		try
		{
			result = true;
			cout << endl;
			cout << "Enter the first value: " << endl; cin >> a;
			cout << "\nEnter the second value: " << endl; cin >> b;
			cout << "\nEnter the value of x: ";cin >> x;

		}
		catch (invalid_argument ex)
		{
			result = false;
			cerr << endl << ex.what() << endl << endl;
		}
		catch (nException& ex)
		{
			result = false;
			cout << endl << ex.getMessage() << endl << endl;
		}
		catch (Exception* ex)
		{
			result = false;
			cout << endl << ex->getMessage() << endl << endl;
		}
	} while (!result);
	system("cls");
	
	cout << "First sum = " << a << "\tSecond sum = " << b << "\tX = " << x << endl;
	cout << endl << "first - second: " << a - b << endl;
	cout << "\nfirst * x: " << a * x << endl;
	cout << "second * x: " << b * x << endl;

	if (a == b)
	{
		cout << a << " == " << b << endl;
	}
	else
		if (a > b)
		{
			cout << a << " > " << b << endl;
		}
		else
			if (a < b)
			{
				cout << a << " < " << b << endl;
			}
	cout << endl;
	cout << "a++ " << a++;
	cout << "\nresult: " << a << endl;
	cout << "\na-- " << a--;
	cout << "\nresult: " << a << endl;

	cout << "\n++a " << ++a << endl;
	cout << "--a " << --a << endl;

	cout << endl;
	system("cls");
}