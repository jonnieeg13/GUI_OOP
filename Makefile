CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mainwin smart

mainwin: main.o mainwin.o person.o student.o parent.o entrydialog.o semester.o subject.o course.o section.o teacher.o transcript.o grade.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o person.o student.o parent.o entrydialog.o semester.o subject.o course.o section.o teacher.o transcript.o grade.o $(GTKFLAGS) -o mainwin

smart: main05.o person.o student.o parent.o *.h       
	$(CXX) $(CXXFLAGS) main05.o person.o student.o parent.o -o smart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

main05.o: main05.cpp *.h       
	$(CXX) $(CXXFLAGS) -c main05.cpp -o main05.o

person.o: person.cpp *.h       
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o: student.cpp *.h       
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o: parent.cpp *.h       
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

semester.o: semester.cpp *.h       
	$(CXX) $(CXXFLAGS) -c semester.cpp -o semester.o

subject.o: subject.cpp *.h       
	$(CXX) $(CXXFLAGS) -c subject.cpp -o subject.o 

course.o: course.cpp *.h       
	$(CXX) $(CXXFLAGS) -c course.cpp -o course.o

section.o: section.cpp *.h       
	$(CXX) $(CXXFLAGS) -c section.cpp -o section.o

teacher.o: teacher.cpp *.h       
	$(CXX) $(CXXFLAGS) -c teacher.cpp -o teacher.o 

transcript.o: transcript.cpp *.h       
	$(CXX) $(CXXFLAGS) -c transcript.cpp -o transcript.o

grade.o: grade.cpp *.h       
	$(CXX) $(CXXFLAGS) -c grade.cpp -o grade.o

debug: CXXFLAGS += -g
debug: mainwin smart

clean:       
	rm -f *.o *.gch *~ *a.out mainwin smart