#include "transcript.h"


Transcript::Transcript(Student& student, Section& section) : _student{student}, _section{section}{ 
}

Transcript::Transcript(std::istream& ist) :_section{*(new Section{ist})}, _student{*(new Student{ist})} {
	_grade = load_grade(ist);
	
}

void Transcript::save(std::ostream& ost){
	_section.save(ost);
	_student.save(ost);
	ost << _grade << "\n";
	
}


void Transcript::assign_grade(Grade grade){

	_grade = grade;
}

std::ostream& operator<<(std::ostream& ost,const Transcript& transcript){
	ost << "In " << transcript._section <<": " << transcript._student << " earned a " << transcript._grade;
	return ost;
}