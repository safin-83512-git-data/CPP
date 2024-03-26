#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int id;
    string title;
    double price;

public:
    
    virtual ~Product() {}

    virtual void accept() {
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    double getPrice() {
        return price;
    }
};

class Book : public Product {
private:
    string author;

public:
    void accept() override {
        cout << "Enter author name: ";
        cin >> author;
        Product::accept();
        // give discount of 10% on price and update the price
        price -= price * 0.10;
    }

    void display() override {
        cout << "Author: " << author << endl;
        Product::display();
    }
};

class Tape : public Product {
private:
    string artist;

public:
    void accept() override {
        cout << "Enter artist name: ";
        cin >> artist;
        Product::accept();
        // give discount of 5% on price and update the price
        price -= price * 0.05;
    }

    void display() override {
        cout << "Artist: " << artist << endl;
        Product::display();
    }
};

int main() {
    int n;
    cout << "Enter product size: ";
    cin >> n;
    Product *arr[n]; 

    int choice;
    int numProducts = 0; 
    do {
        
        cout << "\n0. Exit" << endl;
        cout << "1. Accept Tape" << endl;
        cout << "2. Accept Book" << endl;
        cout << "3. Display Tape" << endl;
        cout << "4. Display Book" << endl;
        cout << "5. Total Bill" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
            
                Tape *t = new Tape();
                t->accept();
                arr[numProducts] = t; 
                numProducts++;
                break;
            }
            case 2: {
               
                Book *b = new Book();
                b->accept();
                arr[numProducts] = b; // Add Book object pointer to array
                numProducts++;
                break;
            }
            case 3: {
            
                cout << "Tape Details:" << endl;
                for (int i = 0; i < numProducts; i++) {
                    Tape *t = dynamic_cast<Tape *>(arr[i]);
                    if (t != nullptr)
                        t->display();
                }
                break;
            }
            case 4: {
            
                cout << "Book Details:" << endl;
                for (int i = 0; i < numProducts; i++) {
                    Book *b = dynamic_cast<Book *>(arr[i]);
                    if (b != nullptr)
                        b->display();
                }
                break;
            }
            case 5: {
                
                double totalBill = 0;
                for (int i = 0; i < numProducts; i++) {
                    totalBill += arr[i]->getPrice();
                }
                cout << "Total Bill: " << totalBill << endl;
                break;
            }
            default:
                cout << "Thank you!" << endl;
                break;
        }
    } while (choice != 0);

    for (int i = 0; i < numProducts; i++) {
        delete arr[i];
    }

    return 0;
}
