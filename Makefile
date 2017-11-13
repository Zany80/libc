AS=scas
CC=kcc
ASFLAGS=-fexplicit-export -fexplicit-import -Iinclude
CFLAGS=--nostdinc --nostdlib -Iinclude --no-std-crt0 --std-sdcc99 -mz80

IO_SOURCES=$(addprefix io/,output.c input.c sprites.c)
MAIN_SOURCES=system.c
FP_SOURCES=$(addprefix fp/,_fsgt.c _fslt.c _fsadd.c _fseq.c _fssub.c)
SOURCES=$(addprefix src/,$(IO_SOURCES) $(MAIN_SOURCES) $(FP_SOURCES))
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm include
	mkdir $(dir bin/src/%.asm.o) -p
	$(AS) -c $< -o $@ $(ASFLAGS)

bin/src/%.c.o:src/%.c include
	mkdir $(dir bin/$<.asm) -p
	$(CC) -S $< -o bin/$<.asm $(CFLAGS)
	$(AS) -c bin/$<.asm -o $@ $(ASFLAGS)

LIB=bin/libc.o

$(LIB): bin/src/crt0.asm.o $(OBJECTS)
	scas -c $^ -o $@ $(ASFLAGS)

clean:
	$(RM) $(LIB) $(OBJECTS)
