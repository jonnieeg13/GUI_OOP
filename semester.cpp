#include "semester.h"

std::string to_string(Semester s) {

	std::string semester = "";

	switch (s)
	{
        case Semester::FALL:
            semester = "Fall";
            break;
        case Semester::SPRING:
            semester = "Spring";
            break;
        case Semester::SUMMER:
            semester = "Summer";
            break;
        default:
            throw std::runtime_error{"Invalid Semester"};
            break;
	} 

	return semester;
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester){
	ost << to_string(semester);
	return ost;
}

Semester load_semester(std::istream& ist){
	std::string s;
	std::getline(ist, s);
	if(s =="Fall" ) {return Semester::FALL;} 
	if(s == "Spring"){return Semester::SPRING;} 
	if(s == "Summer"){return Semester::SUMMER; }
	throw std::runtime_error{"Invalid Semester"};
}

