SYSTEMC_HOME = /usr/local/systemc-2.3.3/

TARGET = full_adder
SOURCE = main.cpp full_adder.cpp
HEADERS = full_adder.h

CXX = g++ 
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lm -o $(TARGET) $(SOURCE) $(HEADERS)

clean:
	rm -f $(TARGET)