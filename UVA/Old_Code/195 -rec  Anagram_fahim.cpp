#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <ctype.h>
#include <set>
#include <math.h>

#define print(a) cout<< a <<endl
#define print2(a,b) cout<< a <<" "<< b <<endl
#define print3(a,b,c) cout<< a <<" "<< b <<" "<< c <<endl
#define pb push_back
#define popb pop_back
#define mem(name, x) memset(name, x, sizeof(name))
#define MAX 10009000
#define PN 1200000
#define ll long long
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define rep2(i,n) for(i=1; i<=(int)(n); i++)
#define SZ(x) (int)x.size()
#define PI (2*acos(0))
#define FST first
#define SND second
#define PQ priority_queue
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define INFI 1<<30

using namespace std;

char str[100], ans[100];
int n, col[100];

void rec(int cur)
{
    int i;
    if(cur==n)
    {
        for(int j=0; j<n; j++) printf("%c", ans[j]);
        printf("\n");
        return;
    }
    for(i=0; i<n; i++)
    {
        if(!col[i])
        {
            if(i && str[i-1]==str[i] && !col[i-1])continue;
            ans[cur]=str[i];
            col[i]=1;
            rec(cur+1);
            col[i]=0;
        }
    }
}

bool compare(char a, char b)
{
    char x=tolower(a);
    char y=tolower(b);
    if(x==y)return (a<b);
    return (x<y);
}

int main()
{
    int i, j, k, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf(" %[^\n]", str);
        n = strlen(str);
        sort(str, str+n, compare);
        rec(0);
    }
    return 0;
}
















