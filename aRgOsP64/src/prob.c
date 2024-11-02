#include <stdio.h>
#include <unistd.h>

// gcc -fno-stack-protector prob.c -o prob -ldl

void vuln()
{
    char buf[50] = {'\0', };
    
    puts("What should I do? Enter you answer : ");
    fflush(stdout);
    read(0, buf, 256);

}

int main(void) 
{
    printf("[Simple ROP]\n");
    vuln();
}