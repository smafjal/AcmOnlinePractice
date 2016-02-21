#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
const int INF=(1<<29);
const int MAX=109;

int grid[MAX][MAX],sum[MAX][MAX];
int N;

int main()
{
    while(scanf("%d",&N)==1)
    {
        sum[1][0]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d",&grid[i][j]);
                sum[i][j]=sum[i][j-1]+grid[i][j];
            }
        }

        int ans=-INF;
        for(int colum1=1;colum1<=N;colum1++) // select first colume.
        {
            for(int colum2=colum1;colum2<=N;colum2++) // select second colume.
            {
                //khadane 1-D
                int val=0;
                for(int row=1;row<=N;row++)
                {
                    val+=sum[row][colum2]-sum[row][colum1-1];
                    ans=max(ans,val);
                    if(val<0) val=0;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


/*

2
-1 -2
-2 -3

**/
