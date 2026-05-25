all:
	g++ main.cpp Elevator.cpp Dispatcher.cpp \
	Request.cpp Building.cpp Logger.cpp \
	-o elevator_simulator -std=c++17