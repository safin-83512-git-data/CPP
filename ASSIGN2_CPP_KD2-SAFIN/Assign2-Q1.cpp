#include <iostream>

using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box() : length(1.0), width(1.0), height(1.0) {}


    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    Box(double side) : length(side), width(side), height(side) {}

    double calculateVolume() {
        return length * width * height;
    }
};

int main() {
    int choice;
    double length, width, height;

    do {
        cout << "\nMenu options:" << endl;
        cout << "1. Calculate Volume with default values" << endl;
        cout << "2. Calculate Volume with length, breadth, and height with same value" << endl;
        cout << "3. Calculate Volume with different length, breadth, and height values" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Box box1;
                cout << "Volume with default values: " << box1.calculateVolume() << endl;
                break;
            }
            case 2: {
                cout << "Enter length, width, and height with same value: ";
                cin >> length;
                Box box2(length);
                cout << "Volume with same value: " << box2.calculateVolume() << endl;
                break;
            }
            case 3: {
                cout << "Enter length, width, and height: ";
                cin >> length >> width >> height;
                Box box3(length, width, height);
                cout << "Volume with different values: " << box3.calculateVolume() << endl;
                break;
            }
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while(choice != 4);

    return 0;
}
