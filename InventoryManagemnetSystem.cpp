//============================================================================
// Name        : InventoryManagemnetSystem.cpp
// Author      : Narayan
// Version     :
// Copyright   : Your copyright notice
// Description : Inventory Management System
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product {

private:
    int productId;
    string name;
    double price;
    int quantity;

public:


    void acceptDetails() {

        cout << "Enter product ID: ";
        cin >> productId;

        cout << "Enter product name: ";
        cin >> name;

        cout << "Enter product price: ";
        cin >> price;

        cout << "Enter product quantity: ";
        cin >> quantity;
    }


    void displayDetails() const {

        cout << left
             << setw(7) << productId
             << setw(12) << name
             << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();
    }


    double totalValue() const {

        return price * quantity;
    }


    bool isLowStock(int threshold) const {

        return quantity < threshold;
    }
};




double reorderCost(int qty, double unitPrice) {

    return qty * unitPrice;
}



double reorderCost(double qty, double unitPrice) {

    return qty * unitPrice;
}



double reorderCost(int qty, double unitPrice, double taxRate) {

    double cost = qty * unitPrice;

    return cost + (cost * taxRate / 100);
}


double applyDiscount(double price, double discountPercent = 10.0) {

    return price - (price * discountPercent / 100);
}




int main() {


    // Array of 5 Product objects
    Product p[5];


    for (int i = 0; i < 5; i++) {

        cout << "\nEnter details for Product " << i + 1 << endl;

        p[i].acceptDetails();
    }



    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;



    cout << "\n\n===== INVENTORY REPORT =====" << endl;

    cout << left
         << setw(7) << "ID"
         << setw(12) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;



    for (int i = 0; i < 5; i++) {

        p[i].displayDetails();


        if (p[i].isLowStock(threshold)) {

            cout << " <- LOW STOCK";
        }

        cout << endl;
    }




    int highest = 0;

    for (int i = 1; i < 5; i++) {

        if (p[i].totalValue() > p[highest].totalValue()) {

            highest = i;
        }
    }




    cout << "\n===== HIGHEST TOTAL VALUE =====" << endl;

    p[highest].displayDetails();

    cout << endl;


       int qty1 = 10;
       double unitPrice1 = 50.0;
       cout << "Integer quantity reorder cost: " << reorderCost(qty1, unitPrice1) << endl;

       double qty2 = 5.5;
       double unitPrice2 = 40.0;
       cout << "Fractional quantity reorder cost: " << reorderCost(qty2, unitPrice2)<< endl;

       int qty3 = 20;
       double unitPrice3 = 30.0;
       double taxRate = 18.0;
       cout << "Reorder cost with tax: " << reorderCost(qty3, unitPrice3, taxRate)<< endl;


       cout << "\n===== DISCOUNT =====" << endl;
       double price = 1000.0;
       cout << "Price after default 10% discount: "<< applyDiscount(price)<< endl;


       cout << "Price after 20% discount: "<< applyDiscount(price, 20.0)<< endl;

    return 0;
}
