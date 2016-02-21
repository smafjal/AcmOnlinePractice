#include<stdio.h>
#include<math.h>

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int x1,x2,y1,y2; int M,x,y;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&M);
        printf("Case %d:\n",++cas);
        for(int i=1;i<=M;i++)
        {
            scanf("%d %d",&x,&y);
            if((x>=x1 and x<=x2) and (y>=y1 and y<=y2)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

