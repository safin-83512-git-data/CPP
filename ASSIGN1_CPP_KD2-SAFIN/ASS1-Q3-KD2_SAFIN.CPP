#include <iostream>

using namespace std;

class Student
{
private:
    int RollNo;
    string Name;
    int marks;

public:
    void initStudent()
    {
        RollNo = 83512;
        Name = "Safin";
        marks = 92;
    }
    void acceptStudentFromConsole()
    {
        cout << "Enter RollNo -";
        cin >> RollNo;
        cout << "Enter Name -";
        cin >> Name;
        cout << "Enter Marks -";
        cin >> marks;
    }
    void printStudentOnConsole()
    {
        cout << "Roll No -" << RollNo << endl;
        cout << "Name -" << Name << endl;
        cout << "Marks -" << marks << endl;
    }
};
int main()
{
    Student t1;
    int choice;
    t1.initStudent();

    do
    {

        cout << "1.initStudent" << endl;
        cout << "2.printStudentOnConsole" << endl;
        cout << "3.acceptStudentFromConsol" << endl;
        cout << "4.exit" << endl;
        cout << "Enter Your Choice:";
        cin >> choice;

        switch (choice)
        {

            break;
        case 1:
            t1.initStudent();
            break;
        case 2:
            t1.printStudentOnConsole();
            break;
        case 3:
            t1.acceptStudentFromConsole();
            break;
        case 4:
            cout << "Thanks For Visiting us" << endl;
        default:
            cout << "Wrong choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}