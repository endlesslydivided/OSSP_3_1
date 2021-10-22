#include <iostream>
#include <ctime>
#include <Windows.h>

#define SECOND 10000000

using namespace std;

int main() {
    clock_t start = clock();

    DWORD pid = GetCurrentProcessId();
    cout << "Main PID: " << pid << endl;

    long long it = -60 * SECOND;
    HANDLE htimer = CreateWaitableTimer(NULL, FALSE, L"OS08_04");
    if (!SetWaitableTimer(htimer, (LARGE_INTEGER*)&it, 60000, NULL, NULL, FALSE)) {
        throw "Error SrtWaitableTimer";
    }

    LPCWSTR an = L"D:\\ALEX\\STUDY\\5SEM_3COURSE\\Операционные системы и системное программирование\\Готовые лабораторные работы\\Lab8\\OS08_04\\Debug\\OS08_04_X.exe";
    PROCESS_INFORMATION pi1, pi2;
    pi1.dwThreadId = 1;  pi2.dwThreadId = 2;

    {
        STARTUPINFO si; ZeroMemory(&si, sizeof(STARTUPINFO)); si.cb = sizeof(STARTUPINFO);
        CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1) ?
            cout << "Process OS08_04xA created \n" : cout << "Process OS08_04xA not created \n";
    }
    {
        STARTUPINFO si; ZeroMemory(&si, sizeof(STARTUPINFO)); si.cb = sizeof(STARTUPINFO);
        CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi2) ?
            cout << "Process OS08_04xB created \n" : cout << "Process OS08_04xB not created \n";
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);  WaitForSingleObject(pi2.hProcess, INFINITE);
    CancelWaitableTimer(htimer);

    cout << "time: " << clock() - start << endl;

    system("pause");
    return 0;
}