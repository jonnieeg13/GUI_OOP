#include "grade.h"

std::ostream& operator<<(std::ostream& ost, const Grade& grade) {
    ost << grade_tostring.at(grade);
    return ost;
}

Grade load_grade(std::istream& ist) {
    
    std::string load;
    std::getline(ist, load);
    for(const auto& [grade, g] : grade_tostring)
        if(g == load) return grade;
    throw std::runtime_error{"Invalid Grade!"};
}