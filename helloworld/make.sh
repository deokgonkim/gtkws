gcc \
-Wall \
-g helloworld.c \
-o hello_world \
`pkg-config --libs --cflags gtk+-2.0` \

