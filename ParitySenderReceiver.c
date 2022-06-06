#include<stdio.h>
void compare(char parity[])
{
	char cmp[100];
	int i=0;
	while(parity[i]!='\0')
	{
		cmp[i]=parity[i];
		i++;
	}
	if(parity[i-1]=='0')
	{
		cmp[i-1]='1';
	}
	else
	{
		cmp[i-1]='0';
	}	
	cmp[i]='\0';
	printf("Erroneous result: %s\nRejected\n",cmp);
}
void evenReceiver(char parity[])
{
	int user;
	printf("Code: %s\n",parity);
	printf("Even Parity receiver\nEnter 1 to get errorless result\nEnter 0 to get erroneous result\n");
	scanf("%d",&user);
		if(user==1){
			printf("Errorless result: %s\nAccepted\n",parity);}
		else{
			compare(parity);}
}
void oddReceiver(char parity[])
{
	int user;
	char cmp[100];
	printf("Code: %s\n",parity);
	printf("Odd Parity receiver\nEnter 1 to get errorless result\nEnter 0 to get erroneous result\n");
	scanf("%d",&user);
		if(user==1)
			printf("Errorless result: %s\nAccepted\n",parity);
		else
			compare(parity);
}

int main()
{
	int number,num,arr[100],user;
	char data[100],parityOdd[100],parityEven[100];
	int i=0,countOdd=0,j=0;
	printf("Enter the number\n");
	scanf("%d",&number);
	num=number;
	while(num>0)
	{
		arr[i]=num%2;
		num=num/2;
		i++;
	}
	while(i>0)
	{
		data[j++]=(char)arr[--i]+48;
	}
	data[j]='\0';
	i=0;
	while(data[i]!='\0')
	{
		parityOdd[i]=data[i];
		parityEven[i]=data[i];
	     if(data[i]=='1')
		  countOdd++;
		 i++;
	}
	if(countOdd%2==1){
		parityOdd[i]='0';parityOdd[i+1]='\0';
    }
	else {
		parityOdd[i]='1';parityOdd[i+1]='\0';
	}
	if(countOdd%2==0){
		parityEven[i]='0';parityEven[i+1]='\0';
	}
	else {
		parityEven[i]='1';parityEven[i+1]='\0';
	}
	printf("Even Parity: %s\n",parityEven);
	printf("Odd Parity: %s\n",parityOdd);
	printf("Parity receiver\nEnter 1 to receive Odd parity\nEnter 0 to receive Even parity\n");
	scanf("%d",&user);
	if(user==1)
	{
		oddReceiver(parityOdd);
	}
	else{
		evenReceiver(parityEven);
	}

}
