#ifndef __COURSE_H
#define __COURSE_H

#include "subject.h"

#include <iostream>
#include <fstream>

class Course{
	public:
		Course(Subject subject, int grade);
		Course(std::istream& ist);
		void save(std::ostream& ost);
		std::string to_string() const;
		friend std::ostream& operator<<(std::ostream& ost, const Course& course);		
	private:
		Subject _subject;
		int _grade;

};


#endif