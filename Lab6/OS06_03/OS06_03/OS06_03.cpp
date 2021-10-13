#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

using namespace std;

//К CA
//о EE
//в E2 
//страница CA = 202
//смещение EEE = 3822
//адрес = 202 * PG + 3822 = 0x000CAEEE

int main() {
    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }
    cout << endl;

    getchar();

    VirtualFree(xmemaddr, NULL, MEM_RELEASE) ?
        cout << "VirtualFree true\n" : cout << "VirtualFree false\n";

    system("pause");
}

