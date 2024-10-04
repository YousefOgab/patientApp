#include "patients.hpp"
#include <iostream>
using namespace std;

Patients::Patients(): patients(nullptr), capacity(100), count(0) {}

Patients::Patients(Patient *initialList, int count): count(count){
    capacity = 2 * count;
    patients = new Patient[capacity];
    for (int i = 0; i < count; ++i){
        patients[i] = initialList[i];
    }
}

Patients::~Patients(){
    delete[] patients;
}

void Patients::addPatient(string name, int age, string gender){
    if (searchByName(name) != -1) {
        cout << "Existing patient, please input another name!" << endl;
        return;
    }
     if (gender != "Male" && gender != "Female") {
        cout << "Invalid input, Male or Female only!" << endl;
        return;
    }

    if (count >= capacity) {
    reAllocate();
    }
        patients[count] = Patient(name, age, gender);
        count++;
    }
    
    


void Patients::reAllocate(){
    capacity *= 2; // double the space
    Patient *newList = new Patient[capacity]; // copy create a new dynamic array
    for (int i = 0; i < count; ++i){ // copy the existing array to the new array
        newList[i] = patients[i];
    }
    delete [] patients; //delete the old array to avoid memory leak
    patients = newList; //assign the new array to the instance variable
}

void Patients::removePatient(int index){// remove an item in the dynamic array
   for (int i = index; i < count - 1; ++i){
        patients[i] = patients[i + 1];
   } 
   count--; //after removing, decrease count
}

int Patients::searchByName(const string &name) const {
    for (int i = 0; i < count; ++i) {
        if (patients[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

int Patients::getCount() const {
    return count;
}

void Patients::print() const {
    for (int i = 0; i < count; ++i) {
        cout << "Patient: " << i << endl;
        patients[i].printInfo();
        cout << endl;
    }
    cout << count << " patients in total." << endl;
}

void Patients::printAllNames() const {
    for (int i = 0; i < count; ++i) {
        cout << "Patient " << i << ": " << patients[i].getName() << endl;
    }
}
