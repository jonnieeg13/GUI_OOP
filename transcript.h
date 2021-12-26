#ifndef _TRANCRIPT_H
#define _TRANSCRIPT_H

#include <iostream>
#include <fstream>
#include "grade.h"
#include "student.h"
#include "section.h"

class Transcript{
	public:
		Transcript(Student& student, Section& section);
		void save(std::ostream& ost);
		Transcript(std::istream& ist); 
		void assign_grade(Grade grade);
		friend std::ostream& operator<<(std::ostream& ost,const Transcript& transcript);	
	private:
		Section& _section;
		Student& _student;
		Grade _grade;
};



#endif