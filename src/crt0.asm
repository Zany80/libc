.db "ZENITH"
.dw _title
.dw start

start:
	;//call __initialize_globals
	jp _main

.function __initialize_globals, __initialize_globals, __initialize_globals_end
__initialize_globals:
    ; Note: this could be more optimized if we could toggle auto-relocation in code
    ld hl, __s_initialized_end
    ld bc, __s_initialized
    scf \ ccf
    sbc hl, bc
    ld b, h \ ld c, l
    ld a, b
    or l
    ret z
    ld hl, __s_initializer
    ld de, __s_initialized
    ldir
    ret

__initialize_globals_end:

; Assign some labels to the start of some sections
.area _INITIALIZER
__s_initializer:
.area _INITIALIZED
__s_initialized:
.area _INITIALIZED_END
__s_initialized_end:
