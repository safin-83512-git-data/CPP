#include <iostream>

using namespace std;

class TollBooth {
private:
    unsigned int totalCars;
    double totalMoney;

public:
    TollBooth() : totalCars(0), totalMoney(0.0) {}

    void payingCar() {
        totalCars++;
        totalMoney += 0.50;
    }

    void nopayCar() {
        totalCars++;
    }

    void printOnConsole() {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Money Collected: $" << totalMoney << endl;
        cout << "Number of Paying Cars: " << totalCars << endl;
        cout << "Number of Non-Paying Cars: " << totalCars << endl;
    }
};

int main() {
    TollBooth booth;
    booth.payingCar(); 
    booth.nopayCar(); 
    booth.printOnConsole();

    return 0;
}
