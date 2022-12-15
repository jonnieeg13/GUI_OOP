#include "subject.h"

std::string to_string(Subject s) {

	std::string subject = "";

	switch (s)
	{
        case Subject::READING:
            subject = "Reading";
            break;

        case Subject::WRITING: 
            subject = "Writing";
			break;
            
		case Subject::MATH:
			return "Math";
			break;

		case Subject::SCIENCE:
			return "Science";
			break;

		case Subject::HISTORY:
			return "History";
			break;
			
		default:
			throw std::runtime_error{"Invalid Subject"};
			break;
	}

	return subject;
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject){	
	ost << to_string(subject);
	return ost;
}

Subject load_subject(std::istream& ist){
	
	std::string s;
	std::getline(ist, s);
	if(s == "Reading") {return Subject::READING;}
	else if(s == "Writing") {return Subject::WRITING;}
	else if(s == "Math")    {return Subject::MATH;}
	else if(s == "Science") {return Subject::SCIENCE;}
	else if(s == "History") {return Subject::HISTORY;}
	else throw std::runtime_error{"Invalid Subject: " + s};

}
