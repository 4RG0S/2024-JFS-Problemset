#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

// gcc -fno-stack-protector prob.c -o prob

void vuln()
{
    char buf[50] = {'\0', };

    printf("printf addr: %p\n", dlsym(dlopen("libc.so.6", RTLD_LAZY), "printf"));
    
    printf("What should I do? Enter you answer : ");
    fflush(stdout);
    
    read(0, buf, 256);
    
    printf("Congrats!\n");
    
}

int main(void) 
{
    printf("[Simple RTL]\n");
    vuln();
}