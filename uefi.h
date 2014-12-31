#define IN
#define OUT
#define OPTIONAL
#define EFIAPI

#define EFI_SUCCESS		0
#define EFI_NOT_READY	6

#define NULL			0

typedef void				VOID;
typedef unsigned char		UINT8;
typedef unsigned short		CHAR16;
typedef unsigned short		UINT16;
typedef int					INT32;
typedef unsigned int		UINT32;
typedef unsigned long long	UINT64;
typedef unsigned long long	UINTN;
typedef unsigned char		BOOLEAN;

typedef unsigned long long EFI_STATUS;
typedef void *EFI_HANDLE;
typedef VOID *EFI_EVENT;

typedef struct {
	UINT64	Signature;
	UINT32	Revision;
	UINT32	HeaderSize;
	UINT32	CRC32;
	UINT32	Reserved;
} EFI_TABLE_HEADER;

#include "BootServices.h"

#include "SimpleTextOutputProtocol.h"
#include "SimpleTextInputProtocol.h"

// ================================
// EFI SYSTEM TABLE
// ================================
typedef struct {
	EFI_TABLE_HEADER				Hdr;
	CHAR16							*FirmwareVendor;
	UINT32							FirmwareRevision;

	EFI_HANDLE						ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL	*ConIn;
	EFI_HANDLE						ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL	*ConOut;

	char							padding[16+8];

	EFI_BOOT_SERVICES				*BootServices;

	/* ... */
} EFI_SYSTEM_TABLE;


extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;

