#include "student.h"
#include "parent.h"

Parent::Parent(std::string name, std::string email) : Person(name,email) {}

void Parent::add_student(Student& student){
	_students.push_back(&student);

}		

std::string Parent::full_info() const{

	std::string info = Person::full_info() + " Student: ";
	for (auto s: _students) {
		info = info + " " + s->to_string();
		
	}
	return info;
	
}

Parent::Parent(std::istream& ist) : Person(ist){}

void Parent::save(std::ostream& ost){
	ost << name << std::endl;
	ost << email << std::endl;
}