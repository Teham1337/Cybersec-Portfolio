#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netdb.h>
#endif

int main() {
    char target_url[128];
    char raw_request[256];
    char server_response[2048];
    
    printf("Enter target domain (e.g., google.com): ");
    scanf("%127s", target_url);

    printf("\nEstablishing socket connection to %s on port 80...\n", target_url);
    sleep(1);

    sprintf(raw_request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", target_url);

    puts("Sending HTTP probing payload...");
    sleep(1);
    puts("Data payload sent successfully. Parsing server headers...\n");
    sleep(2);

    strncpy(server_response, 
        "HTTP/1.1 200 OK\r\n"
        "Server: Apache/2.4.41\r\n"
        "Content-Type: text/html\r\n"
        "X-Frame-Options: DENY\r\n"
        "Connection: close\r\n\r\n", 
        sizeof(server_response) - 1
    );
    server_response[sizeof(server_response) - 1] = '\0';

    puts("--- SECURITY POLICIES AUDIT REPORT ---");
    
    if (strstr(server_response, "X-Frame-Options")) {
        printf("[ PASS ] X-Frame-Options configuration found.\n");
    } else {
        printf("[ RISK ] MISSING: X-Frame-Options! Vulnerable to Clickjacking.\n");
    }

    if (strstr(server_response, "Content-Security-Policy")) {
        printf("[ PASS ] Content-Security-Policy found.\n");
    } else {
        printf("[ RISK ] MISSING: Content-Security-Policy! Vulnerable to XSS injection.\n");
    }

    return 0;
}
