CC=gcc

#PKG_CONFIG=`pkg-config --libs --cflags gtk+-2.0`
LDFLAGS=`pkg-config --libs gtk+-2.0`
CFLAGS=-g `pkg-config --cflags gtk+-2.0`

OBJS=icon.o
SRCS=$(OBJS:.o=.c)

TARGET=icon

all: $(TARGET)

icon: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

#dep:
#	gccmakedep $(INC) $(SRCS)

clean:
	rm -rf $(OBJS) $(TARGET) core

