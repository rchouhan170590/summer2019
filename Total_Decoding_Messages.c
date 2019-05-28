/*
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
input contain 1-9 digits.
*/
#include<stdio.h>
void total_combi(int n,char str[]);
int to_int(char);
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
    int n;
    scanf("%d",&n);
    char str[n];
    scanf("%s",str);
    //printf("%d\n",total_combi(n,str));
    
     total_combi(n,str);
    }
    return 0;
}

void total_combi(int n,char str[])
{
   if(n<=1)
   {
      printf("Number of way to decode : %d",1);
      return ;
   }
   int temp[n];
   temp[n-1]=1;
   
   int digit1 = to_int(str[n-1]);
   int digit2 = to_int(str[n-2]);
   int num = digit2*10+digit1;
   if(num<=26)
     temp[n-2]=2;
    else
       temp[n-2]=1;
    for(int i=n-3;i>=0;i--)
    {
         int b = 0;
         digit1 = to_int(str[i]);
         digit2 = to_int(str[i+1]);
         num = digit1*10+digit2;
         if(num<=26)
           b = temp[i+2];
         temp[i]= temp[i+1]+b;
    }
    //return temp[0];
    printf("Number of way to decode : %d",temp[0]);
    return ;
}
int to_int(char a)
{
    int x = a -'0';
    return x;
}
