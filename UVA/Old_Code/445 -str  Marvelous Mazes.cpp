#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>

#define sz 599
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<"  "<<b<<endl
#define print3(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl


using namespace std;

void print_again(char c,int count)
{
    for(int i=1; i<=count; i++)
    {
        if(c=='b')printf(" ");
        else if(c=='!' || c=='\n')printf("\n");
        else if(c=='*')printf("*");
        else printf("%c",c);
    }
    return;
}

int main()
{
    int i,j,k;
    int count=0;
    char c,w;
    w='#';
    while(scanf("%c",&c)==1)
    {
        if(c=='\n' && w=='\n')
        {
            w='#';
            printf("\n");
            continue;
        }
        if(c=='!' || c=='\n')printf("\n");
        else if(isdigit(c)) count+=(c-'0');
        else
        {
//          print1(count);
            print_again(c,count);
            count=0;
        }
        w=c;
    }
    return 0;
}
