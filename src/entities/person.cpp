#include "../../include/entities/person.h"
#include <iostream>
using namespace std;
Person::Person(string fName, string lName, string id, int birth, string gen)
    : firstName(fName), lastName(lName), nationalID(id), birthYear(birth), gender(gen) {}

void Person::showInfo() const {
    cout << "Name: " << firstName << " " << lastName << "\n"
         << "National ID: " << nationalID << "\n"
         << "Birth Year: " << birthYear << "\n"
         << "Gender: " << gender << endl;
}

string Person::getNationalID() const {
    return nationalID;
}