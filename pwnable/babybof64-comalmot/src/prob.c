#include <stdio.h>
#include <unistd.h>

// gcc -fno-stack-protector -z execstack prob.c -o prob

void vuln()
{
    char buf[50] = {'\0', };

    printf("buf[50] address: %p\n", buf);

    printf("What should I do? Enter you answer : ");
    fflush(stdout);
    
    read(0, buf, 100);

}

int main(void) 
{
    printf("[No Mitigation]\n");
    vuln();
}