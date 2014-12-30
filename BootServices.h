typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
	IN UINTN		NumberOfEvents,
	IN EFI_EVENT	*Event,
	OUT UINTN		*Index
	);

typedef struct {
	EFI_TABLE_HEADER	Hdr;
	char				procs[8*9];
	EFI_WAIT_FOR_EVENT	WaitForEvent;
	/* ... */
} EFI_BOOT_SERVICES;

