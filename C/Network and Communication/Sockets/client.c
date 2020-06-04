// Client code in C to sort the array
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// Driver code
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    int server_reply[100];
    int number[100], i, temp;
    int num = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d", &number[i]);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8880);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    if (send(sock, &number, num * sizeof(int), 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    // Receive a reply from the server
    if (recv(sock, &server_reply, num * sizeof(int), 0) < 0)
    {
        puts("recv failed");
        return 0;
    }

    puts("Server reply :\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", server_reply[i]);
    }

    // close the socket
    close(sock);
    return 0;
}