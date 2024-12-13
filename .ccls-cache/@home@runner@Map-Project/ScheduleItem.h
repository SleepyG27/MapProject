
#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <string>
#include <iostream>

class ScheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totEnrl;
    int capEnrl;
    std::string instructor;

public:
    ScheduleItem(
        std::string subj = "", std::string cat = "", std::string sec = "",
        std::string comp = "", std::string sess = "", int un = 0,
        int tot = 0, int cap = 0, std::string inst = "");

    std::string getKey() const;
    std::string getSubject() const;
    std::string getCatalog() const;
    std::string getSection() const;
    std::string getInstructor() const;

    bool operator==(const ScheduleItem& other) const;
    bool operator!=(const ScheduleItem& other) const;
    bool operator>=(const ScheduleItem& other) const;

    void print() const;
};

#endif
