CC = gcc

CFLAGS += -wall -m32
LDFLAGS += -melf_i386

SUBDIRS := lib boot kernel


	
all: iso
	
iso: kernel.bin
	mkdir -p /tmp/tutos
	mkdir -p /tmp/tutos/boot
	cp kernel.bin /tmp/tutos/boot/
	mkdir -p /tmp/tutos/grub
	cp grub.cfg /tmp/tutos/grub/
	grub2-mkrescue -o tutos.iso /tmp/tutos
	rm -rf /tmp/tutos

test: kernel.bin
	qemu-system-i386 -m 256M -kernel kernel.bin

test_iso: iso
	qemu-system-i386 -m 256M -hda tutos.iso
		
kernel.bin: 
	-for d in $(SUBDIRS); do (cd $$d; $(MAKE) ); done
	$(LD) $(LDFLAGS) -o kernel.bin $(foreach dir,$(SUBDIRS),./$(dir)/$(dir).o)

clean:
	@ -for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean); done
	@ $(RM) *.o
	@ $(RM) kernel.bin
	@ $(RM) tutos.iso
	
