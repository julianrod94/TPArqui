include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
ASMSOURCES=$(wildcard *.asm)
SOURCES=$(wildcard *.c)
ASMOBJECTS=$(ASMSOURCES:.asm=.o)
all: $(MODULE)

$(MODULE): $(SOURCES) $(ASMOBJECTS)
	$(ASM) $(ASMFLAGS) $(ASMSOURCES)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld $(SOURCES) -o ../$(MODULE)


$(ASMOBJECTS) : $(ASMSOURCES)
	
	
%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o

.PHONY: all clean
