#include "../../include/entities/dealer.h"
#include <iostream>
using namespace std;
Dealer::Dealer(string dID, string n, int year, string econ,
               string first, string last, string prov, string cty)
    : dealerID(dID), name(n), establishmentYear(year), economicCode(econ),
      ownerFirstName(first), ownerLastName(last), province(prov), city(cty) {}
void Dealer::showInfo() const {
    cout << "Dealer ID: " << dealerID << "\n"
         << "Name: " << name << "\n"
         << "Establishment Year: " << establishmentYear << "\n"
         << "Economic Code: " << economicCode << "\n"
         << "Owner: " << ownerFirstName << " " << ownerLastName << "\n"
         << "Province: " << province << ", City: " << city << endl;
}
string Dealer::getDealerID() const {
    return dealerID;
}
string Dealer::getDealerName() const {
    return name;
}