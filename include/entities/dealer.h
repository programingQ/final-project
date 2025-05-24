#ifndef DEALER_H
#define DEALER_H
#include <string>
using namespace std;
class Dealer {
    string dealerID;
    string name;
    int establishmentYear;
    string economicCode;
    string ownerFirstName;
    string ownerLastName;
    string province;
    string city;
public:
    Dealer(string dID, string n, int year, string econ,
           string first, string last, string prov, string cty);
    void showInfo() const;
    string getDealerID() const;
    string getDealerName() const;
};
#endif