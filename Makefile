#Yasmine Brooks
#Dr. Pounds
#February 12, 2019
#Pendulum POC Makefile

CXX = g++
LDLIBS = -lglut -lGL -lGLU -lGLEW libSOIL.a -lm
HEADERS = openGl.h globals.h constants.h prototypes.h Camera.h
OBJS = init.o display.o pendMath.o runPhys.o reshape.o frameRate.o drawShape.o keyboard.o sleepFunc.o drawRoom.o specialKeys.o Camera.o textures.o graph.o

CFLAGS = 
debug ?= n
ifeq ($(debug), y)
	CFLAGS += -g -DDEBUG
else
	CFLAGS += -O2
endif

all: pend tags

pend : main.o $(OBJS) 
	$(CXX) $(CFLAGS) -o pend main.o $(OBJS) $(LDLIBS)

main.o : main.cpp $(HEADERS)
	$(CXX) $(CFLAGS) main.cpp -c

init.o : init.cpp $(HEADERS)
	$(CXX) $(CFLAGS) init.cpp -c

display.o : display.cpp $(HEADERS)
	$(CXX) $(CFLAGS) display.cpp -c

pendMath.o : pendMath.cpp $(HEADERS)
	$(CXX) $(CFLAGS) pendMath.cpp -c

runPhys.o : runPhys.cpp $(HEADERS)
	$(CXX) $(CFLAGS) runPhys.cpp -c

reshape.o : reshape.cpp $(HEADERS)
	$(CXX) $(CFLAGS) reshape.cpp -c

frameRate.o : frameRate.cpp $(HEADERS)
	$(CXX) $(CFLAGS) frameRate.cpp -c

drawShape.o : drawShape.cpp $(HEADERS)
	$(CXX) $(CFLAGS) drawShape.cpp -c

keyboard.o : keyboard.cpp $(HEADERS)
	$(CXX) $(CFLAGS) keyboard.cpp -c

sleepFunc.o : sleepFunc.cpp $(HEADERS)
	$(CXX) $(CFLAGS) sleepFunc.cpp -c

drawRoom.o : drawRoom.cpp $(HEADERS)
	$(CXX) $(CFLAGS) drawRoom.cpp -c

specialKeys.o : specialKeys.cpp $(HEADERS)
	$(CXX) $(CFLAGS) specialKeys.cpp -c

Camera.o : Camera.cpp $(HEADERS)
	$(CXX) $(CFLAGS) Camera.cpp -c

textures.o : textures.cpp $(HEADERS)
	$(CXX) $(CFLAGS) textures.cpp -c

graph.o : graph.cpp $(HEADERS)
	$(CXX) $(CFLAGS) graph.cpp -c



clean:
	rm *.o

pristine:
	rm *.o
	rm pend
	rm tags
	touch *

tags:
	ctags *.h *.cpp









