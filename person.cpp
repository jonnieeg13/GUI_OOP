#include "person.h"

Person::Person(std::string name, std::string email) : name{name}, email{email} {}

std::string Person::to_string() const{

	return name;

}

std::string Person::full_info() const{

	return name +  "( " + email +")";
}

std::ostream& operator<<(std::ostream& ost, const Person& person){

	ost << person.to_string();
	return ost;
}

Person::Person(std::istream& ist){
	ist >> name; ist.ignore(32767, '\n');
	ist >> email; ist.ignore(32767, '\n');
	
}

void Person::save(std::ostream& ost){
	ost << name << std::endl;
	ost << email << std::endl;
}