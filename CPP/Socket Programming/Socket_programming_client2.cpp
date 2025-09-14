#include<iostream>
#include<sys/socket.h> //For Linux


#include<netinet/in.h> //For Linux
#include<arpa/inet.h> //For inet_addr function
#include<unistd.h> //For close function in Linux
#include<string.h> //For memset function
#include<fcntl.h>
#define PORT 8080
struct sockaddr_in srvr_addr;
int main()
{
    int nClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(nClientSocket < 0)
    {
        std::cout<<"CLient Socket failled"<<std::endl;
        exit(EXIT_FAILURE);
    }

    srvr_addr.sin_family = AF_INET; // IPv4
    srvr_addr.sin_port = htons(PORT); // Port number (convert to network byte order)
    //srvr_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    srvr_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Convert IP address from text to binary form
    memset(srvr_addr.sin_zero, '\0', sizeof srvr_addr.sin_zero); // Zero the rest of the struct

    int nRet = connect(nClientSocket,(struct sockaddr*) &srvr_addr, sizeof(srvr_addr));
    if(nRet< 0)
    {
        std::cout<<"Connect Failed"<<std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        char buffer[255] ={0};
        recv(nClientSocket, buffer, 255, 0);
        std::cout<<"Just press any key to see the messgae received from server: "<<std::endl;
        getchar();
        std::cout<<buffer<<std::endl;
    }


}