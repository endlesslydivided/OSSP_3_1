#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#define BUF_SIZE 70

int main(int argc, char *argv[])
{
	char buf[BUF_SIZE+1], s[10];
	int sector;
	buf[BUF_SIZE] = '\0'; 
	char* locale = setlocale(LC_ALL, "ru_RU.UTF-8");
	char c[1];
	int in = open("./OS09_05.txt",O_RDONLY);
	int out;

	do 
	{
		printf("Sector number input(<0 -exit): ");
		gets(s);
		sector = atoi(s);
		if(sector < 0)
		{
			break;
		}
		if(sector == 0 && *s != '0') 
		{
			printf("Not a number entered\n");
			continue;
		}

		if(lseek(in, (long)sector*BUF_SIZE,0)==-1L)
		{
			printf("Seek Error\n");
		}	
		if(read(in, buf, BUF_SIZE)==0) 
		{
			printf("Read Error\n");
		}
		else 
		{
			printf("%s\n", buf);
		}
	} while(sector > -1);
    exit(0);
}
