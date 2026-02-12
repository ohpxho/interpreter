	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 1
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x8, #52776558133248             ; =0x300000000000
	movk	x8, #49139, lsl #48
	str	x8, [sp]
Lloh0:
	adrp	x0, l_.str@PAGE
Lloh1:
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	x8, #1073741824                 ; =0x40000000
	movk	x8, #9219, lsl #32
	movk	x8, #16638, lsl #48
	str	x8, [sp]
Lloh2:
	adrp	x0, l_.str.1@PAGE
Lloh3:
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	x8, #39595303501824             ; =0x240300000000
	movk	x8, #16638, lsl #48
	str	x8, [sp]
Lloh4:
	adrp	x0, l_.str.2@PAGE
Lloh5:
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	mov	x8, #2147483648                 ; =0x80000000
	movk	x8, #25165, lsl #32
	movk	x8, #16704, lsl #48
	str	x8, [sp]
Lloh6:
	adrp	x0, l_.str.3@PAGE
Lloh7:
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	mov	x8, #3221225472                 ; =0xc0000000
	movk	x8, #51174, lsl #32
	movk	x8, #16475, lsl #48
	str	x8, [sp]
Lloh8:
	adrp	x0, l_.str.4@PAGE
Lloh9:
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	mov	x8, #1073741824                 ; =0x40000000
	movk	x8, #13107, lsl #32
	movk	x8, #16339, lsl #48
	str	x8, [sp]
Lloh10:
	adrp	x0, l_.str.5@PAGE
Lloh11:
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	mov	w19, #2147483647                ; =0x7fffffff
	str	x19, [sp]
Lloh12:
	adrp	x0, l_.str.6@PAGE
Lloh13:
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	str	x19, [sp]
Lloh14:
	adrp	x0, l_.str.7@PAGE
Lloh15:
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	mov	w19, #-1                        ; =0xffffffff
	str	x19, [sp]
Lloh16:
	adrp	x0, l_.str.8@PAGE
Lloh17:
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	str	x19, [sp]
Lloh18:
	adrp	x0, l_.str.9@PAGE
Lloh19:
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_printf
	mov	w8, #-2                         ; =0xfffffffe
	str	x8, [sp]
Lloh20:
	adrp	x0, l_.str.10@PAGE
Lloh21:
	add	x0, x0, l_.str.10@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	str	x8, [sp]
Lloh22:
	adrp	x0, l_.str.11@PAGE
Lloh23:
	add	x0, x0, l_.str.11@PAGEOFF
	bl	_printf
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.loh AdrpAdd	Lloh22, Lloh23
	.loh AdrpAdd	Lloh20, Lloh21
	.loh AdrpAdd	Lloh18, Lloh19
	.loh AdrpAdd	Lloh16, Lloh17
	.loh AdrpAdd	Lloh14, Lloh15
	.loh AdrpAdd	Lloh12, Lloh13
	.loh AdrpAdd	Lloh10, Lloh11
	.loh AdrpAdd	Lloh8, Lloh9
	.loh AdrpAdd	Lloh6, Lloh7
	.loh AdrpAdd	Lloh4, Lloh5
	.loh AdrpAdd	Lloh2, Lloh3
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"v: %f\n"

l_.str.1:                               ; @.str.1
	.asciz	"w: %f\n"

l_.str.2:                               ; @.str.2
	.asciz	"x: %f\n"

l_.str.3:                               ; @.str.3
	.asciz	"y: %f\n"

l_.str.4:                               ; @.str.4
	.asciz	"z: %f\n"

l_.str.5:                               ; @.str.5
	.asciz	"addf: %f\n"

l_.str.6:                               ; @.str.6
	.asciz	"e: %d\n"

l_.str.7:                               ; @.str.7
	.asciz	"f: %d\n"

l_.str.8:                               ; @.str.8
	.asciz	"b: %u\n"

l_.str.9:                               ; @.str.9
	.asciz	"c: %u\n"

l_.str.10:                              ; @.str.10
	.asciz	"bpc: %u\n"

l_.str.11:                              ; @.str.11
	.asciz	"bmc: %u\n"

.subsections_via_symbols
