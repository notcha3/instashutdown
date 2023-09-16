#include "instashutdown.h"

VOID main(VOID)
{
	
	HMODULE hNTDLL = GetModuleHandleA("ntdll.dll");

	PVOID pVoid = NULL;

	RtlAdjustPrivilege = (NTSTATUS*)GetProcAddress(
		hNTDLL,
		"RtlAdjustPrivilege"
	);

	NtShutdownSystem = (NTSTATUS*)GetProcAddress(
		hNTDLL,
		"NtShutdownSystem"
	);


	NTSTATUS uPrivStatus = RtlAdjustPrivilege(
		SE_SHUTDOWN_PRIVILEGE, 
		TRUE, 
		FALSE, 
		&pVoid);

	if(uPrivStatus == STATUS_SUCCESS) {
		NtShutdownSystem(ShutdownPowerOff);
		FreeLibrary(hNTDLL);
	}
	else {
		FreeLibrary(hNTDLL);
		MessageBoxA(NULL,
		"Couldn't get shutdown privilege\0",
		"Error\0",
		MB_OK | MB_ICONERROR);
	}

}
