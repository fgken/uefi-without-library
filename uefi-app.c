#include "uefi.h"

#define puts(str)	gST->ConOut->OutputString(gST->ConOut, (str))
#define sleep()		{int i,j; for(i=0; i<10000; i++)for(j=0; j<10000; j++);}

//#include "debug.h"

#define DEFAULT_SERIAL_PORT 0x3f8

static inline unsigned char inb(int port) {
    unsigned char value;
    asm volatile("inb %w1, %b0" : "=a"(value) : "Nd"(port));
    return value;
}

static inline void outb(unsigned char value, int port) {
    asm volatile("outb %b0, %w1" : : "a"(value), "Nd"(port));
}

EFI_SYSTEM_TABLE	*gST = NULL;
EFI_BOOT_SERVICES	*gBS = NULL;

void *entry = NULL;
void *boot_param = NULL;

EFI_STATUS
EFIAPI
EfiMain (
    IN EFI_HANDLE        ImageHandle,
    IN EFI_SYSTEM_TABLE  *SystemTable
    )
{
	EFI_STATUS Status;
	CHAR16 FilePath[] = L"\\\\print.efi"
	UINTN MapKey = 0;
	int i;
	UINTN MemoryMapSize = 0;
	EFI_MEMORY_DESCRIPTOR *MemoryMap = NULL;
	UINTN DescriptorSize;
	UINT32 DescriptorVersion;
	
	gST = SystemTable;
	gBS = SystemTable->BootServices;

    puts(L"EFI App Start!\n");

	return EFI_SUCCESS;

	{
		UINTN NumberOfFileSystemHandles;
		EFI_HANDLE *FileSystemHandles;
		EFI_DEVICE_PATH_PROTOCOL *FileDevicePath = NULL;

		Status = gBS->LocateHandleBuffer(
				ByProtocol,
				&gEfiSimpleFileSystemProtocolGuid,
				NULL,
				&NumberOfFileSystemHandle,
				&FileSystemHandles
				);
		if(Status != EFI_SUCCESS){
			puts("Error: LocateHandleBuffer(SimpleFileSys) Failed\n");
		}

		// Get device path of file from file path
		//FileDevicePath = 

		//Status = gBS->LocateDevicePath, &


	}

	gBS->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey,
			&DescriptorSize, &DescriptorVersion);

	if(MapKey != 0){
		puts(L"MapKey != 0!!\n");
		Status = gBS->ExitBootServices(ImageHandle, MapKey);
		if(Status != EFI_SUCCESS){
			puts("Error: ExitBootServices Failed!\n");
		}
	}

	asm volatile ("mov r28=%1; br.sptk.few %0" :: "b"(entry), "r"(boot_param));

	{
		int port = DEFAULT_SERIAL_PORT;
		outb('A', port);
	}

    while(1);

    return EFI_SUCCESS;
}

