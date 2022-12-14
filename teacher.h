#ifndef _TEACHER_H
#define _TEACHER_H

#include "person.h"
#include <iostream>
#include <fstream>
#include <string>

class Teacher : public Person{
	public:
		using Person::Person;
        Teacher(std::istream &ist); 
		void save(std::ostream &ost) override;
        std::string full_info() const override;	

};

#endif