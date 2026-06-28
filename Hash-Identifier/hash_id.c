#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char user_input[128];
    int length;

    puts("Please enter hash: ");
    scanf("%127s", user_input);
    
    puts("Identifying...");
    sleep(2);

    length = strlen(user_input);

    if (length == 32) {
        printf("Possible hash: MD5 or MD4\n");
    } 
    else if (length == 40) {
        printf("Possible hash: SHA-1 or MySQL323\n");
    } 
    else if (length == 56) {
        printf("Possible hash: SHA-224\n");
    }
    else if (length == 64) {
        printf("Possible hash: SHA-256 or Cisco-PIX\n");
    } 
    else if (length == 96) {
        printf("Possible hash: SHA-384\n");
    }
    else if (length == 128) {
        printf("Possible hash: SHA-512\n");
    }
    else {
        printf("hash-id: invalid or unrecognized hash length: %d\n", length);
    }

    return 0;
}
