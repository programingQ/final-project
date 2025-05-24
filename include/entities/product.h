#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
private:
    std::string productID;
    std::string name;
    float price;
    std::string brand;
    float weight;

public:
    Product(std::string pID, std::string n, float pr, std::string b, float w);
    void showInfo() const;
    std::string getProductID() const;
    float getPrice() const;
};

#endif