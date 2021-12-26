#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"
#include <iostream>
#include <string>
#include <vector>
class Parent;


class Student : public Person{
	
	public:
		Student(std::string name, std::string email, int grade);
		void add_parent(Parent& parent);		
		std::string full_info() const override;
		Student(std::istream& ist);
		virtual void save(std::ostream& ost);
		typedef std::vector<Parent*>::iterator iterator;
		typedef std::vector<Parent*>::const_iterator const_iterator;
		iterator begin() {return _parents.begin();}
		iterator end() {return _parents.end();}
	protected:
		int grade;
		std::vector<Parent*> _parents;

};

#endif