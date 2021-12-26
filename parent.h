#ifndef __PARENT_H
#define __PARENT_H

#include "person.h"
#include <iostream>
#include <string>
#include <vector>

class Student;


class Parent : public Person{

	public:
		Parent(std::string name, std::string email);
		using Person::Person;
		void add_student(Student& student);		
		std::string full_info() const override;
		Parent(std::istream& ist); 
		virtual void save(std::ostream& ost);
		typedef std::vector<Student*>::iterator iterator;
		typedef std::vector<Student*>::const_iterator const_iterator;
		iterator begin() {return _students.begin();}
		iterator end() {return _students.end();}
	protected:
		std::vector<Student*> _students;

};

#endif