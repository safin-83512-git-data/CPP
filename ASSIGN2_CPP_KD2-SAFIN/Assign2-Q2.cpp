#include <iostream>

using namespace std;

class TollBooth {
private:
    unsigned int totalCars;
    unsigned int payingCars;
    unsigned int nonPayingCars;
    double totalMoney;

public:
    TollBooth() : totalCars(0), payingCars(0), nonPayingCars(0), totalMoney(0.0) {}
    
    void addCars(unsigned int paying, unsigned int nonPaying) {
        totalCars += paying + nonPaying;
        payingCars += paying;
        nonPayingCars += nonPaying;
        totalMoney += (0.50 * paying);
    }

    void printOnConsole() {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Money Collected: $" << totalMoney << endl;
        cout << "Number of Paying Cars: " << payingCars << endl;
        cout << "Number of Non-Paying Cars: " << nonPayingCars << endl; 
    }
};

int main() {
    TollBooth booth;
    unsigned int paying, nonPaying;

    cout << "Enter the number of paying cars: ";
    cin >> paying;
    cout << "Enter the number of non-paying cars: ";
    cin >> nonPaying;

    booth.addCars(paying, nonPaying);

    booth.printOnConsole();

    return 0;
}
