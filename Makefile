# Makefile for Library Management System
CXXFLAGS += --std=c++14
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: div lms
debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

lms: main.o controller.o view.o library.o publication.o patron.o dialogs.o
	$(CXX) $(CXXFLAGS) -o lms main.o controller.o view.o library.o publication.o patron.o dialogs.o $(GTKFLAGS)
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
controller.o: controller.cpp *.h
	$(CXX) $(CXXFLAGS) -c controller.cpp $(GTKFLAGS)
library.o: library.cpp *.h
	$(CXX) $(CXXFLAGS) -c library.cpp
view.o: view.cpp dialogs.o *.h
	$(CXX) $(CXXFLAGS) -c view.cpp $(GTKFLAGS)
publication.o: publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c publication.cpp
patron.o: patron.cpp *.h 
	$(CXX) $(CXXFLAGS) -c -w patron.cpp
dialogs.o: dialogs.cpp *.h
	$(CXX) $(CXXFLAGS) -c dialogs.cpp $(GTKFLAGS)
clean:
	-rm -f *.o *.gch lms test_age test_genre test_media test_publication test_library test_view test_view_actual.txt
div:
	@echo
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo
