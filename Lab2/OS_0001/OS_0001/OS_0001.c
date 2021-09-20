#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	for (int i = 0; i < 1000; i++)
	{
		sleep(2);
		printf("PID: %d-#%d\n", getpid(), i);
	}
	exit(0);
}