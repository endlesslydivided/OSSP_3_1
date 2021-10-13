#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define KB (1024)
#define IC 256

int main() {
	pid_t pid = getpid();
	printf("OS06_06 PID %d\n", pid);
	
	int countItems = IC / sizeof(int);

	int* mem1 = malloc(1024 * 256);
	printf("mem1(1024*256) = %p\n", mem1);
    for (int i = 0; i<countItems; i++) 
    {
      mem1[i] = i;
    }
	
	sleep(60 * 60 * 60);
	
	exit(0);
}