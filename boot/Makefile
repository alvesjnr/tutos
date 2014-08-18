
INCLUDE := -I../lib -I../include
CFLAGS += -m32 -c
LDFLAGS += -melf_i386

all: boot

boot: bootstrap.o _boot.o 
	$(LD) $(LDFLAGS) -r -o boot.o _boot.o bootstrap.o

bootstrap.o: bootstrap.S 
	$(CC) $(CFLAGS) $(INCLUDE) bootstrap.S

_boot.o: _boot.c
	$(CC) $(CFLAGS) $(INCLUDE) _boot.c

clean:
	@ $(RM) *.o
	
