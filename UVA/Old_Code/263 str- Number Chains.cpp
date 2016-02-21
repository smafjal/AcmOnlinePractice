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
#include<functional>

#define sz 599
#define pb(a) push_back(a)
#define paii(a,b) pair<a,b>
#define oo 1<<29
#define makp(a,b) make_pair(a,b)
#define SIZE(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

bool com(const char &x,const char &y){return x>y;}

string sub(string s1,string s2)
{
    int i;
    char arr[sz],arr1[sz],arr2[sz];
    long long p1,p2,p;
    string s3;

    for(i=0;i<SIZE(s1);i++)arr1[i]=s1[i];
    arr1[i]='\0';
    for(i=0;i<SIZE(s2);i++)arr2[i]=s2[i];
    arr2[i]='\0';

    sscanf(arr1,"%lld",&p1);
    sscanf(arr2,"%lld",&p2);
    p=p2-p1;

//    cout<<"S1:  "<<s1<<endl;
//    cout<<"S2:  "<<s2<<endl;
//    cout<<"P1:  "<<p1<<endl;
//    cout<<"P2:  "<<p2<<endl;
//    cout<<"P:  "<<p<<endl;
    if(p==0){s3+="0";return s3;}
    int k=0;
    while(p)
    {
        arr[k]=(p%10)+'0';
        p/=10;
        k++;
    }
//    k++;
    arr[k]='\0';
    s3=arr;
    reverse(s3.begin(),s3.end());
//    cout<<"SUB S3:   "<<s3<<endl;
    return s3;
}

string ass(string s2)
{
    string s1;
    bool fl=1;
    sort(s2.begin(),s2.end());
//    cout<<"sort:  "<<s2<<endl;
    if(SIZE(s2)==1){return s2;}
    for(int i=0;i<SIZE(s2);i++)
    {
        if(fl){if(s2[i]=='0')continue;else fl=0;}
        s1+=s2[i];
    }
//    cout<<"SSSSSSS:  "<<s1<<endl;
    return s1;
}
int main()
{
    int i,j,k,loop;
    char  arr[sz];

    while(scanf(" %s",arr)==1)
    {
        string s1,s2,s3,s;
        map<string,int>S;

        s=arr;
        if(s=="0")break;
        s2=s;
        sort(s2.begin(),s2.end(),com);
        s1=ass(s);

        s3=sub(s1,s2);
//        cout<<s1<<"  "<<s2<<"  "<<s3<<endl;

//        cout<<"S3:  "<<s3<<endl;
//        char c;
//        scanf(" %c",&c);
//        scanf("%*c");

        k=0;
        S[s3]=++k;
        cout<<"Original number was "<<s<<endl;
        while(true)
        {
            cout<<s2<<" - "<<s1<<" = "<<s3<<endl;
            s2=s3;
            s1=s3;
            sort(s2.begin(),s2.end(),com);
            s1=ass(s3);
            s3=sub(s1,s2);
//            cout<<"S3 in loop "<<s3<<endl;
            if(!S[s3]){S[s3]=++k;}
            else break;
        }
        k++;
        cout<<s2<<" - "<<s1<<" = "<<s3<<endl;
        cout<<"Chain length "<<k<<endl<<endl;
        mem(arr,0);

    }
}
