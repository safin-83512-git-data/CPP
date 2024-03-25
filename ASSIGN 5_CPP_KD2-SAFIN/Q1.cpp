#include<iostream>
using namespace std;
class Date{
    private:
    int day;
    int month;
    int year;
    public:
    Date(){
      day = 0;
      month = 1;
      year = 2000;
    }
    void acceptDate(){
         cout<<"Enter date"<<endl;
         cin>>day;
         cout<<"enter month"<<endl;
         cin>>month;
         cout<<"enter year"<<endl;
         cin>>year;
         
    }
    void displayDate(){
         cout<<day<<" "<<month<<" "<<year<<endl;
    }


};
class Person{
    private:
    string name;
    string address;
    int birthdate;
    public:
    Person(){
       name = "SAFIN";
       address = "LATUR";
       birthdate = 2000;


    }
    void acceptPerson(){
        cout<<"Enter Person Name"<<endl;
         cin>>name;
         cout<<"Enter Person Address"<<endl;
         cin>>address;
         cout<<"Enter Person BirthYear "<<endl;
         cin>>birthdate;
    }
    void displayPerson(){
        cout<<name<<" "<<address<<" "<<birthdate<<endl;
    }


    
};
class Employee{
    private:
    int id;
    int sal; 
    int dept;
    Date joiningDate;
    Person *perPtr;
    public:
    void acceptEmp(){
        cout<<"Enter emp id"<<endl;
         cin>>id;
         cout<<"Enter emp sal"<<endl;
         cin>>sal;
         cout<<"Enter emp dept"<<endl;
         cin>>dept;
         joiningDate.acceptDate();

    }
    void addPer(){
        perPtr = new Person;
        perPtr->acceptPerson();
    }
    void displayEmp(){
        cout<<"Employee details"<<endl;
        cout<<id<<" "<<sal<<" "<<dept<<endl;
        cout<<"Show joining detail"<<endl;
        joiningDate.displayDate();
        
        
    }
    void perDisplay(){
         if(perPtr != NULL){
          cout<<"Person details "<<endl;
          perPtr->displayPerson();
        }
    }
    ~Employee(){
        if(perPtr != NULL){
            delete perPtr;
            perPtr = NULL;
           
        }
    }



};
int main(){
   
   Employee a;
   a.acceptEmp();
   a.addPer();
   a.perDisplay();
   a.displayEmp();
}