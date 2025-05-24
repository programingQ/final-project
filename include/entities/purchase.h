#ifndef PURCHASE_H
#define PURCHASE_H
#include "customer.h"
#include "product.h"
#include "dealer.h"
using namespace std;
class Purchase {
    Customer* customer;
    Product* product;
    Dealer* dealer;
    int quantity;
    string purchaseDate;
public:
    Purchase(Customer* cust, Product* prod, Dealer* deal, int qty, string date);
    void showInfo() const;
    Customer* getCustomer() const;
    Product* getProduct() const;
    Dealer* getDealer() const;
    int getQuantity() const;
    float getTotalAmount() const;
    string getProductId() const;
    string getCustomerId() const;
    string getDealerId() const ;
};
#endif