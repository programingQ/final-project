#include <iostream>
#include "./include/utils/utils.h"
#include "./src/utils/utils.cpp"  // best practice is not to include c++ files in cpp file and tell compiler to compile them together
using namespace std;
Customer* customers[100];
Product* products[100];
Dealer* dealers[100];
Purchase* purchases[100];
int customerCount = 0;
int productCount = 0;
int dealerCount = 0;
int purchaseCount = 0;
int main() {
    int choice;
    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                removeCustomer();
                break;
            case 5:
                addDealer();
                break;
            case 6:
                removeDealer();
                break;
            case 7:
                recordPurchase();
                break;
            case 8:
                totalPrice();
            break;
            case 9:
               productscustomers();
               break;
            case 10:
               dealersProducts();
               break;
            case 11:
            saleCount();
            break;
            case 12:
            customersProducts();
            break;
            case 13:
            dealerSalesReport();
            break;
            case 14:
                cout << "Good Luck 👋\n";
                freeMemory();
                return 0;
            default:
                cout << "Invalid choice 🧱 Try again . . .  ↻  \n\n";
                break;
        }
    }
    return 0;
}