SDK_DIR=../../
# Default to something that won't harm the system
DEVICE=/dev/null

AS=scas
LD=scas
CC=kcc

_P=-Wp,-include -Wp,

include $(SDK_DIR)/flags.make

ASFLAGS=-fexplicit-export -fexplicit-import -Iheaders -I$(SDK_DIR)/include
CFLAGS=--nostdinc --nostdlib -Iheaders -I$(SDK_DIR)/include --no-std-crt0 \
	--std-sdcc99 -mz80 $(addprefix $(_P),$(STD_INCLUDES))

SOURCES=$(addprefix src/, hello_world.c)
OBJECTS=$(addprefix bin/,$(addsuffix .o,$(SOURCES)))

bin/src/%.asm.o:src/%.asm $(SDK_DIR)/include
	mkdir $(dir bin/src/%.asm.o) -p
	$(AS) -c $< -o $@ $(ASFLAGS)

bin/src/%.c.o:src/%.c $(SDK_DIR)/include
	mkdir $(dir bin/$<.asm) -p
	$(CC) -S $< -o bin/$<.asm $(CFLAGS)
	$(AS) -c bin/$<.asm -o $@ $(ASFLAGS)

ROM=bin/hello_world.bin
PNG=bin/hello_world.png

$(ROM): $(SDK_DIR)/bin/libc.o $(OBJECTS)
	scas $^ -o $@ $(ASFLAGS)

clean:
	$(RM) $(ROM) $(OBJECTS)

run:
	zenith80 --file $(ROM)

$(PNG): $(ROM)
	cat icon.png $(ROM) > $(PNG)

burn: $(PNG)
	dd if=$(PNG) of=$(DEVICE) status=progress

from_disk:
	zenith80 --file $(DEVICE) --real --wait --format=png
