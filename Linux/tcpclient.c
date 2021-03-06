#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main(int argc, char **argv)
{
	int s, len;
	struct sockaddr_in remote_addr;
	char buf[BUFSIZ];
	memset(&remote_addr, 0, sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	remote_addr.sin_port = htons(8000);
	if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		return 1;
	}
	if(connect(s, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("connect");
		return 1;
	}
	printf("connected to server\n");
	//buf[len] = '\n';
	//puts(buf);
	memset(buf, 0, sizeof(buf));
	while((len = recv(s, buf, BUFSIZ, 0)) > 0)
	{
		printf("Received : %s\n", buf);
		printf("Enter string to send(quit by type quit): ");
		char ch[1007];
		gets(ch);
		//buf[strlen(buf)] = '\0';
		//scanf("%s", buf);
		if(!strcmp(ch, "quit")) break;
		len = send(s, ch, strlen(buf), 0);
		//len = recv(s, buf, BUFSIZ, 0);
		memset(buf, 0, sizeof(buf));
	}
	//close(s);
	return 0;
}
