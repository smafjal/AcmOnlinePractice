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

#define sz 30099
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

vector<int>vec[sz];
int ind[sz];
bool col[sz];
queue<int>Q;

void TP(void)
{
    int i,j,k,u,pu;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(i=0;i<SIZE(vec[u]);i++)
        {
            if(!col[vec[u][i]])
            {
                ind[vec[u][i]]--;
                if(!ind[vec[u][i]]){col[vec[u][i]]=1;Q.push(vec[u][i]);};
            }
        }
    }
    return;
}

void reset()
{
    mem(ind,0);
    while(!Q.empty())Q.pop();
    mem(col,0);
}

int main()
{
    int i,j,k,loop,x,y,w,n;
    scanf("%d",&loop);
    for(k=1;k<=loop;k++)
    {
        scanf(" %d",&n);

        mem(ind,0);
        map<string,int>M;
        int c=0;
        string s1,s2;
        for(i=0;i<=n+5;i++)vec[i].clear();

        for(i=0;i<n;i++)
        {
            cin>>s1;
            cin>>s2;
            if(!M[s1])M[s1]=++c;
            if(!M[s2])M[s2]=++c;
            vec[M[s1]].pb(M[s2]);
//            cout<<M[s1]<<"  "<<M[s2]<<endl;
            ind[M[s2]]++;
        }
        bool fl=0;
        for(i=1;i<=c;i++)
        {
            if(ind[i]==0){col[i]=1;fl=1;Q.push(i);}
        }
        if(!fl){printf("Case %d: No\n",k);continue;}
        TP();
        fl=1;
        for(i=1;i<=c;i++)
        {
            if(!col[i]){fl=0;break;}
        }
        if(fl)printf("Case %d: Yes\n",k);
        else printf("Case %d: No\n",k);
        reset();
    }
    return 0;
}
