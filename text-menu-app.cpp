#include "text-menu-app.hpp"
#include <iostream>

using namespace std;

TextMenuApp::TextMenuApp(Patients &patients) : patients(patients) {}

void TextMenuApp::run() {
    int option;
    do {
        cout << "1. Print all patients;" << endl;
        cout << "2. Add a new patient;" << endl;
        cout << "3. Remove a patient;" << endl;
        cout << "4. Exit." << endl;
        cout << "Please choose an option (1-4): ";
        cin >> option;

        switch (option) {
            case 1:
                patients.print();
                break;
            case 2: {
                string name, gender;
                int age;
                bool uniqueName = false;
                do {
                    cout << "Please input patient's name: ";
                    cin.ignore(); // Clear input buffer
                    getline(cin, name);
                    if (patients.searchByName(name) == -1) {
                        uniqueName = true;
                    } else {
                        cout << "Existing patient, please input another name!" << endl;
                    }
                } while (!uniqueName);

                cout << "Please input patient's age: ";
                cin >> age;

                bool validGender = false;
                do {
                    cout << "Please input patient's gender (Male/Female): ";
                    cin >> gender;
                    if (gender == "Male" || gender == "Female") {
                        validGender = true;
                    } else {
                        cout << "Invalid input, Male or Female only!" << endl;
                    }
                } while (!validGender);

                patients.addPatient(name, age, gender);
                cout << "Patient added!" << endl;
                break;
            }

            case 3: {
                cout << "Patient List:" << endl;
                patients.printAllNames();
                cout << "Please input the index of the patient you want to remove: ";
                int index;
                cin >> index;
                patients.removePatient(index);
                cout << "Patient removed!" << endl;
                break;
            }
            case 4:
                cout << "Thank you for using the app!" << endl;
                break;
            default:
                cout << "Invalid option! Please choose again." << endl;
        }
    } while (option != 4);
}
