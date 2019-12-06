/* Server Socket, used to send files */

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>


#define PORT 8812
#define LENGTH 512
#define BACKLOG 10

int loop_func(int sockfd) {
    char buf[MAX];
    ssize_t bytes;

    for(;;) {
        memset(buf, 0, MAX);

        std::cout << "Reading from client" << std::endl;
        
        if(read(sockfd, buf, MAX))
    }
}


int main(int argc, char** argv) {

    int sockfd;
    int connfd;

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Error Opening Socket" << strerror(errno) << std::endl;
        return 1;
    }
    
    sockaddr_in client_addr;
    sockaddr_in server_addr;
    memset(client_addr, 0, sizeof(client_addr))

    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(PORT);

    if(bind(fd, (struct sockaddr*)&client_addr, sizeof(struct sockaddr)) < 0) {
        std::cerr << "Failed to bind client addr" << strerror(errno) << std::endl;
        return 1;
    }

    /* Server is ready to listen */
    if(listen(fd, BACKLOG) < 0) {
        std::cerr << "Error, failed to listen to the port" << strerror(errno) << std::endl;
        return 1;
    }

    if((connfd = accept(sockfd, (struct sockaddr*)&client_addr, &len) < 0) {
        std::cerr << "Error, accepting connection" << strerror(errno) << std::endl;
        return 1;
    }

    loop_func();

    close(sockfd);
    return 0;
}


