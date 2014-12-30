#include "uefi.h"

#define puts(str)	gST->ConOut->OutputString(gST->ConOut, (str))
#define sleep()		{int i,j; for(i=0; i<10000; i++)for(j=0; j<10000; j++);}

EFI_SYSTEM_TABLE *gST = NULL;
EFI_BOOT_SERVICES *gBS = NULL;

void gethexchar(UINT8 val, CHAR16 *str)
{
	if(0 <= val && val <= 9){
		*str = L'0' + val;
	}
	else{
		*str = L'A' + val - 10;
	}
}

void val2hexstr(UINT8 val, CHAR16 *str)
{
	gethexchar((val >> 4) & 0x0f, &str[0]);
	gethexchar((val & 0x0f), &str[1]);
}

void memdump(UINT8 *p, UINTN len)
{
	CHAR16 Str[16];
	UINTN i,j;

	Str[2] = L'\0';

	i = 0;

	while(i<len){
		for(j=0; j<8 && i<len; j++,i++){
			val2hexstr(p[i], Str);
			puts(Str);
			puts(L" ");
		}
		puts(L"\n");
	}
}

EFI_STATUS
EFIAPI
EfiMain (
    IN EFI_HANDLE        ImageHandle,
    IN EFI_SYSTEM_TABLE  *SystemTable
    )
{
	CHAR16 Str[24] = L"Hello World!\n";
	EFI_INPUT_KEY Key;
	UINTN Index;

	gST = SystemTable;
	gBS = SystemTable->BootServices;

    puts(L"EFI App Start!\n");
	

	while(1){
		SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &Index);
		SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key);

		Str[0] = Key.UnicodeChar;
		Str[1] = L'\n';
		Str[2] = L'\0';

		puts(Str);
	}

	puts(L"Finished\n");

    while(1);
    return EFI_SUCCESS;
}

