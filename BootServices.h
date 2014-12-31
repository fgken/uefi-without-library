typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
	IN UINTN		NumberOfEvents,
	IN EFI_EVENT	*Event,
	OUT UINTN		*Index
	);

typedef UINT64	EFI_PHYSICAL_ADDRESS;
typedef UINT64	EFI_VIRTUAL_ADDRESS;
typedef struct {
	UINT32					Type;
	EFI_PHYSICAL_ADDRESS 	PhysicalStart;
	EFI_VIRTUAL_ADDRESS		VirtualStart;
	UINT64					NumberOfPages;
	UINT64					Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MEMORY_MAP) (
	IN OUT UINTN					*MemoryMapSize,
	IN OUT EFI_MEMORY_DESCRIPTOR	*Memorymap,
	OUT UINTN						*MapKey,
	OUT UINTN						*DescriptorSize,
	OUT UINT32						*DescriptorVersion
	);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT_BOOT_SERVICES) (
	IN EFI_HANDLE	ImageHandle,
	IN UINTN		MapKey
	);


typedef struct {
	UINT32	Data1;
	UINT16	Data2;
	UINT16	Data3;
	UINT8	Data4[8];
} EFI_GUID;

typedef enum {
	AllHandles,
	ByRegisterNotify,
	ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER) (
	IN EFI_LOCATE_SEARCH_TYPE	SearchType,
	IN EFI_GUID					*Protocol	OPTIONAL,
	IN VOID						*Searchkey	OPTIONAL,
	IN OUT UINTN				*NoHandles,
	OUT EFI_HANDLE				**Buffer
	);
	

typedef struct {
	EFI_TABLE_HEADER			Hdr;
	char						procs1[8*4];
	EFI_GET_MEMORY_MAP			GetMemoryMap;
	char						procs2[8*4];
	EFI_WAIT_FOR_EVENT			WaitForEvent;
	char						procs3[8*16];
	EFI_EXIT_BOOT_SERVICES		ExitBootServices;
	char						procs4[8*9];
	EFI_LOCATE_HANDLE_BUFFER	LocateHandleBuffer;
	char						procs5[8*7];
} EFI_BOOT_SERVICES;

