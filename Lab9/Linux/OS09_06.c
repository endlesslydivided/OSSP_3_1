
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    int number;  
    char *locale = setlocale(LC_ALL, "");
    char c;
    int in = open("./OS09_05.txt",O_RDONLY);
    int out;
    _Bool evenNumber = 0;
    if(argc != 2)
    {
        printf("One number argument is required: odd number - odd rows, even number - even rows\n");
        exit(1);
    }
    number = atoi(argv[1]);
    printf("Params: %d",number);
    if(number % 2 != 0)
    {
        out = open("./OS09_05_01.txt",O_CREAT);
    }
    else 
    {
        evenNumber = 1;
        out = open("./OS09_05_02.txt",O_CREAT);
    }


    while (read(in,&c,1) == 1)
    {
        if(!evenNumber)
        {
            write(out,&c,1);
        }
        if(c == '\n')
        {
            evenNumber = !evenNumber;
        }
    }
    exit(0);
}
