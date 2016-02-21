#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
string s;

bool rec(int i,int j)
{
    if(i>j) return 1;
    if(s[i]==s[j]) rec(i+1,j-1);
    else return 0;
}

int main()
{
    int i,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        if(s.size()==1) {printf("Case %d: Yes\n",++cas);continue;}
        bool l=rec(0,s.size()-1);
        if(l) printf("Case %d: Yes\n",++cas);
        else printf("Case %d: No\n",++cas);
    }
    return 0;
}
