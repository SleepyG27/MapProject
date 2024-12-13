
#include "Schedule.h"
#include <sstream>
#include <iostream>

void Schedule::initSchedule(std::ifstream& infile) {
    std::string line;
    getline(infile, line); // Skip header line

    while (getline(infile, line)) {
        std::istringstream ss(line);
        std::string subject, catalog, section, component, session, instructor;
        int units, totEnrl, capEnrl;

        try {
            getline(ss, subject, ',');
            getline(ss, catalog, ',');
            getline(ss, section, ',');
            getline(ss, component, ',');
            getline(ss, session, ',');

            if (!(ss >> units)) throw std::runtime_error("Invalid units");
            ss.ignore();

            if (!(ss >> totEnrl)) throw std::runtime_error("Invalid total enrollment");
            ss.ignore();

            if (!(ss >> capEnrl)) throw std::runtime_error("Invalid capacity");
            ss.ignore();

            getline(ss, instructor, ',');

            ScheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
            scheduleMap[item.getKey()] = item;
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\n";
        }
    }
}

void Schedule::print() const {
    std::cout << "Subject\tCatalog\tSection\tComponent\tSession\tUnits\tTotEnrl\tCapEnrl\tInstructor\n";
    for (const auto& [key, item] : scheduleMap) {
        item.print();
    }
}

void Schedule::findBySubject(const std::string& subject) const {
    for (const auto& [key, item] : scheduleMap) {
        if (item.getSubject() == subject) {
            item.print();
        }
    }
}

void Schedule::findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const {
    for (const auto& [key, item] : scheduleMap) {
        if (item.getSubject() == subject && item.getCatalog() == catalog) {
            item.print();
        }
    }
}

void Schedule::findByInstructor(const std::string& lastName) const {
    for (const auto& [key, item] : scheduleMap) {
        std::string instructor = item.getInstructor();
        if (instructor.find(lastName) != std::string::npos) {
            item.print();
        }
    }
}
