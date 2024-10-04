#include "patient.hpp"
#include <iostream>
#include <string>

using namespace std;

Patient::Patient(const string &nameInput, int ageInput, const string &genderInput) {
    name = nameInput;
    age = ageInput;
    gender = genderInput;
}

string Patient::getName() const {
    return name;
}

void Patient::printInfo() const {
    cout << "Patient name: " << name << endl;
    cout << "Patient age: " << age << endl;
    cout << "Patient gender: " << gender << endl;
}
