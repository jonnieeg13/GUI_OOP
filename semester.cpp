#include "semester.h"

std::string to_string(Semester s) {

 	if(s == Semester::FALL) {return "fall";} 
	if(s == Semester::SPRING){return "spring";} 
	if(s == Semester::SUMMER){return "summer";}
	else throw std::runtime_error{"Invalid Semester"}; 
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester){
	ost << to_string(semester);
	return ost;
}

Semester load_semester(std::istream& ist){
	std::string s;
	std::getline(ist, s);
	if(s =="fall" ) {return Semester::FALL;} 
	if(s == "spring"){return Semester::SPRING;} 
	if(s == "summer"){return Semester::SUMMER; }
	else throw std::runtime_error{"Invalid Semester"};
}

