CXX=g++
CFLAGS=-I. -Wall
TARGET=main
OBJS= Component.o ComponentFactory.o Core.o Engine.o Falcon9Core.o MerlinEngine.o VacuumMerlinEngine.o Factory.o CoreFactory.o MerlinEngineFactory.o VacuumMerlinEngineFactory.o main.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)