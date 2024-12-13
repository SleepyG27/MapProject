
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleItem.h"
#include <map>
#include <string>
#include <fstream>

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

public:
    void initSchedule(std::ifstream& infile);
    void print() const;
    void findBySubject(const std::string& subject) const;
    void findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const;
    void findByInstructor(const std::string& lastName) const;
};

#endif
