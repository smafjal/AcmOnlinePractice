#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>


using namespace std;

char arr1[10000],arr2[10000];

int main()
{
    int i,j,l,a,k;
    while(gets(arr1))
    {
        gets(arr2);
        k=strlen(arr1);
        l=strlen(arr2);
        vector<char>v;
        for(i=0;i<k;i++)
        {
            for(j=0;j<l;j++)
            {
                if(arr1[i]>='a' && arr1[i]<='z')
                {
                    if(arr1[i]==arr2[j])
                    {
                        v.push_back(arr1[i]);
                        arr2[j]='1';
                        break;
                    }
                }
            }
        }
        sort(v.begin(),v.end());
        for(i=0;i<(int)v.size();i++) printf("%c",v[i]);
        printf("\n");
    }
    return 0;
}
