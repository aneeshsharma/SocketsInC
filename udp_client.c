#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 6000
#define MAXLINE 1024

int main()
{
    int sock_fd;
    char buffer[MAXLINE];
    char *message = "A message from client";

    struct sockaddr_in server_address;

    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int recv_len, len;

    sendto(sock_fd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&server_address, sizeof(server_address));

    printf("Hello message sent.\n");

    recv_len = recvfrom(sock_fd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&server_address, &len);

    buffer[recv_len] = '\0';

    printf("Message received: %s\n", buffer);

    close(sock_fd);

    return 0;
}