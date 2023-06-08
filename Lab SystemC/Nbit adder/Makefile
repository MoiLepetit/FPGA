SYSTEMC_HOME = /usr/local/systemc-2.3.3/

TARGET = nb_adder
SOURCE = main.cpp "../Full adder/full_adder.cpp" nb_adder.cpp
HEADERS = nb_adder.h "../Full adder/full_adder.h"

CXX = g++ 
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lm -o $(TARGET) $(SOURCE) $(HEADERS)

clean:
	rm -f $(TARGET)