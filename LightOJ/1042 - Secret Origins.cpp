/**
Bismillahir Rahmanir Rahim
Md.Afjal Hossain(Sm19)
SUST - CSE - 2010.
Date: 3/7/2012
**/

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<string>

#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)x.size()

using namespace std;

string Bit(int n)
{
    string str;
    while(n)
    {
        str+=((n%2)+'0');
        n/=2;
    }
    reverse(all(str));
    return str;
}

int num_decimal(string str)
{
    int len=SZ(str);int dig=0;
    reverse(all(str));
    for(int i=0;i<len;i++)
    {
        if(str[i]=='0') continue;
        dig+=(1<<i);
    }
    return dig;
}

int main()
{
    int ans,n,t,cas=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        string bit_str=Bit(n);
        bit_str='0'+bit_str;

        while(next_permutation(all(bit_str))) {ans=num_decimal(bit_str); if(ans>n)break;}
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
