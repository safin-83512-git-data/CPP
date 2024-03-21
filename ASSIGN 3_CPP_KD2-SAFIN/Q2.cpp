#include <iostream>
using namespace std;

class Time
{
private:
    int h;
    int m;
    int s;

public:
    Time()
    {
        h = 0;
        m = 0;
        s = 0;
    }

    Time(int h1, int m1, int s1)
    {
        h = h1;
        m = m1;
        s = s1;
    }
    int getHour()
    {
        return h;
    }
    int getMinute()
    {
        return m;
    }
    int ingetSeconds()
    {
        return s;
    }
    void printTime()
    {
        cout << "HOUR- " << h << endl
             << "MIN- " << m << endl
             << "SEC- " << s << endl;
    }
    void setHour(int hr)
    {
        h = hr;
    }
    void setMinute(int mi)
    {
        m = mi;
    }
    void setSeconds(int sec)
    {
        s = sec;
    };
};

int main()
{
    Time *ptr = new Time;
    Time *ptr2 = new Time(10, 4, 6);
    cout << "Enter Hours -";
    int h;
    cin >> h;
    cout << "Enter Min -";
    int min;
    cin >> min;
    cout << "Enter Second -";
    int s;
    cin >> s;
    ptr->setHour(h);
    ptr->setMinute(min);
    ptr->setSeconds(s);
    cout << "default constructor" << endl;
    ptr->printTime();
    cout << "Parametrized call" << endl;
    ptr2->printTime();
    delete ptr;
    ptr = NULL;
    delete ptr2;
    ptr2 = NULL;

    return 0;
}