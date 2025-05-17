#include <stdio.h>
#include <string.h>

unsigned char encoded_flag[] = { 0x3D, 0x31, 0x24, 0x0C, 0x16, 0x19, 0x03, 0x56, 0x28, 0x02, 0x4E, 0x0F, 0x28, 0x02, 0x19, 0x4E, 0x16, 0x14, 0x1C, 0x56, 0x19, 0x10, 0x37, 0x37, 0x0A };

int main(int argc, char* argv[]) {
    int encoded_length = sizeof(encoded_flag) / sizeof(encoded_flag[0]);

    if (argc != 2 || strlen(argv[1]) != encoded_length) {
        printf("no hack\n");
        return 1;
    }

    for (int i = 0; i < encoded_length; i++) {
        unsigned char xor_result = argv[1][i] ^ 0x77;
        if (xor_result != encoded_flag[i]) {
            printf("no hack\n");
            return 1;
        }
    }

    printf("correct!\n");
    return 0;
}