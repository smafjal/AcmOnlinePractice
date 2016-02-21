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

#define sz 10099
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int main()
{
    int i,j,k,n,loop;
    scanf("%d",&loop);
    scanf("%*c");
    while(loop--)
    {
        string s;
        getline(cin,s);
//        cout<<s<<endl;
        k=SIZE(s);
        double p=sqrt(k);
        if(p!=(int)(p)){cout<<"INVALID"<<endl;continue;}
        n=(int)p;
        char arr[sz];
        k=1;
        for(i=0;i<SIZE(s);i++)
        {
            arr[k]=s[i];
            k++;
        }
        arr[k]='\0';
//        for(i=1;i<k;i++)printf("%c ",arr[i]);
        int man,count;
        for(i=1;i<=n;i++)
        {
            printf("%c",arr[i]);
            count=1;
            man=i;
            while(count<n)
            {
                printf("%c",arr[n*count+i]);
                count++;
            }
        }
        mem(arr,0);
        cout<<endl;
    }
    return 0;
}
