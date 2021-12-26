#ifndef __SEMESTER_H
#define __SEMESTER_H

#include <iostream>
#include <vector>

enum class Semester{

	FALL,
	SPRING,
	SUMMER

};

const std::vector<Semester> semesters{
	Semester::FALL,
	Semester::SPRING,
	Semester::SUMMER
};

std::string to_string(Semester s);

std::ostream& operator<<(std::ostream& ost, const Semester& semester);

Semester load_semester(std::istream& ist);

#endif