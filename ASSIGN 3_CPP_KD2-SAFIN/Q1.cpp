#include <iostream>
using namespace std;

class volume
{
private:
    static double PI;
    double r;
    double h;
    double v;

public:
    volume()
    {
        r = 0;
        h = 0;
        v = 0;
    }
    double getRadius()
    {
        return r;
    }
    void setRadius(double rad)
    {
        r = rad;
    }
    double getHeight()
    {
        return h;
    }
    void setHeight(double height)
    {
        h = height;
    }
    double getVolume()
    {
        double vol = PI * r * r * h;
        v = vol;
        return v;
    }
    void prdoubleVolume()
    {
        cout << "cylinder volume - " << v << endl;
    }
};
double volume ::PI = 3.14;
int main()
{
    volume v;
    cout << "Enter values of Radius -";
    double r;
    cin >> r;
    cout << "Enter values of Height -";
    double h;
    cin >> h;
    v.setRadius(r);
    v.setHeight(h);
    v.getVolume();
    v.prdoubleVolume();

    return 0;
}
