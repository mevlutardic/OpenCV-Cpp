CXXFLAGS = -O2 -g -Wall -fmessage-length=0 `pkg-config opencv --cflags ` -I /usr/include/libusb-1.0
OBJS = Readimage.cpp
LIBS = `pkg-config opencv --cflags --libs`
TARGET = Readimage

$(TARGET):$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

