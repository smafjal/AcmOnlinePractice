#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int i,j,k;
    scanf("%d",&k);
    while(k--)
    {
        vector<char>str;
        char c;
        while(scanf("%c",&c)==1 && c!='\n')str.push_back(c);
        sort(str.begin(),str.end());
        for(i=0;i<(int)str.size();i++)printf("%c",str[i]);
        printf("\n");
        while(next_permutation(str.begin(),str.end()))
        {
            for(i=0;i<str.size();i++)printf("%c",str[i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
