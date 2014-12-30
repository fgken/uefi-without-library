CC = x86_64-w64-mingw32-gcc
CFLAGS = -shared -nostdlib -mno-red-zone -fno-stack-protector -Wall -e EfiMain

all: uefi-app.efi

%.efi: %.dll
	objcopy --target=efi-app-x86_64 $< $@

%.dll: %.c
	$(CC) $(CFLAGS) $< -o $@

setup:
	wget http://sourceforge.net/projects/edk2/files/OVMF/OVMF-X64-r15214.zip
	unzip OVMF-X64-r15214.zip OVMF.fd
	rm OVMF-X64-r15214.zip
	mkdir -p image/EFI/BOOT
	ln -sf ../../../uefi-app.efi image/EFI/BOOT/BOOTX64.EFI

run: uefi-app.efi
	qemu-system-x86_64 -nographic -bios OVMF.fd -hda fat:image

clean:
	rm *.efi
