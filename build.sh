#!/bin/sh

set -e

# 2.3.1 Compiling the Operating System
nasm -f elf32 loader.s
# 2.3.2 Linking the Kernel
ld -T link.ld -melf_i386 loader.o -o kernel.elf

# 2.3.4 Building an ISO Image
mkdir -p iso/boot/grub              # create the folder structure
cp kernel.elf iso/boot/             # copy the kernel
genisoimage -R                              \
            -b boot/grub/stage2_eltorito    \
            -no-emul-boot                   \
            -boot-load-size 4               \
            -A os                           \
            -input-charset utf8             \
            -quiet                          \
            -boot-info-table                \
            -o os.iso                       \
            iso
