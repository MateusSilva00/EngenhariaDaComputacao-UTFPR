// 1. Create a TCP socket using socket().
// 2. Establish a connection to the server using connect().
// 3. Communicate using send and recv().
// 4. Close the connection with close().
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void DieWithUserMessage(const char *msg, const char *detail){
    fputs(msg, stderr);
    fputs(": ", stderr);
    fputs(detail, stderr);
    fputc('\n', stderr);
    exit(1);
}
void DieWithSystemMessage(const char *msg){
    perror(msg);
    exit(1);
}
int  main(int argc, char *argv[]){
    if (argc < 3 || argc > 4) // Teste para numero correto de argumentos
        DieWithUserMessage("Parameter(s)", "<Server Address> <Echo Word [<Server Port>]");

    char *servIP = argv[1];
    char *echoString = argv[2];

    // Default typedef unsigned int 16
    in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0)
        DieWithSystemMessage("socket() failed!");

    // Construindo estrutura do endereço do server
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET; // IPv4 address family
    int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
    if (rtnVal == 0)
        DieWithUserMessage("inet_pton() failed!", "invalid adress string");
    else if (rtnVal < 0)
        DieWithSystemMessage("inet_pton() failed!");
    servAddr.sin_port = htons(servPort);

    // Estabelece conexão com o server
    if (connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        DieWithSystemMessage("connect() failed!");

    size_t echoStringLen = strlen(echoString);

    //Enviar string para o server
    ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
    if (numBytes < 0)
        DieWithSystemMessage("send() failed!");
    else if (numBytes != echoStringLen)
        DieWithUserMessage("send()", "sent unexpected number of bytes!");

    unsigned int totalBytesRcvd = 0;
    fputs("Received: ", stdout);
    while (totalBytesRcvd < echoStringLen)
    {
        char buffer[BUFSIZ]; //Default buffer size
        numBytes = recv(sock, buffer, BUFSIZ - 1, 0);
        if (numBytes < 0)
            DieWithSystemMessage("recv() failed!\n");
        else if (numBytes == 0)
            DieWithUserMessage("recv()", "connection closed prematurly");
        totalBytesRcvd += numBytes;
        buffer[numBytes] = '\0';
        fputs(buffer, stdout);
    }

    fputc('\n', stdout);
    close(sock);
    exit(0);
}
