
#include "Schedule.h"
#include <iostream>

int main() {
    Schedule schedule;
    std::ifstream infile("STEM - Summer 2022 Schedule of Classes as of 05-02-22(1).csv");

    if (!infile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    schedule.initSchedule(infile);
    infile.close();

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print schedule\n";
        std::cout << "2. Find by subject\n";
        std::cout << "3. Find by subject and catalog\n";
        std::cout << "4. Find by instructor\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.print();
            break;
        case 2: {
            std::string subject;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            schedule.findBySubject(subject);
            break;
        }
        case 3: {
            std::string subject, catalog;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            std::cout << "Enter catalog: ";
            std::cin >> catalog;
            schedule.findBySubjectAndCatalog(subject, catalog);
            break;
        }
        case 4: {
            std::string lastName;
            std::cout << "Enter instructor's last name: ";
            std::cin >> lastName;
            schedule.findByInstructor(lastName);
            break;
        }
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
