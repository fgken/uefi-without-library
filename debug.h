
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


