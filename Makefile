AS=scas
CC=kcc
ASFLAGS=-fexplicit-export -fexplicit-import -Iinclude
CFLAGS=--nostdinc --nostdlib -Iinclude --no-std-crt0 --std-sdcc99 -mz80

MAIN_SOURCES=system.c
IO_SOURCES=$(addprefix io/,output.c input.c)
SPRITES_SOURCES=$(addprefix sprites/,sprites.c)
FP_SOURCES=$(addprefix fp/,_fsgt.c _fslt.c _fsadd.c _fseq.c _fssub.c)
SDCC_SOURCES=$(addprefix sdcc/,call_hl.c)
SOURCES=$(addprefix src/,$(IO_SOURCES) $(MAIN_SOURCES) $(FP_SOURCES) \
$(SDCC_SOURCES) $(SPRITES_SOURCES)) 
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(basename $(SOURCES))))

bin/src/%.o:src/%.asm include
	mkdir $(dir $@) -p
	$(AS) -c $< -o $@ $(ASFLAGS)

bin/src/%.o:src/%.c include
	mkdir $(dir $@) -p
	$(CC) -S $< -o $(basename $@).asm $(CFLAGS)
	$(AS) -c $(basename $@).asm -o $@ $(ASFLAGS)
#	rm $(basename $@).asm

LIB=bin/libc.o

$(LIB): bin/src/crt0.o $(OBJECTS)
	scas -c $^ -o $@ $(ASFLAGS)

clean:
	$(RM) $(LIB) $(OBJECTS)
