#include<stdio.h>

int f91(int n)
{
    static int i=0;
    i++;
    printf(" i= %d n=%d\n",i,n);

    if(n>=101) return n-10;
    n=f91(f91(n+11));
//    printf(" i= %d n=%d\n",i,n);
    return n;
}
int main()
{
    int i,j, n;
    while(scanf("%d", &n)==1)
    {
        if(!n) break;
        j=f91(n);
        printf("%d\n",j);
    }
    return 0;

}
