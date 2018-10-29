CXX = g++
CXXFLAGS = -ansi -pedantic -Wall


calculator: calculator.o charlist.o charstack.o doublelist.o doublestack.o operator_string.o
	$(CXX) $(CXXFLAGS) -o calculator calculator.o charlist.o charstack.o doublelist.o doublestack.o operator_string.o

calculator.o: calculator.cxx charlist.h charlist.h doublestack.h doublestack.h
	$(CXX) $(CXXFLAGS) -c calculator.cxx charlist.h charlist.h doublestack.h doublestack.h

charlist.o: charlist.cxx charlist.h
	$(CXX) $(CXXFLAGS) charlist.cxx charlist.h

charstack.o: charstack.h charlist.h
	$(CXX) $(CXXFLAGS) charstack.cxx charstack.h charlist.h


doublelist.o: doublelist.cxx doublelist.h
	$(CXX) $(CXXFLAGS) doublelist.cxx doublelist.h

doublestack.o: doublestack.cxx doublestack.h doublelist.h
	$(CXX) $(CXXFLAGS) doublestack.cxx doublestack.h doublelist.h