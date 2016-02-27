
SOURCE = ussdEncode.c
LIBS = -lm
TARGET = ussdEncode

# add -g for debugging symbols

all: $(SOURCE)
	gcc -o $(TARGET) $(LIBS) $(SOURCE) && strip $(TARGET)
