#ifndef _SECTION_H
#define _SECTION_H

#include <iostream>
#include <fstream>
#include "course.h"
#include "teacher.h"
#include "semester.h"

class Section{
	public:
		Section(Course course,Teacher& teacher,Semester semester,int year);
		void save(std::ostream& ost);
		Section(std::istream& ist);
		std::string to_string() const;
		friend std::ostream& operator<<(std::ostream& ost, const Section& section);
		
	private:
		Course _course;
		Teacher& _teacher;
		Semester _semester;
		int year;
};

#endif