/*************************************************************************
    > File Name: udpclient.c
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月15日 星期二 20时17分00秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main()
{
	int s, len;
	struct sockaddr_in remote_addr;
	char buf[BUFSIZ];
	memset(&remote_addr, 0, sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	remote_addr.sin_port = htons(8000);

	if((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket");
		return 1;
	}
	
	strcpy(buf, "This is a test message");
	printf("sending : '%s'\n", buf);

	if((len = sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)))< 0)
	{
		perror("sendto");
		return 1;
	}
	close(s);
	return 0;
}

