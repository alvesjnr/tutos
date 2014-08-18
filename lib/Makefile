
LIB := ../lib
CFLAGS += -m32 -c
LDFLAGS += -melf_i386

OBJECTS := kernelio.o 

all: lib 

lib: $(OBJECTS)
	$(LD) $(LDFLAGS) -r -o lib.o *.o

$(OBJECTS):  
	$(CC) $(CFLAGS) -I$(LIB) *.c

clean:
	@ $(RM) *.o
	
