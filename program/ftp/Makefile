#CC=arm-openwrt-linux-gnueabi-gcc
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lm
SOURCES=server.c handles.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ftp

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *.o ftp

push:
	adb push ftp /mnt/UDISK
adb:
	adb forward tcp:31879 tcp:31879
	adb forward tcp:8021 tcp:8021
