//Given a String of length S, reverse the whole string without reversing 
//the individual words in it. Words are separated by dots.



#include <stdio.h>
#include<string.h>
#define Max 3000
void reverse(char str[]);
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
	 char str[Max];
	 scanf("%s",str);
	 //printf("%s\n",str);
	 reverse(str);
    }
	return 0;
}
void reverse(char str[])
{
    char str2[Max] = "";
    int  end = strlen(str)-1;
    int length  = end;
    char dot = '.';
    int count = 0;
    int i;
    for( i=length;i>=0;i--)
    {
        if(str[i]=='.')
        {
            for(int r=i+1;r<=end;r++)
            {
               str2[count++]=str[r];
               //printf("\n%s",str2[0]);
            }
            str2[count++]=dot;
            end = i -1;
        }
    }
    for(int r=i+1;r<=end;r++)
      str2[count++]=str[r];
    printf("%s\n",str2);
}
