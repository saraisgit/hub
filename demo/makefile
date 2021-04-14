CC = g++
INFRA_DIR = ../src
INFRA_DIR2 = ../../src
ThermoLib:
	$(CC) -ansi -pedantic -Wall -g -fPIC -std=c++03 -c thermostat.cpp $(INFRA_DIR)/event.cpp $(INFRA_DIR)/agent.cpp  $(INFRA_DIR)/ctorArgs.cpp  $(INFRA_DIR2)/condition.cpp  $(INFRA_DIR2)/mutex.cpp $(INFRA_DIR2)/mutex.cpp -I ../inc -I ../../inc -I../../lib/inc
	$(CC) -shared *.o -lpthread -o ../tests/libThermostat.so
	rm *.o

ACLib:
	$(CC) -ansi -pedantic -Wall -g -fPIC -std=c++03 -c ac.cpp $(INFRA_DIR)/event.cpp $(INFRA_DIR)/agent.cpp  $(INFRA_DIR)/ctorArgs.cpp  $(INFRA_DIR2)/condition.cpp  $(INFRA_DIR2)/mutex.cpp $(INFRA_DIR2)/mutex.cpp -I ../inc -I ../../inc -I../../lib/inc
	$(CC) -shared *.o -lpthread -o ../tests/libAC.so
	rm *.o

LightLib:
	$(CC) -ansi -pedantic -Wall -g -fPIC -std=c++03 -c light.cpp $(INFRA_DIR)/event.cpp $(INFRA_DIR)/agent.cpp  $(INFRA_DIR)/ctorArgs.cpp  $(INFRA_DIR2)/condition.cpp  $(INFRA_DIR2)/mutex.cpp $(INFRA_DIR2)/mutex.cpp -I ../inc -I ../../inc -I../../lib/inc
	$(CC) -shared *.o -lpthread -o ../tests/libLight.so
	rm *.o