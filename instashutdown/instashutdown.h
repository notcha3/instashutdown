#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winternl.h>
#include <ntstatus.h>

// thanks to reactos sources and https://undocumented.ntinternals.click for the function prototypes

#define SE_SHUTDOWN_PRIVILEGE 19

NTSTATUS (NTAPI *RtlAdjustPrivilege) (
    _In_ INT    Privilege,
	_In_ BOOLEAN  Enable,
	_In_ BOOLEAN  CurrentThread,
	_In_ PBOOLEAN Enabled
);

typedef enum SHUTDOWN_ACTION {
    ShutdownNoReboot,
    ShutdownReboot,
    ShutdownPowerOff
} SHUTDOWN_ACTION, *PSHUTDOWN_ACTION;

NTSTATUS (NTAPI *NtShutdownSystem) (
  _In_ SHUTDOWN_ACTION Action 
  );