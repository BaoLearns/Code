/*************************************************************************
    > File Name: udpserver.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月15日 星期二 19时53分24秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
	struct sockaddr_in my_addr, remote_addr;
	memset(&my_addr, 0, sizeof( my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_port = htons(8000);
	int s, fd, len;
	char buf[BUFSIZ];
	
	if((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket");
		return 1;
	}

	if(bind(s, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("bind");
		return 1;
	}
	int sin_size = sizeof(struct sockaddr_in);
	printf("waiting for a packet...\n");

	if((len = recvfrom(s, buf, BUFSIZ, 0, (struct sockaddr*)&remote_addr, &sin_size)) < 0)
	{
		perror("recvfrom");
		return 1;
	}

	printf("received packet from %s:\n" ,inet_ntoa(remote_addr.sin_addr));
	buf[len] = '\0';
	printf("contents :%s\n",  buf);
	close(s);
	return 0;
}

