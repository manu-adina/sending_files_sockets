
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <iostream>


int main(int argc, char** argv) {

    int sockfd;
    int nsockfd;

    struct sockaddr_in client_addr; 
    struct sockaddr_in remote_addr;


    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Error creating a socket" << strerror(errno) << std::endl;
        return 1;
    }

    memset(remote_addr, 0, sizeof(remote_addr));

    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("192.168.0.136".c_str());
    remote_addr.sin_port = htons(8812);

    if(connect(sockfd, (struct sockaddr*)&remote_addr, sizeof(struct sockaddr)) < 0) {
        std::cerr << "Error, failed to connect" << strerror(errno) << std::endl;
        return 1;
    }

    



    return 0;
}
