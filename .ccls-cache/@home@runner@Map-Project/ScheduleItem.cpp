
#include "ScheduleItem.h"

ScheduleItem::ScheduleItem(
    std::string subj, std::string cat, std::string sec,
    std::string comp, std::string sess, int un,
    int tot, int cap, std::string inst)
    : subject(subj), catalog(cat), section(sec),
      component(comp), session(sess), units(un),
      totEnrl(tot), capEnrl(cap), instructor(inst) {}

std::string ScheduleItem::getKey() const {
    return subject + "_" + catalog + "_" + section;
}

std::string ScheduleItem::getSubject() const { return subject; }
std::string ScheduleItem::getCatalog() const { return catalog; }
std::string ScheduleItem::getSection() const { return section; }
std::string ScheduleItem::getInstructor() const { return instructor; }

bool ScheduleItem::operator==(const ScheduleItem& other) const {
    return getKey() == other.getKey();
}

bool ScheduleItem::operator!=(const ScheduleItem& other) const {
    return !(*this == other);
}

bool ScheduleItem::operator>=(const ScheduleItem& other) const {
    return getKey() >= other.getKey();
}

void ScheduleItem::print() const {
    std::cout << subject << "\t" << catalog << "\t" << section << "\t"
              << component << "\t" << session << "\t" << units << "\t"
              << totEnrl << "\t" << capEnrl << "\t" << instructor << "\n";
}
