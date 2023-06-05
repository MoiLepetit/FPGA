SYSTEMC_HOME = /usr/local/systemc-2.3.3/

TARGET = grey_scale
SOURCE = main.cpp grey_scale.cpp image.cpp
HEADERS = image.h grey_scale.h read_image.h save_image.h

CXX = g++ 
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lm -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)