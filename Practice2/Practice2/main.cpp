#include <iostream>
using namespace std;

enum class Month
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

void changemonth(int month)
{
	switch (month)
	{
	case (int)Month::Jan:
		cout << "It's January" << endl;
		break;
	case (int)Month::Feb:
		cout << "It's February" << endl;
		break;
	case (int)Month::Mar:
		cout << "It's March" << endl;
		break;
	case (int)Month::Apr:
		cout << "It's April" << endl;
		break;
	case (int)Month::May:
		cout << "It's May" << endl;
		break;
	case (int)Month::Jun:
		cout << "It's June" << endl;
		break;
	case (int)Month::Jul:
		cout << "It's July" << endl;
		break;
	case (int)Month::Aug:
		cout << "It's August" << endl;
		break;
	case (int)Month::Sep:
		cout << "It's September" << endl;
		break;
	case (int)Month::Oct:
		cout << "It's October" << endl;
		break;
	case (int)Month::Nov:
		cout << "It's November" << endl;
		break;
	case (int)Month::Dec:
		cout << "It's December" << endl;
		break;
	default:
		cout << "Not month" << endl;
		break;
	}
}

int main()
{
	int month;
	cin >> month;
	changemonth(month);
	return 0;
}