#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 10000; i++) {
        Sleep(200);
        cout << "PID = " << pid << ", TID = " << tid << "\n";     
    }

    return 0;
}

