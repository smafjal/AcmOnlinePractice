#include<stdio.h>
#include<math.h>
#include<iostream>
#define PI (2*acos(0.0))

using namespace std;

int main()
{
    int cas=0;int t,n;
    scanf("%d",&t);
    double d1,d2,R,r;

    while(t--)
    {
        cin>>R>>n;
        d1=sin(PI/n);
        d2=1+1/d1;
        double r=R/d2;
        printf("Case %d: %.6lf\n",++cas,r);
    }
    return 0;
}





