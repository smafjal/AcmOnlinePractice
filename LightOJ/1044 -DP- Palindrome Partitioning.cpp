/// Bismillahir Rahmanir Rahim.
/*******

A palindrome partition is the partitioning of a string such that each separate substring is a palindrome.

For example, the string "ABACABA" could be partitioned in several different ways, such as {"A","B","A","C","A","B","A"}, {"A","BACAB","A"}, {"ABA","C","ABA"}, or {"ABACABA"}, among others.

You are given a string s. Return the minimum possible number of substrings in a palindrome partition of s.

Input
Input starts with an integer T (≤ 40), denoting the number of test cases.

Each case begins with a non-empty string s of uppercase letters with length no more than 1000.

Output
For each case of input you have to print the case number and the desired result.

*****/
#include <stdio.h>
#include <string.h>
#define MAX 1001
#define oo (1<<30)
#define mem(a,b) memset(a,b,sizeof(a))

int min(int a,int b) {return a>b?b:a;}

int dp[MAX],L,palim[MAX][MAX];
char str[MAX];

int palimdrome(int i,int j)
{
    if(i>j) return 1;
    int &ret=palim[i][j];
    if(ret!=-1) return palim[i][j];
    if(str[i]==str[j]) return ret=palimdrome(i+1,j-1);
    else return ret=0;
}

int rec(int cur)
{
    if(cur==L) return 0;
    int &ret=dp[cur];
    if(ret!=-1) return ret;
    int mn=oo;
    for(int i=cur;i<L;i++)
    {
        bool ind=palimdrome(cur,i);
        if(ind) mn=min(mn,rec(i+1)+1);
    }
    ret=mn;
    return mn;
}

int main()
{
    int i,j,k,t,cas=0;
    scanf("%d ",&t);
    while(t--)
    {
        gets(str); mem(dp,-1);mem(palim,-1);
        L=strlen(str);
        int ret = rec(0);
        printf("Case %d: %d\n",++cas,ret);
    }
    return 0;
}

