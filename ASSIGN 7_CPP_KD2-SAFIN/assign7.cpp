// Q1. Provide menu driven code for the functionalities:
// 1. Accept Employee
// 2. Display the count of all employees with respect to designation
// 3. Display All Managers
// 4. Display All Salesman
// 5. Display All SalesManagers


#include <iostream>
#include <typeinfo>
using namespace std;
class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    void setId()
    {
        int id1;
        cout << "enter id ";
        cin >> id1;
        id = id1;
    }
    int getId()
    {
        return id;
    }
    void setSalary()
    {
        double sal;
        cout << "enter salary ";
        cin >> sal;
        salary = sal;
    }
    double getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        setId();
        setSalary();
    }

    virtual void display()
    {
        cout << "ID: " << getId() << endl;
        cout << "Salary: $" << getSalary() << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};
class Manager : virtual public Employee
{
private:
    double Bonus;

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void setBonus()
    {
        double bon;
        cout << "enter bonus ";
        cin >> bon;
        Bonus = bon;
    }
    double getBonus()
    {
        return Bonus;
    }
    virtual void  accept()
    {
        Employee::accept();
        setBonus();
    }
   virtual void display()
    {
        Employee::display();
        cout << " Bonus " << Bonus << endl;
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};
class Salesman : virtual public Employee
{
private:
    double comm;

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double com1)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void setComm()
    {
        double com1;
        cout << "enter comm ";
        cin >> com1;
        comm = com1;
    }
    double getComm()
    {
        return comm;
    }
   virtual void accept()
    {
        Employee::accept();
        setComm();
    }

   virtual void display()
    {
        Employee::display();
        cout << "commision of saleman " << comm << endl;
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SaleManager : public Manager, public Salesman
{
public:
    SaleManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SaleManager(int id, double salary, double bonus, double com1)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }

    void accept()
    {
        Employee::accept();
        Manager::accept();
        // SaleManager::acceptSalesMan();
        Salesman::accept();
    }
    void display()
    {
        Employee::display();
        Manager::display();
        Salesman::display();

    }
    ~SaleManager()
    {
        cout << "~Salemanager()" << endl;
    }
};

int main()
{
    Employee *arr[10];

    int ch;
    int index = 0;
    int scnt = 0;
    int mcnt = 0;
    int smCnt = 0;
    do
    {
        cout << "0 exit" << endl;
        cout << "1 accept Manager" << endl;
        cout << "2 Accept saleman" << endl;
        cout << "3 accept Manager" << endl;
        cout << "4 display Manager" << endl;
        cout << "5 display saleman" << endl;
        cout << "6 display salemanager" << endl;
        cout << "Enter choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exit ";
            break;
        case 1:
            if (index < 10)
            {
                arr[index] = new Manager();
                arr[index]->accept();
                index++;
                mcnt++;
            }
            break;
        case 2:
            if (index < 10)
            {
                arr[index] = new Salesman();
                arr[index]->accept();
                index++;
                scnt++;
            }
            break;
        case 3:
            if (index < 10)
            {
                arr[index] = new SaleManager();
                arr[index]->accept();
                index++;
                smCnt++;
            }
            break;
        case 4:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
            }
            cout << "MM===============================";
            break;
        case 5:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    arr[i]->display();
                }
            }
            cout << "SALEMAN*******";
            break;
        case 6:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(SaleManager))
                {
                    arr[i]->display();
                }
                else if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
                else
                {
                    arr[i]->display();
                }
            }

            cout << "*********";

        default:
            break;
        }
    } while (ch != 0);
    cout<<"Count of Manager "<<mcnt<<endl;
    cout<<"Count of Salesman "<<scnt<<endl;
    cout<<"Count of Sale Manager "<<smCnt<<endl;
    for (int i = 0; i < index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }
    // SaleManager d;
    // d.accept();
    // d.diplay();
    // Employee *eptr = new SaleManager();
    // eptr->accept(); // Late Binding
    // eptr->display();

    // delete eptr;
    // eptr = NULL;
    // return 0;
}