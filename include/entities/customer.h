#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "person.h"
#include <string>
class Customer : public Person {
    std::string customerID;
    std::string province;
    std::string city;
public:
    Customer(std::string fName, std::string lName, std::string id, int birth, std::string gen,
             std::string cID, std::string prov, std::string cty);
             
    void showInfo() const override;
    std::string getCustomerID() const;
    std::string getNatinalID() const;
};

#endif