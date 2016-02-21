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

void worke(string s)
{
    int i,j,k;
    string s1,s2;

    for(i=0;i<SIZE(s)-2;i++)
    {
        s2+=s[i];
    }
//    cout<<"s2: "<<s2<<endl;

    char c1,c2,c3;

    c3=s[SIZE(s)-1];
    c2=s[SIZE(s)-2];
///// in "o", "s", "ch", "sh" or "x", append "es"

//    cout<<c1<<"  "<<c2<<" "<<c3<<endl;
    if((c3=='y') && c2 !='a' && c2 !='e' && c2 !='i'&& c2 !='o' && c2 !='u'){s2+=c2;s2+="ies";cout<<s2<<endl;return;}
    if(c2=='c' && c3=='h'){s2+=c2;s2+=c3;s2+="es";cout<<s2<<endl;return;}
    if(c2=='s' && c3=='h'){s2+=c2;s2+=c3;s2+="es";cout<<s2<<endl;return;}
    if(c3=='s'){s2+=c2;s2+=c3;s2+="es";cout<<s2<<endl;return;}
    if(c3=='o'){s2+=c2;s2+=c3;s2+="es";cout<<s2<<endl;return;}
    if(c3=='x'){s2+=c2;s2+=c3;s2+="es";cout<<s2<<endl;return;}

    s2+=c2;s2+=c3;s2+='s';cout<<s2<<endl;
    return;
}
int main()
{
    int i,j,k,l,n;
    while(scanf(" %d %d",&l,&n)==2)
    {

        string s1,s2;
        vector<string>s,ss;

        for(i=1;i<=l;i++)
        {
            cin>>s1>>s2;
            s.pb(s1);
            ss.pb(s2);
        }
        string str;

        for(i=1;i<=n;i++)
        {
            cin>>str;
            bool fl=0;
            for(j=0;j<SIZE(s);j++)
            {
                if(str==s[j]){cout<<ss[j]<<endl;fl=1;break;}
            }
            if(!fl)worke(str);
        }
        ss.clear();s.clear();s1.clear();s2.clear();
    }
    return 0;
}
