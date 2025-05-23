#include <Windows.h>
#include <iostream>
#include <bitset>

#include "SDKLib/Include/NKIOLIB.h"
#include "SDKLib/Include/NKLCLIB.h"

#include "IO_interface.hpp"

#if defined _WIN64
#pragma comment(lib, "./SDKLib/Lib/x64/NKIOLIBx64.lib")
#pragma comment(lib, "./SDKLib/Lib/x64/NKLCLIBx64.lib")
#else
#pragma comment(lib, "./SDKLib/Lib/x86/NKIOLIBx86.lib")
#pragma comment(lib, "./SDKLib/Lib/x86/NKLCLIBx86.lib")
#endif 

HANDLE xServerThreadHdl = NULL;
DWORD dwServerThreadId;
DWORD WINAPI ServerThread(LPVOID lpParameter); // need to set flag

void originalExample();
void proposedMethod();
void simpleWrite(Output_to_HW outputShort);

int main(void)
{
    int ret = -1;
    char configPath[256] = "PATH-TO-CONFIG-FILE-config.ini";

    // 1. init the library
    ret = NKDIO_LibraryInit((const char *)configPath);
    if (ret != 0)
	{
		printf("DIO Library initialized failed ret:%d\n", ret);
	}
	ret = NKLC_LibraryInit((const char *)configPath);
	if (ret != 0)
	{
		printf("LC Library initialized failed ret:%d\n", ret);
		//return -1;
	}
    else
    {
        // 2: Create the serial communication server thread
		xServerThreadHdl = CreateThread(NULL, 1024, ServerThread, NULL, 0, &dwServerThreadId);
		if (NULL == xServerThreadHdl)
		{
			printf("Create server thread failed\n\r");
		}
		else
        {
            // main action
            originalExample();
            proposedMethod();
        }
    }
}

// need to set flag
DWORD WINAPI ServerThread(LPVOID lpParameter)
{
	for (;;) // it make thread excited after ending the program
	{
		NKLC_Process_Async();
		Sleep(1);
	}
}

// data read and write example
void originalExample()
{
    unsigned char inputBytePort0 = 0;
    unsigned char inputBytePort1 = 0;
    unsigned char outputBytePort0 = 0xFF;
    unsigned char outputBytePort1 = 0;

    // data read
    NKDIO_PollingReadDiByte(0, &inputBytePort0);
    NKDIO_PollingReadDiByte(1, &inputBytePort1);

    // data write
    NKDIO_PollingWriteDoByte(0, outputBytePort0);
    NKDIO_PollingWriteDoByte(1, outputBytePort1);
}

void proposedMethod()
{
    simpleWrite(Y1_HIGH);
    simpleWrite(Y13_HIGH);
}

void simpleWrite(Output_to_HW outputShort)
{
     NKDIO_PollingWriteDoByte(outputShort >> 8, std::bitset<8>(outputBytePort0));
}