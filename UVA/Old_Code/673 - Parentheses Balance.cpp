#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>


using namespace std;

int main()
{
    char c;
    int i,j,k,l;
    char arr[130];
    scanf("%d",&k);
    gets(arr);
    while(k--)
    {
        gets(arr);
        stack<char>S;
        if(strcmp(arr,"")==0)
        {
            printf("Yes\n");
            continue;
        }
        int l=strlen(arr);
        for(i=0;i<l;i++)
        {
            if(arr[i]=='(')S.push(arr[i]);
            else if(arr[i]=='[')S.push(arr[i]);
            else if(arr[i]==')' || arr[i]==']')
            {
                if(!S.empty())
                {
                    c=S.top();
                    if(c=='(' && arr[i]==')')S.pop();
                    else if(c=='[' && arr[i]==']')S.pop();
                    else S.push(arr[i]);
                }
                else S.push(arr[i]);
            }
        }
        if(S.empty())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
