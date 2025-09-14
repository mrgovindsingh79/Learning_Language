#include<iostream>

//Socket programming
//Socket programming is a way to enable communication between two different processes on the same or 
//different machines. It is a low-level programming interface that allows developers to create networked applications
//using sockets, which are endpoints for sending and receiving data over a network.
//Sockets can be used to implement various network protocols, such as TCP/IP, UDP, and HTTP. They provide a way to establish a connection between two processes, 
//send and receive data, and manage the connection state.
//Socket programming is commonly used in client-server applications, where a client process connects to a server process to request services or resources. 
//The server process listens for incoming connections and responds to client requests.
//Socket programming can be complex and requires a good understanding of networking concepts and protocols. However, it is a powerful tool for building distributed systems and networked applications.
// It is of two types:
//1. Connection-oriented (TCP) Stream Sockets
//2. Connectionless (UDP) Datagram Sockets
//#include<winsock2.h> //For Windows
#include<sys/socket.h> //For Linux


#include<netinet/in.h> //For Linux
#include<arpa/inet.h> //For inet_addr function
#include<unistd.h> //For close function in Linux
#include<string.h> //For memset function
#include<fcntl.h>

struct sockaddr_in srvr_addr; //Structure to hold server address information
//sockaddr_in is a structure that contains an internet address. It is used with IPv4
//AF_INET - Address family for IPv4
//sin_port - Port number
//sin_addr - IP address 

#define PORT 8080
int maxFD;
int sockfd;
fd_set fw, fr, fe;
int nArrCLient[5];
void ProcessNewRequest()
{
    if(FD_ISSET(sockfd, &fr))
    {
        socklen_t addrLen = sizeof(struct sockaddr_in);
        int nClientSocket = accept(sockfd,NULL,&addrLen);
        //To communicate with the Client we need to use nClientSocket address.
        if(nClientSocket > 0)
        {
            //Put into the client fd_set. Since we acepted the client now we can give response to this client. 
            //So that the client can send another request to fullfill.
            int ind;
            for(ind = 0; ind<5; ind++)
            {
                if(nArrCLient[ind] == 0)
                {
                    nArrCLient[ind] = nClientSocket;
                    send(nClientSocket,"Got the connection Successfull",31,0);
                    break;
                }
            }
            if(ind == 5)
            {
                std::cout<<"No Space for new connection"<<std::endl;
            }

        }
    }
}
int main()
{
    //For windows
    //WSADATA wsaData;
    //int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    //if (iResult != 0) {
    //    std::cerr << "WSAStartup failed: " << iResult << "\n";
    //    return 1;
    //}
    int nRet = 0;

    //1.
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
    //AF_INET - Address family for IPv4
    //SOCK_STREAM - Type of socket (stream socket for TCP)
    //0 - Protocol (0 means default protocol for the given address family and socket type)

    
    //We can put some x number of socket in each fd_set

    if (sockfd == -1)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }
    //2. Initialize and configure socket options here (not shown)

    srvr_addr.sin_family = AF_INET; // IPv4
    srvr_addr.sin_port = htons(PORT); // Port number (convert to network byte order)
    //srvr_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    srvr_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Convert IP address from text to binary form
    memset(srvr_addr.sin_zero, '\0', sizeof srvr_addr.sin_zero); // Zero the rest of the struct


    //Before binding the socket we will set the type for the socket as blocking or non-blocking socket.
    //ByDefault every socket is blocking socket

    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl get");
        exit(EXIT_FAILURE);
    }

    // Clear the O_NONBLOCK flag if it’s set
    //flags &= ~O_NONBLOCK;
    //if (fcntl(sockfd, F_SETFL, flags) == -1) {
    //    perror("fcntl set");
    //    exit(EXIT_FAILURE);
    //}

    std::cout << "Socket is set to BLOCKING mode" << std::endl;
    
    //Before Binding the we provide set socket options.
    //setsockopt() in Linux (and Unix) is that it gives you control over the behavior of your socket 
    //beyond the defaults chosen by the kernel. We can tune performance, reliability, and behavior for your application’s needs.
    //Avoiding “Address already in use” (SO_REUSEADDR)
    //Load balancing with multiple processes (SO_REUSEPORT): multiple process/threads can bind to same port.
    //and so on
    int nOptVal = 0;
    int nOptLen = sizeof(nOptVal);
    int ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*) &nOptVal, nOptLen); //use same address for multple process
    if(ret == 0)
    {
        std::cout<<"Set Socket Successfull"<<std::endl;
    }
    else
    {
        std::cout<<"Set Socket UnSuccessfull"<<std::endl;
        exit(EXIT_FAILURE);
    }
    //3. Bind the Socket
    nRet = bind(sockfd,(sockaddr*)&srvr_addr, sizeof(srvr_addr));

    if(nRet < 0)
    {
        std::cout<<"Failed to bind the Local port "<<std::endl;
    }
    else
    {
        std::cout<<"Local port bind success"<<nRet<<std::endl;
    }
    std::cout << "Socket created successfully with file descriptor: " << sockfd << "\n";
    // Remember to close the socket when done (not shown here)

    //4. Listen the request from the Socket
    nRet = listen(sockfd, 5); //5 as arg how many req can a server can pull at a time from active queue.
    if (nRet <0)
    {
        std::cout<<"Failed to listen fomr local port "<<std::endl;
    }
    else
    {
        std::cout<<"Started to listen fomr local port "<<std::endl;
    }

    //5. Wait for connections

    int n = 100;
    for(int i=0;i<64;i++)
    {
        FD_SET(n,&fr);
        n++;
    }
    int cnt=0;
    for(int j=0;j<n;j++)
    {
        //std::cout<<"fd: "<<FD_ISSET(j,&fr)<<std::endl;
        if(FD_ISSET(j, &fr))
        {//std::cout<<"fd: "<<j<<std::endl;
        cnt++;}
    }
    std::cout<<"Count: "<<cnt<<std::endl;

    //Select is system call used to monitor multiple file descriptors to see if they are reasdy for I/O operations
    //such as read/write or error exception. It helps us to wait on multiple sockets or file descriptor at once
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    maxFD = sockfd;

    while(1)
    {
        //Clear the file descriptor
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);

        FD_SET(sockfd, &fr);
        FD_SET(sockfd, &fe);
        

        nRet = select(maxFD+1, &fr, &fw, &fe, &tv);
        if(nRet > 0)
        {
            //Some connects or communicate with some message over a dedicated connection
            std::cout<<"Data on port............. Listening Now"<<std::endl;
            //if (FD_ISSET(sockfd, &fe))
            //{
            //    std::cout<<"There is exception..... Get away from here now...."<<std::endl;
            //}
            //if(FD_ISSET(sockfd, &fr))
            //{
            //    std::cout<<"Ready to read......... Something new came up to read??"<<std::endl;
            //}
            //if(FD_ISSET(sockfd, &fw))
            //{
            //    std::cout<<"Ready to write Something "<<std::endl;
            //}
            ProcessNewRequest();
            std::cout<<"Success"<<std::endl;
        }
        else if (nRet == 0)
        {
            //No connection or any communication made
            //None of the socket decriptor is ready
            std::cout<<"Nothing on Port: "<<PORT<<std::endl;
        }
        else
        {
            //It failed and you your app should show some usefull message
            std::cout<<"I failed "<<std::endl;
            //WSACleanup();  for windows, nothing in linux
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }
    close(sockfd);

    return 0;
}
