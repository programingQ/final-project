#include "../../include/entities/product.h"
#include <iostream>
using namespace std;
Product::Product(string pID, string n, float pr, string b, float w)
    : productID(pID), name(n), price(pr), brand(b), weight(w) {}

void Product::showInfo() const {
    cout << "Product ID: " << productID << "\n"
              << "Name: " << name << "\n"
              << "Price: " << price << "\n"
              << "Brand: " << brand << "\n"
              << "Weight: " << weight << endl;
}

string Product::getProductID() const {
    return productID;
}
float Product::getPrice() const {
    return price;
}