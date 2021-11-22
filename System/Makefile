CXX=g++
CFLAGS=-I. -Wall -g
TARGET=main
OBJS=   Builder/Falcon9Builder.o Builder/FalconHeavyBuilder.o Builder/RocketBuilder.o \
		Component/Component.o \
		 Component/Engine.o Component/Falcon9Core.o Component/MerlinEngine.o Component/VacuumMerlinEngine.o \
		LaunchStation/LaunchStation.o \
			LaunchStation/Command.o LaunchStation/TakeOff.o LaunchStation/Button.o \
		Memento/RocketState.o \
			Memento/RocketMemento.o Memento/RocketCaretaker.o \
			SpaceCraft/Observer.o SpaceCraft/Payload.o \
			SpaceCraft/Dragon/Human.o \
			SpaceCraft/Dragon/Cargo.o \
			SpaceCraft/Dragon/Dragon.o \
				SpaceCraft/Dragon/CrewDragon.o SpaceCraft/Dragon/DragonSpacecraft.o \
			SpaceCraft/FalconRocket/Falcon9.o \
				SpaceCraft/FalconRocket/FalconHeavy.o SpaceCraft/FalconRocket/Rocket.o \
		Stage/Stage.o \
			Stage/Stage1.o Stage/Stage2.o \
		StarlinkSatellite/StarlinkSatellite.o \
			StarlinkSatellite/Iterator.o StarlinkSatellite/Laser.o \
        main.o

all: $(OBJS)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./main

clean:
	rm -f $(TARGET) $(OBJS) main.exe