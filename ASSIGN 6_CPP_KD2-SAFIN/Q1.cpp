#include<iostream>
using namespace std;

class Date
{
private:
        int day,month,year;

public:
    // Date()
    // {
    //     day=14;
    //     month=09;
    //     year=2001;
    // }
    void acceptDate()
    {
        cout<<"Enter Day -";
        cin>>day;
        cout<<"Enter Month -";
        cin>>month;
        cout<<"Enter Year -";
        cin>>year;
    }
    void displayDate()
    {
        cout<<"Date -"<<day<<"-"<<month<<"-"<<year<<endl;
    }
};

class person
{
private:
    string name;
    string address;
    Date Dob;

public:
        // person()
        // {
        //     name="SAFIN";
        //     address="Latur";
        // }
        virtual void acceptData()
        {
            cout<<"Enter Name -";
            cin>>name;
            cout<<"Enter Address -";
            cin>>address;
            cout<<"Enter Date of Birth -";
            Dob.acceptDate();
        }
        virtual void displayData()
        {
            cout<<"Person Name -"<<name<<endl;
            cout<<"Person address -"<<address<<endl;
            cout<<"Person Name -";
            Dob.displayDate();
        }
};

class employee:public person
{
private:
        int empid;
        string dept;
        double salary;
        Date doj;

public:
        // employee()
        // {
        //     id=1001;
        //     sal=5000;
        //     dept="Manager";

        // }
        void acceptData()
        {
            cout<<"Employee id -";
            cin>>empid;
            cout<<"Employee salary -";
            cin>>salary;
            cout<<"Employee dept -";
            cin>>dept;
            cout<<"Employee joining Date -";
            doj.acceptDate();

            person::acceptData();
        }
        void displayData()
        {
            cout<<"id -"<<empid<<endl;
            cout<<"salary-"<<salary<<endl;
            cout<<"dept -"<<dept<<endl;
            cout<<"Joining Date -";
            doj.displayDate();

            person::displayData();
            
        }

};

int main()
{

    person p;
    p.acceptData();
    p.displayData();

    employee e;
    e.acceptData();
    e.displayData();

    person *ptr=new employee();
    ptr->acceptData();
    ptr->displayData();
    delete ptr;
    ptr=NULL;
}