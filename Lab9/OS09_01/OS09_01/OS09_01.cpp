#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;

BOOL printFileInfo(
    LPWSTR FileName
);

int main()
{
    printFileInfo((LPWSTR)L"D:\\ALEX\\STUDY\\5SEM_3COURSE\\Операционные системы и системное программирование\\Готовые лабораторные работы\\Lab9\\OS09_01.txt");
}

BOOL printFileInfo(LPWSTR FileName)
{
    LPBY_HANDLE_FILE_INFORMATION lpFileInformation = new BY_HANDLE_FILE_INFORMATION();
    DWORD fileType;
    LPSYSTEMTIME systemTimeCreation = new SYSTEMTIME();
    LPSYSTEMTIME systemTimeLastWrite = new SYSTEMTIME();
    setlocale(LC_ALL, "");


    try
    {
        HANDLE of = CreateFile(
            FileName,
            GENERIC_WRITE|GENERIC_READ,
            NULL,
            NULL,
            OPEN_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL);
        if (of == INVALID_HANDLE_VALUE)
        {
            throw "Open file failed";
        }

        wcout << L"--- Open file successfull --- \n";
        wcout << L"--- File info:  --- \n";

        LPWSTR p;
        while (p!= NULL) {
            cout << p << endl;
            p = wcstok(FileName, L"\\");
        }

        printf("File name:%ls \n", p);

        wcout << L"File type: ";

        if (fileType = GetFileType(of))
        {
            switch (fileType)
            {
            case FILE_TYPE_CHAR: cout << "Printe, console file\n"; break;
            case FILE_TYPE_DISK: cout << "Disk file\n"; break;
            case FILE_TYPE_PIPE: cout << "Socket,named pipe, or anonymous pipe\n"; break;
            case FILE_TYPE_REMOTE: cout << "UDEFINED\n"; break;
            case FILE_TYPE_UNKNOWN: cout << "Unknown file type\n"; break;
            }
        }
        else
        {
            throw "GetFileType failed";
        }

        if (GetFileInformationByHandle(of, lpFileInformation))
        {
            cout << "File size: " << lpFileInformation->nFileSizeHigh << "." << lpFileInformation->nFileIndexLow << "\n";
            
            if (FileTimeToSystemTime(&lpFileInformation->ftCreationTime, systemTimeCreation) 
                && FileTimeToSystemTime(&lpFileInformation->ftCreationTime, systemTimeLastWrite))
            {
                printf("Creation time: %u.%u.%u %u:%u:%u \n", systemTimeCreation->wDay, systemTimeCreation->wMonth, systemTimeCreation->wDay, systemTimeCreation->wHour, systemTimeCreation->wMinute, systemTimeCreation->wSecond);
                printf("Last access time: %u.%u.%u %u:%u:%u \n", systemTimeLastWrite->wDay, systemTimeLastWrite->wMonth, systemTimeLastWrite->wDay, systemTimeLastWrite->wHour, systemTimeLastWrite->wMinute, systemTimeLastWrite->wSecond);
            }
            else
            {
                throw "FileTimeToSystemTime failed";
            }

        }
        else
        {
            throw "GetFileInformationByHandle failed";
        }
        CloseHandle(of);
    }
    catch (char* err)
    {
        cout << "--- Error:\n" << err << "\n";
    }
    system("pause");
}