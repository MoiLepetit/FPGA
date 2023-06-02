SYSTEMC_HOME = /usr/local/systemc-2.3.3/

TARGET = grey_scale
SOURCE = main.cpp grey_scale.cpp
HEADERS = grey_scale.h

CXX = g++ 
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lm -o $(TARGET) $(SOURCE) $(HEADERS)
	./$(TARGET)

clean:
	rm -f $(TARGET)