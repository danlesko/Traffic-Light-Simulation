all: Driver.o TrafficSim.o Vehicle.o IntersectionFlowRate.o Linked_List.o ResultVehicle.o
	g++ -ansi -Wall Driver.o TrafficSim.o Vehicle.o IntersectionFlowRate.o Linked_List.o ResultVehicle.o -o Driver.out

Vehicle.o: Vehicle.cpp
	g++ -ansi -Wall -c Vehicle.cpp

TrafficSim.o: TrafficSim.cpp
	g++ -ansi -Wall -c TrafficSim.cpp

IntersectionFlowRate.o: IntersectionFlowRate.cpp
	g++ -ansi -Wall -c IntersectionFlowRate.cpp

Linked_List.o: Linked_List.cpp
	g++ -ansi -Wall -c Linked_List.cpp

ResultVehicle.o: ResultVehicle.cpp
	g++ -ansi -Wall -c ResultVehicle.cpp

Driver.o: Driver.cpp
	g++ -ansi -Wall -c Driver.cpp

run:
	./Driver.out $(STRING)

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[
