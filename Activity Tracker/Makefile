TAG = tag.cpp tag.h
TASK = task.cpp task.h
SCHEDULETASK = scheduleTask.cpp scheduleTask.h
TODOS = todos.cpp todos.h
APP = app.cpp app.h
CXXFLAGS = -g -Wall -std=c++11
CXX = g++ 
CCC = $(CXX) $(CXXFLAGS)

OBJECTS = main.o scheduleTask.o task.o tag.o todos.o app.o

.PHONY: all clean
all: execute

run: $(OBJECTS)
	$(CCC) -o run $(OBJECTS)

main.o: main.cpp
	$(CCC) -c main.cpp

tag.o: $(TAG)
	$(CCC) -c tag.cpp

task.o: $(TASK)
	$(CCC) -c task.cpp

scheduleTask.o: $(SCHEDULETASK)
	$(CCC) -c scheduleTask.cpp

todos.o: $(TODOS)
	$(CCC) -c todos.cpp

app.o: $(APP)
	$(CCC) -c app.cpp

execute: run
	./run

clean:
	rm -f *.o run

