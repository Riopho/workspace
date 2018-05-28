LIB_PATH=-L../hiredis-master -L./libevent-2.1.8-stable/.libs
INCLUDE_PATH=-I../hiredis-master -I./libevent-2.1.8-stable/include -I../hiredis-master/adapters
AsyncDemo:HiredisAsynDemo.cpp
	g++ -g -lstdc++ -lhiredis -levent -o a.out HiredisAsynDemo.cpp $(LIB_PATH) $(INCLUDE_PATH) 
clean:
	rm -rf AsyncDemo
