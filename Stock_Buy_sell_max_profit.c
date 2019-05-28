/* The cost of stock on each day is given in an array A[] of size N. 
   Find all the days on which you buy and sell the stock so that in 
   between those days your profit is maximum.
   
 */
 
 #include<stdio.h>
int max_profit(int ,int stock[],int,int ,int);
int max(int ,int);
int main()
{
    int n;
    scanf("%d",&n);
    int stock[n];
    for(int i=0;i<n;i++)
      scanf("%d",&stock[i]);
    printf("max profit gain : %d",max_profit(n,stock,0,0,1));
    return 0;
}

int max_profit(int n,int stock[],int run,int take_val,int flage)
{
    if(run>=n)
      return 0;
    else
    {
        if(flage==1)
        {
            return max(max_profit(n,stock,run+1,stock[run],0),max_profit(n,stock,run+1,take_val,flage));
        }
        else
        {
          return max((stock[run]-take_val)+max_profit(n,stock,run+1,0,1),max_profit(n,stock,run+1,take_val,flage));
        }
    }
}
int max(int a,int b)
{
    return (a>b?a:b);
}
