
INCLUDE := -I../include
CFLAGS += -m32 -c
LDFLAGS += -melf_i386

OBJECTS := kernelio.o utils.o 

all: lib 

lib: $(OBJECTS)
	$(LD) $(LDFLAGS) -r -o lib.o *.o

$(OBJECTS):  
	$(CC) $(CFLAGS) $(INCLUDE) *.c

clean:
	@ $(RM) *.o
	
