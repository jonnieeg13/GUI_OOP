#include "subject.h"

std::string to_string(Subject s) {
 	if(s == Subject::READING) {return "reading";}
	if(s == Subject::WRITING) {return "writing";}
	if(s == Subject::MATH) {return "math";}
	if(s == Subject::SCIENCE) {return "science";}
	if(s == Subject::HISTORY) {return "history";}
	else throw std::runtime_error{"Invalid Subject"};
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject){
	ost << to_string(subject);
	return ost;
}

Subject load_subject(std::istream& ist){
	std::string s;
	std::getline(ist, s);
	if(s == "reading") {return Subject::READING;}
	if(s == "writing") {return Subject::WRITING;}
	if(s == "math")    {return Subject::MATH;}
	if(s == "science") {return Subject::SCIENCE;}
	if(s == "history") {return Subject::HISTORY;}
	else throw std::runtime_error{"Invalid Subject"};
}

