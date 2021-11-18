CXX=g++
CFLAGS=-I. -Wall
TARGET=main
OBJS=   Builder/Falcon9Builder.o Builder/FalconHeavyBuilder.o Builder/RocketBuilder.o \
		Component/Component.o \
			Component/Core.o Component/Engine.o Component/Falcon9Core.o Component/MerlinEngine.o Component/VacuumMerlinEngine.o \
        Factory/Factory.o \
			Factory/ComponentFactory.o Factory/CoreFactory.o Factory/DragonFactory.o Factory/FalconRocketFactory.o \
			Factory/MerlinEngineFactory.o Factory/SpaceCraftFactory.o Factory/VacuumMerlinEngineFactory.o \
		LaunchStation/LaunchStation.o \
			LaunchStation/Command.o LaunchStation/Iterator2.o LaunchStation/Land.o LaunchStation/TakeOff.o \
		Memento/Memento.o \
			Memento/Caretaker.o Memento/DragonCaretaker.o Memento/DragonMemento.o Memento/FalconCaretaker.o Memento/FalconMemento.o \
		SpaceCraft/SpaceCraft.o \
			SpaceCraft/Observer.o SpaceCraft/Payload.o \
			SpaceCraft/Dragon/Dragon.o \
				SpaceCraft/Dragon/CrewDragon.o SpaceCraft/Dragon/DragonSpacecraft.o SpaceCraft/Dragon/Human.o SpaceCraft/Dragon/Modules.o \
			SpaceCraft/FalconRocket/Falcon9.o \
				SpaceCraft/FalconRocket/FalconHeavy.o SpaceCraft/FalconRocket/Rocket.o \
		Stage/Stage.o \
			Stage/Stage1.o Stage/Stage2.o \
		StarlinkSatellite/StarlinkSatellite.o \
			StarlinkSatellite/Iterator.o StarlinkSatellite/Laser.o \
        main.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)