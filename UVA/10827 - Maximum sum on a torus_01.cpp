#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
const int INF=(1<<29);
const int MAX=509;

int grid[MAX][MAX],sum[MAX][MAX];
int A[MAX][MAX];
int N;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                cin>>grid[i][j];
                grid[i+N][j]=grid[i][j+N]=grid[i+N][j+N]=grid[i][j];
            }

        for(int i=1;i<=N+N;i++)
        {
            for(int j=1;j<=N+N;j++)
            {
                sum[i][j]=sum[i][j-1]+grid[i][j];
            }
        }

        // horizontal
        int ans=-INF;
        for(int colum1=1;colum1<=N;colum1++)
        {
            for(int colum2=colum1;colum2<=N+colum1-1;colum2++)
            {
                for(int row=1;row<=N;row++)
                {
                    int val=0;
                    for(int row2=row;row2<=row+N-1;row2++)
                    {
                        val+=sum[row2][colum2]-sum[row2][colum1-1];
                        ans=max(ans,val);
                        if(val<0) val=0;
                    }
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}


/**

2
5
1 -1 0 0 -4
2 3 -2 -3 2
4 1 -1 5 0
3 -2 1 -3 2
-3 2 4 1 -4

3
1 2 3
4 5 6
7 8 9

**/
