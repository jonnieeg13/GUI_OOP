#include "parent.h"
#include "student.h"

Student::Student(std::string name, std::string email, int grade) : Person(name,email), grade{grade} {}

void Student::add_parent(Parent& parent){
	_parents.push_back(&parent);

}		

std::string Student::full_info() const {

	
	 std::string info = Person::full_info() + " in grade " + std::to_string(grade) + " Parents: "; 
	 for (auto p: _parents){

	 	info = info + " " + p->to_string();

	 } 
	 return info;

}

Student::Student(std::istream& ist) : Person(ist){ 
	ist >> grade;
	ist.ignore(32767, '\n');
}

void Student::save(std::ostream& ost){
	ost << name << std::endl;
	ost << email << std::endl;
	ost << grade << std::endl;
}