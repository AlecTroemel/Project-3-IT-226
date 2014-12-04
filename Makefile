Driver: Driver.o
	g++ -o Driver Driver.o Student.o Gradebook.o Course.o Assignment.o

Driver.o: Student.o
	g++ -c Driver.cpp

Student.o: Student.h.gch
	g++ -c Student.cpp

Student.h.gch: Gradebook.o
	g++ -c Student.h

Gradebook.o: Gradebook.h.gch
	g++ -c Gradebook.cpp

Gradebook.h.gch: Course.o Assignment.o
	g++ -c Gradebook.h

Course.o: Course.h.gch
	g++ -c Course.cpp

Course.h.gch: Course.h
	g++ -c Course.h

Assignment.o: Assignment.h.gch
	g++ -c Assignment.cpp

Assignment.h.gch: Assignment.h
	g++ -c Assignment.h
		
clean:

