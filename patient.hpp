#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    string name;
    int age;
    string gender;
public:
    Patient(const string &name, int age, const string &gender);
    string getName() const;
    void printInfo() const;
    Patient() : name(""), age(0), gender("") {}

};

#endif  // PATIENT_HPP
