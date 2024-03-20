#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string Building;
    string Street;
    string City;
    int PIN;

public:
    Address() : Building(""), Street(""), City(""), PIN(0) {}

    Address(string b, string s, string c, int p) : Building(b), Street(s), City(c), PIN(p) {}


    string getBuilding() { return Building; }
    string getStreet() { return Street; }
    string getCity() { return City; }
    int getPin() { return PIN; }

    void setBuilding(string b) { Building = b; }
    void setStreet(string s) { Street = s; }
    void setCity(string c) { City = c; }
    void setPin(int p) { PIN = p; }

    void accept() {
        cout << "Enter Building: ";
        getline(cin, Building);
        cout << "Enter Street: ";
        getline(cin, Street);
        cout << "Enter City: ";
        getline(cin, City);
        cout << "Enter PIN: ";
        cin >> PIN;
    }

    void display() {
        cout << "\nAddress Details:" << endl;
        cout << "-----------------" << endl;
        cout << "Building: " << Building << endl;
        cout << "Street: " << Street << endl;
        cout << "City: " << City << endl;
        cout << "PIN: " << PIN << endl;
        cout << "-----------------" << endl;
    }
};

int main() {
    Address address;
    cout << "SAFIN Please Enter Address Your Details:" << endl;
    address.accept();
    address.display();

    return 0;
}
