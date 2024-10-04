#ifndef TEXT_MENU_APP_HPP
#define TEXT_MENU_APP_HPP

#include "patients.hpp"
#include <string>

class TextMenuApp {
 private:
  Patients &patients;
 public:
  TextMenuApp(Patients &patients);
  void run();
};

#endif  // TEXT_MENU_APP_HPP
