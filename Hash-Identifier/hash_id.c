#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

    char user_input[128];
    int length;

    puts("Please enter hash: ");
    scanf("%127s", user_input);
    sleep(2);

    length = strlen(user_input);

    if (length == 32) {
        printf("Possible hash: MD5\n");
    } 
    else if (length == 40) {
        printf("Possible hash: SHA-1\n");
    } 
    else if (length == 64) {
        printf("Possible hash: SHA-256\n");
    } 
    else {
        printf("hash-id: invalid hash length: %d\n", length);
    }

    return 0;
}
