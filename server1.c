#include<stdio.h>
#include<sys/types.h>
#include<resolv.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define SERVADDR "127.0.0.1"
#define MYPORT 9898
#define MYBUF 12345

int main(void)
{
	int sockfd, N, CLIFD, ADDRLEN;
	struct sockaddr_in SD, CLID;
	char buf[MYBUF],stop[MYBUF]="Stop";

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*	bzero(&SD, sizeof(SD));*/
	SD.sin_family = AF_INET;
	SD.sin_port = htons(MYPORT);
	SD.sin_addr.s_addr = inet_addr(SERVADDR);

	if(bind(sockfd, (struct sockaddr*)&SD, sizeof(SD))<0)
	{
		printf("exit..");
		//exit(1);	
	}

	listen(sockfd, 20);

	ADDRLEN = sizeof(CLID);
	CLIFD = accept(sockfd, (struct sockaddr*)&CLID, &ADDRLEN);
	
	while(1)
	{
		bzero(buf,MYBUF);
		N = recv(CLIFD, buf, MYBUF, 0);
		printf("%s from: ip_addr: %s port:%d", buf, inet_ntoa(CLID.sin_addr), htons(CLID.sin_port));
		//bzero(buf,MYBUF);
		if(strncmp("Stop",buf,4)==0)
		{
			strcpy(buf,"Terminated..");
			//bzero(buf,MYBUF);
			N=send(CLIFD,buf,MYBUF,0);
			break;
		}
		
		else
		{
			//bzero(buf,MYBUF);
			strcpy(buf,"Accepted..");	
			N = send(CLIFD, buf, MYBUF, 0);	
		}
		
	}
	printf("\nclosed");
	close(CLIFD);
	close(sockfd);

	return 0;
}