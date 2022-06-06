/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
int sender(char *X, char *Hamm, int l, int par){
    int pos=1, p=0, i=1;
    for(;;i++){
        if(pos==i){
            Hamm[i]='Z';
            pos=pos<<1;
        }
        else
        Hamm[i]=X[p++];
        if(p==l)break;
    }
    pos=1;
    while(pos<=i){
        int ctr=0;
        for(int j=pos+1;j<=i;j++)
        if((j&pos)==pos && Hamm[j]!='Z')
        ctr+=Hamm[j];
        Hamm[pos]=(ctr+par)%2+48;
        pos=pos<<1;
    }
    printf("The generated code is: ");
    for(int j=i;j>=1;j--)
    printf("%c",Hamm[j]);
    return i;
}

void medium(char *X, int l){
    printf("\nDo u want any error in medium?(1/0): ");
    int x;
    scanf("%d",&x);
    if(x==0)return;
    while(1){
        int p=0;
        printf("Enter a position  to add error(enter invalid position to exit):");
        scanf("%d",&p);
        if(p<0 || p>=l){
            printf("error provided..\nthe new data is: ");
            for(int i=1;i<=l;i++)
            printf("%c",X[i]);
            return;
        }
        X[p]=(X[p]+1)%2+48;
    }
}
void receiver(char *Hamm, int l, int par, int remlen){
    int check[remlen];
    int pos=1,p=0,flag=1;
    while(pos<=l){
        int ctr=0;
        for(int i=pos;i<=l;i++)
            if((i&pos)==pos)
            ctr+=Hamm[i]-48;
        check[p]=(ctr+par)%2;
        if(check[p++]==1)flag=0;
        pos=pos<<1;
    }
    int val=0;
    printf("\nThe generated parity is: ");
    for(int i=remlen-1;i>=0;i--){
        printf("%d",check[i]);
        val+=check[i]*pow(2,i);
    }
    
    if(flag==1){
    printf("\nThe data is received correctly."); return;}
    else
    printf("\nThe data is received incorrectly.\nfor one bit error th eposition of problem is: %d",val);
}

int main()
{
    char X[1000];
    int l=0;
    printf("Enter the dataword: ");
    for(;;l++){
        scanf("%c",&l[X]);
        if(l[X]=='\n')break;
    }
    printf("Enter the type of parity:\n\t1.Even parity\n\t2.Odd parity.\n\t Enter choice: ");
    int par;
    scanf("%d",&par);
    char Hamm[1000];    
    int hl=sender(X, Hamm, l, --par);
    medium(Hamm, hl);
    receiver(Hamm, hl, par, hl-l);
    return 0;
}
