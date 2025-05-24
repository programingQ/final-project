#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person {
    string firstName;
    string lastName;
    string nationalID;
    int birthYear;
    string gender;
public:
    Person(string fName, string lName, string id, int birth, string gen);
    virtual void showInfo() const;
    string getNationalID() const ;
};

#endif