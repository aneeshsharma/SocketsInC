#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 5000

int main()
{
    int sock = 0, recv_len;
    struct sockaddr_in server_address;
    char message[256];
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error creating socket!!\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        printf("Invalid address\\Address not supported\n");
        return -1;
    }

    printf("Enter message - ");
    scanf("%[^\n]s", message);

    printf("Connecting...\n");

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Connection failed!\n");
        return -1;
    }

    send(sock, message, strlen(message), 0);
    printf("Client Message sent!\n");
    recv_len = read(sock, buffer, 1024);
    printf("Message received - %s\n", buffer);
    return 0;
}