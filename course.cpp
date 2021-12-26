#include "course.h"

Course::Course(Subject subject, int grade) : _subject{subject}, _grade{grade} {}

Course::Course(std::istream& ist) {
	_subject = load_subject(ist);
	ist >> _grade; ist.ignore(32767, '\n');
}

void Course::save(std::ostream& ost) {
	ost << _subject << "\n";
	ost << _grade << "\n";
}
std::string Course::to_string() const {
	return ::to_string(_subject) + " (" + " grade " + std::to_string(_grade) + ") ";
}
std::ostream& operator<<(std::ostream& ost, const Course& course){

	ost << course.to_string();
	return ost;

}