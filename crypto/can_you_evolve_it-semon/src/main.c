//gcc main.c -o main -lssl -lcrypto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/aes.h>

void initialize() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void string_to_hex(const unsigned char *input, char *output) {
    while (*input) {
        sprintf(output, "%02x", *input);
        output += 2;
        input++;
    }
}

void aes_ecb_encrypt(const unsigned char *key, const unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);

    int len = strlen((const char *)plaintext);
    for (int i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_ecb_encrypt(plaintext + i, ciphertext + i, &encryptKey, AES_ENCRYPT);
    }
}

void aes_ecb_decrypt(const unsigned char *key, const unsigned char *ciphertext, unsigned char *plaintext) {
    AES_KEY decryptKey;
    AES_set_decrypt_key(key, 128, &decryptKey);

    int len = strlen((const char *)ciphertext);
    for (int i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_ecb_encrypt(ciphertext + i, plaintext + i, &decryptKey, AES_DECRYPT);
    }
}

void getFlag() {
    
    FILE* file = fopen("./flag.txt", "rb");

    unsigned char buffer[40] = {0};
    size_t bytesRead;

    if((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        printf("FLAG : %s", buffer);
    } else {
	printf("File read error!!\n");
    }
    printf("\n");
}

int main() {

	const unsigned char* key = "4RG0S_Pass_K3Y!!";
	unsigned char encrypt_pwd[128] = {0};
	unsigned char* admin_pwd = "50c14d3ad61c89d391eb6f79e559eea0";
	unsigned char decryptedtext[128] = {0};
	char* id_list[4] = {"argos", "guest", "chacha", "admin"};
	char id[20];
	unsigned char password[30] = {0};
	unsigned char hex_pwd[60] = {0};
	unsigned char hex_test[60] = {0};
	unsigned char test[128] = {0};

	int i, j;
	int available_id = -1;
	
	initialize();

	digivice();
	
	printf("Login Digivice!!\n");
	
	printf("[ >] ID : ");
	scanf("%s", id);

	printf("[ >] PW : ");
	scanf("%s", password);

	for(i=0; i < 4; i++) {

		if (strlen(id_list[i]) != strlen(id)) {
			continue;
		}
		
		if ( !strcmp(id_list[i], id) ) {
			available_id = i;
			break;
		}

	}
	if (available_id != -1) {
		if (available_id == 3) {
			aes_ecb_encrypt(key, password, encrypt_pwd);

			string_to_hex(encrypt_pwd, hex_pwd);
			string_to_hex(test, hex_test);
			for( i=0; i < strlen(admin_pwd); i++ ) {
				if (hex_pwd[i] != admin_pwd[i]) {

					evolution();
					fail();
				}
			}
			printf("Login Success!! Please wait.");
			fflush(stdout);
			usleep(1000000);
			printf("\rLogin Success!! Please wait..");
			fflush(stdout);
			usleep(1000000);
			printf("\rLogin Success!! Please wait...");
			fflush(stdout);
			usleep(1000000);
			evolution();
			flag();
			getFlag();
		}
		else{
			evolution();
			fail();
			printf("Hello, %s\n", id_list[available_id]);
		}
	} else {
		printf("ID not in list. Please try again..\n");
	}

	return 0;
}
