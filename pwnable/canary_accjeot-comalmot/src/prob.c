#include <stdio.h>
#include <unistd.h>

// gcc -fstack-protector -z execstack prob.c -o prob

void vuln()
{
    char buf[50] = {'\0', };

    printf("buf[50] address: %p\n", buf);

    printf("What should I do? Enter you answer : ");
    fflush(stdout);
    
    read(0, buf, 100);

    printf("It's your answer! right? : %s\n", buf);
    fflush(stdout);

    printf("Once Again! : ");
    fflush(stdout);

    read(0, buf, 100);

}

int main(void) 
{
    printf("[Canary]\n");
    vuln();
}