#include "section.h"


Section::Section(Course course,Teacher& teacher,Semester semester,int year) : _course{course}, _teacher{teacher} ,_semester{semester}, year{year} {

 }

void Section::save(std::ostream& ost){
	_course.save(ost);
	_teacher.save(ost);
	ost << _semester << "\n";
	ost << year << "\n";
	
}
Section::Section(std::istream& ist) : _course{ist},  _teacher{*(new Teacher{ist})} {
	_semester = load_semester(ist);
	ist >> year; ist.ignore(32767, '\n');
	
}

std::string Section::to_string() const {
	
	return _course.to_string() + " for " + ::to_string(_semester) + " " + std::to_string(year) + " ("+ "taught by "+ _teacher.to_string() + ")";
}
std::ostream& operator<<(std::ostream& ost, const Section& section){
	
	ost << section.to_string();
	return ost;
}
