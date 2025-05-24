#include "../../include/entities/customer.h"
#include <iostream>
using namespace std;
Customer::Customer(string fName, string lName, string id, int birth, string gen,
                   string cID, string prov, string cty)
    : Person(fName, lName, id, birth, gen), customerID(cID), province(prov), city(cty) {}

void Customer::showInfo() const {
    Person::showInfo();
    cout << "Customer ID: " << customerID << "\n"
         << "Province: " << province << "\n"
         << "City: " << city << endl;
}

string Customer::getCustomerID() const {
    return customerID;
}