CC = gcc
# add -g for debugging symbols
REL_FLAGS = -W -O2
DEB_FLAGS = -W -g
CFLAGS = $(REL_FLAGS)
#OPTIONS = -DDEBUG
INCLUDES =
LDFLAGS =
LIBS = -lm
TARGETS = encode decode

all: $(TARGETS)

$(TARGETS): %: %.o
	@echo [LD] $@
	@$(CC) $(CFLAGS) -o $@ $< $(LIBS) $(LDFLAGS)

%.o: %.c
	@echo [CC] $@
	@$(CC) $(OPTIONS) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@echo [RM]
	@rm -f *.o $(TARGETS)

remake: clean all
