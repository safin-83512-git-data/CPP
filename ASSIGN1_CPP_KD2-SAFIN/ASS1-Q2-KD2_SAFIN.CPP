#include <iostream>

using namespace std;
struct date
{
    int sd;
    int sm;
    int sy;

    void initDate()
    {
        int d, m, y;
        cin >> d >> m >> y;
        sd = d;
        sm = m;
        sy = y;
        cout << "Date month and year " << sd << " / " << sm << " / " << sy << endl;
        // isLeapYear();
    }
    void printDateOnConsole()
    {
        cout << sd << " - " << sm << " - " << sy << endl;
    }
    void acceptDateFromConsole()
    {
        cin >> sd >> sm >> sy;
        // cout<<"Date month and year " <<sd<<" - "<<sm<<" - "<<sy<<endl;
    }

    bool isLeapYear()
    {

        bool isLeap = false;
        if (sy % 4 == 0)
        {
            // cout<<"leap-year"<<endl;
            isLeap = true;
        }
        else
        {
            // cout<<"Not year";
            isLeap = false;
        }

        return isLeap;
    }
};
int main()
{
    struct date t;
    int ch;

    do
    {
        cout << "1 Init Date" << endl;
        cout << "2 Print Date" << endl;
        cout << "3 Accept Date" << endl;
        cout << "4 Leap Year" << endl;
        cout << "0 End" << endl;
        cout << "Enter choice" << endl;

        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "exit" << endl;
            break;
        case 1:
            t.initDate();
            break;
        case 2:
            t.printDateOnConsole();
            break;
        case 3:
            t.acceptDateFromConsole();
            break;
        case 4:
            if (t.isLeapYear())
            {
                cout << "Is a leap year" << endl;
            }
            else
            {
                cout << "Not a leap year" << endl;
            }

            break;
        default:
            cout << "Wrong option" << endl;
            break;
        }
    } while (ch != 0);
    return 0;
}