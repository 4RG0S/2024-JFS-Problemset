// gcc -Wall -no-pie -fno-stack-protector even_odd.c -o even_odd

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GOAL 50
#define EVEN 0
#define ODD 1

void init() {
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);
}

void win() {
    system("cat flag");
}

int main() {
    unsigned int round = 0;
    unsigned char round_reward = 0;
    unsigned int total_reward = 0;
    unsigned int even_odd;
    unsigned int random_number;
    
    char input;
    
    init();

    srand(time(NULL));

    do {
        random_number = rand();
        even_odd = random_number % 2;

        do {
            printf("[ROUND %d]\n", round);
            printf("random number generated! even or odd?\n");
            printf("even='e', odd='o': ");
            scanf("%c%*c", &input);
        } while ( input != 'e' && input != 'o' );

        if((input == 'e' && even_odd == EVEN) || (input == 'o' && even_odd == ODD)) {
            round++;
            round_reward = rand() % 10000;
            total_reward += round_reward;

            printf("[+] correct! random number was %d\n", random_number);
            printf("[$] round reward : %d, total reward : %d\n\n", round_reward, total_reward);
        } else {
            printf("[-] incorrct. random number was %d\n\n", random_number);
            return;
        }
    } while ( round < GOAL );

    win();
    return;
}