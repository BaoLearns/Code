/*************************************************************************
    > File Name: tcpserver.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: Mon Sep 14 15:22:06 2015
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int s, fd, len;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	int sin_size;
	char buf[BUFSIZ];
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_port = htons(8000);

	if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		return 0;
	}

	if(bind(s, (struct scokaddr *)&my_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("bind");
		return 0;
	}
	
	listen(s, 5);
	sin_size = sizeof(struct sockaddr_in);
	int flag = 1;
	while(flag)
	{
		if((fd = accept(s, (struct sockaddr *)&remote_addr, &sin_size)) < 0)
		{
			perror("accept");
			return 1;
		}

		printf("accepted client %s\n", inet_ntoa(remote_addr.sin_addr));
		len = send(fd, "Welcome to my server\n", 21, 0);
		memset(buf, 0, sizeof(buf));
		while(flag && (len = recv(fd, buf, BUFSIZ, 0)) > 0)
		{
			//buf[len] = '\0';
			printf("Received :%s\n", buf);
			char ch[1006];
			printf("Enter string to send(quit by type quit): " );
			gets(ch);
			ch[strlen(ch)] = '\n';
			if(!strcmp(ch, "quit"))
			{
				flag = 0;
				memset(buf, 0, sizeof(buf));
			}
			if(send(fd, ch, strlen(ch), 0) < 0)
			{
				perror("write");
				return 0;
			}
			memset(buf, 0, sizeof(buf));
		}
	}
	close(fd);
	close(s);
	return 0;
}

