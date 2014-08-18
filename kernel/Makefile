
INCLUDE:= -I../include -I../lib
CFLAGS += -m32 -c
LDFLAGS += -melf_i386

OBJECTS := init.o


all: kernel 

kernel: $(OBJECTS) 
	$(LD) $(LDFLAGS) -r -o kernel.o *.o

$(OBJECTS): 
	$(CC) $(CFLAGS) $(INCLUDE) *.c

clean:
	@ $(RM) *.o
	
