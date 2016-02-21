#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int data[4];
        for(int i=0;i<3;i++) scanf("%d",&data[i]);
        sort(&data[0],&data[3]);

        if((((data[0]*data[0])+(data[1]*data[1]))==(data[2]*data[2]))) printf("Case %d: yes\n",++cas);
        else printf("Case %d: no\n",++cas);
    }
    return 0;
}
