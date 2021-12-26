#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>
#include <fstream>

class Person{

	public:
		Person(std::string name, std::string email);
		std::string to_string() const;
		virtual std::string full_info() const;
		friend std::ostream& operator<<(std::ostream& ost, const Person& person);
		Person(std::istream& ist);
		virtual void save(std::ostream& ost);

	protected:
		std::string name;
		std::string email;

};



#endif