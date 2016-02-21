#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#define sz 100000

using namespace std;

vector<char>v;
int man=0;

void mw(char c,char arr1[])
{
    int i,j;
    if(arr1[man]==c)
    {
        v.push_back(c);
        man++;
    }
    return;
}

int worke(char arr1[],char arr2[])
{
    int i,j,k;
    int l1=strlen(arr1);
    int l2=strlen(arr2);
    if(l1>l2)return 0;
    for(i=0;i<l2;i++)
    {
        mw(arr2[i],arr1);
    }
    int l=(int)v.size();
    if(l!=l1)return 0;
    k=1;
    for(i=0;i<l;i++)
    {
        if(v[i]!=arr1[i])
        {
            k=0;
            break;
        }
    }
    return k;
}

int main(void)
{
    int k;
    char arr1[sz],arr2[sz];
    while(scanf(" %s %s",arr1,arr2)==2)
    {
        k=worke(arr1,arr2);
        if(k)printf("Yes\n");
        else printf("No\n");
        v.clear();
        man=0;
    }
    return 0;
}
