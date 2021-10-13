#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	
	for (int i = 0; i < 100; i++) {
		sleep(2);
		printf("OS03_06 PID: %d-#%d\n", getpid(), i);
		if(i == 3)
		{
			system("./OS03_05_1");
		}
	}

	exit(0);
}