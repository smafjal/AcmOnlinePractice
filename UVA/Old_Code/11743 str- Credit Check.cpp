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

using namespace std;

int man(int n)
{
    int s=0;
    while(n)
    {
        s+=(n%10);
        n/=10;
    }
    return s;
}

int main()
{
    int i,j,k,loop;
    string s1,s2,s3,s4;
    scanf(" %d",&loop);
    for(k=1;k<=loop;k++)
    {
        cin>>s1>>s2>>s3>>s4;
//        cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
        int sum1=0,sum2=0;
        for(i=0;i<SIZE(s1);i++)
        {
            if(i%2)sum2=sum2+(s1[i]-'0');
            else sum1=sum1+man((s1[i]-'0')*2);
        }
        for(i=0;i<SIZE(s2);i++)
        {
            if(i%2)sum2=sum2+(s2[i]-'0');
            else sum1=sum1+man((s2[i]-'0')*2);
        }
        for(i=0;i<SIZE(s3);i++)
        {
            if(i%2)sum2=sum2+(s3[i]-'0');
            else sum1=sum1+man((s3[i]-'0')*2);
        }
        for(i=0;i<SIZE(s4);i++)
        {
            if(i%2)sum2=sum2+(s4[i]-'0');
            else sum1=sum1+man((s4[i]-'0')*2);
        }
//        printf("%d %d\n",sum1,sum2);
        if(!((sum1+sum2)%10))printf("Valid\n");
        else printf("Invalid\n");
        s1.clear();s2.clear();s3.clear();s4.clear();
    }
    return 0;
}
