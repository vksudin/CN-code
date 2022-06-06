#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<resolv.h>
#include<arpa/inet.h>
#include<string.h>

#define SERVERADDR "127.0.0.1"
#define MYPORT 9898
#define MYBUF 12345
int main(void)
{
	int sockfd, SERVFD, N1;
	struct sockaddr_in SERVD;
	char BUF[MYBUF],stop[MYBUF]="Terminate..";

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*	bzero(&SERVD, sizeof(SERVD));*/

	SERVD.sin_family = AF_INET;
	SERVD.sin_port = htons(MYPORT);
	SERVD.sin_addr.s_addr = inet_addr(SERVERADDR);
	
//	inet_aton(SERVERADDR, (struct in_addr*)&SERVD.sin_addr.s_addr);

	if(connect(sockfd, (struct sockaddr*)&SERVD, sizeof(SERVD))<0)
	{
		printf("connection not established");
		//exit(1);
	}

	while(1)
	{
		printf(">>");
		bzero(BUF, MYBUF);
		fgets(BUF,MYBUF,stdin);	
		N1 = send(sockfd, BUF, sizeof(BUF), 0);
		
		bzero(BUF, MYBUF);
		N1 = recv(sockfd, BUF, sizeof(BUF), 0);
		printf("%s from ip_addr: %s port: %d client side", BUF, inet_ntoa(SERVD.sin_addr), htons(SERVD.sin_port));
		
		if(strncmp(BUF,stop, 4)==0)
			break;
	}
	
	close(sockfd);

	return 0;
}