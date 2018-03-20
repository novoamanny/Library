# Makefile for Library Management System
CXXFLAGS += --std=c++11

all: div lms
debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

lms: main.o controller.o view.o library.o publication.o patron.o
	$(CXX) $(CXXFLAGS) -o lms main.o controller.o view.o library.o publication.o patron.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
controller.o: controller.cpp *.h
	$(CXX) $(CXXFLAGS) -c controller.cpp
library.o: library.cpp *.h
	$(CXX) $(CXXFLAGS) -c library.cpp
publication.o: publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c publication.cpp
patron.o: patron.cpp *.h 
	$(CXX) $(CXXFLAGS) -c -w patron.cpp
clean:
	-rm -f *.o *.gch lms test_age test_genre test_media test_publication test_library test_view test_view_actual.txt
div:
	@echo
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo
