#include "../../include/entities/purchase.h"
#include <iostream>
using namespace std;
Purchase::Purchase(Customer* cust, Product* prod, Dealer* deal, int qty, string date)
    : customer(cust), product(prod), dealer(deal), quantity(qty), purchaseDate(date) {}
void Purchase::showInfo() const {
    cout << "Purchase Info:\n";
    customer->showInfo();
    product->showInfo();
    dealer->showInfo();
    cout << "Quantity: " << quantity << "\n"
         << "Date: " << purchaseDate << endl;
}

Customer* Purchase::getCustomer() const {
    return customer;
}

Product* Purchase::getProduct() const {
    return product;
}

Dealer* Purchase::getDealer() const {
    return dealer;
}

int Purchase::getQuantity() const {
    return quantity;
}

float Purchase::getTotalAmount() const {
    return quantity * product->getPrice();
}
string Purchase::getProductId() const {
string pId = getProduct()->getProductID();
return pId;
}
string Purchase::getCustomerId() const {
    string cId = getCustomer()->getCustomerID();
    return cId;
}
string Purchase::getDealerId() const {
    string dId = getDealer()->getDealerID();
    return dId;
}