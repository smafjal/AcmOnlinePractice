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

#define sz 128
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

char arr[sz];

bool ch(char c1,char c2)
{
    if((arr[c1]==1 && arr[c2]==1))return 1;
    if(c1=='0' && arr[c2]==1)return 1;
    return 0;
}
int main()
{
    int i,j,k,loop;
    char arr1[sz],arr2[sz];
    mem(arr,0);
    arr['a']=1;arr['e']=1;arr['i']=1;arr['o']=1;arr['u']=1;

    scanf("%d",&loop);
    while(loop--)
    {
        scanf(" %[^\n]",arr1);
        scanf(" %[^\n]",arr2);
        string s1,s2,s3,s4;
        s1=arr1;s2=arr2;
        bool fl=0;
//        cout<<s1<<" "<<s2<<endl;

        if(SIZE(s1)==SIZE(s2))
        {
            for(i=0;i<SIZE(s1);i++)
            {
                if(!(ch(s1[i],s2[i])))
                {
                    s3+=s1[i];
                    s4+=s2[i];
                }
            }
        }
        else {printf("No\n");continue;}
        if(s3==s4)printf("Yes\n");
        else printf("No\n");
        s1.clear();s2.clear();s3.clear();s4.clear();
    }
    return 0;
}
