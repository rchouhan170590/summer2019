/* The cost of stock on each day is given in an array A[] of size N. 
   Find all the days on which you buy and sell the stock so that in 
   between those days your profit is maximum.
 */
 
 #include<stdio.h>
void max_profit(int ,int stock[]);
int main()
{
    int t;
    scanf("%d",&t);
    for(int r=0;r<t;r++) {
    int n;
    scanf("%d",&n);
    int stock[n];
    for(int i=0;i<n;i++)
      scanf("%d",&stock[i]);
    max_profit(n,stock);
    printf("\n");
    }
    return 0;
}

void max_profit(int n,int stock[])
{
    int flage=1;
    int prev_value ;
    prev_value = stock[0];
    int take_index = 0;
    int take_value = stock[0];
    for(int i=1;i<n;i++)
    {
        if(stock[i]<prev_value)
        {
            if(take_value!=prev_value)
            {
                printf("(%d %d) ",take_index,i-1);
                flage=0;
            }
            take_index = i;
            take_value = stock[i];
            //printf("\n %d %d",take_value,i);
        }
        prev_value = stock[i];
    }
    if(stock[n-2]<stock[n-1])
    {
      printf("(%d %d) ",take_index,n-1);
      flage = 0;
    }
    if(flage)
       printf("No Profit");
    return ;
}
