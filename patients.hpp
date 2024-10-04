#ifndef PATIENTS_HPP
#define PATIENTS_HPP

#include "patient.hpp"
#include <string>

class Patients {
  Patient *patients;
  int capacity;
  int count;
  void reAllocate();
 public:
  Patients();
  Patients(Patient *initialList, int count);
  ~Patients();
  void addPatient(std::string name, int age, std::string gender);
  void removePatient(int index);
  int searchByName(const std::string &name) const;
  int getCount() const;
  void print() const;
  void printAllNames() const;
};

#endif //PATIENTS_HPP
