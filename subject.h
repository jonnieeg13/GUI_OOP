#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <iostream>
#include <vector>

enum class Subject{

	READING,
	WRITING,
	MATH,
	SCIENCE,
	HISTORY

};
const std::vector<Subject> subjects{
	Subject::READING,
	Subject::WRITING,
	Subject::MATH,
	Subject::SCIENCE,
	Subject::HISTORY
};
std::string to_string(Subject s);

std::ostream& operator<<(std::ostream& ost, const Subject& subject);

Subject load_subject(std::istream& ist);

#endif