global loader


MAGIC_NUMBER        equ 0x1BADB002
FLAGS               equ 0x0
CHECKSUM            equ -MAGIC_NUMBER

KERNEL_STACK_SIZE   equ 4096



section .text:
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM

loader:
    extern kernel_main
    mov esp, kernel_stack + KERNEL_STACK_SIZE

    call kernel_main

.loop:
    jmp .loop

section .bss
align 4
kernel_stack:
    resb KERNEL_STACK_SIZE

