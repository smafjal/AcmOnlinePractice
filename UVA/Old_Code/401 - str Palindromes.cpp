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


/**
A	A	M	M	Y	Y
B		N		Z	5
C		O	O	1	1
D		P		2	S
E	3	Q		3	E
F		R		4
G		S	2	5	Z
H	H	T	T	6
I	I	U	U	7
J	L	V	V	8	8
K		W	W	9
L	J	X	X
*/
char arr[150];
string s1,s2;

bool mirrored()
{
    for(int i=0;i<SIZE(s1);i++)
    {
        if(arr[s1[i]]!='-')s2.pb(arr[s1[i]]);
        else return 0;
    }
//    cout<<"s2:  "<<s2<<endl;
    reverse(s2.begin(),s2.end());
//    cout<<"RE S2:  "<<s2<<endl;
    if(s2==s1)return 1;
    return 0;
}

void reset()
{
    char a[]="ABCDEFJHIJKLMNOPQRSTUVWXYZ0123456789";
    char b[]="A---3--HIL-JM-O---2TUVWXY5-1SE-Z--8-";
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        arr[a[i]]=b[i];
    }
//    for(int i=0;i<128;i++) printf("%c     %c\n",i,arr[i]);
}

bool  pl()
{
    s2=s1;
    reverse(s2.begin(),s2.end());
    if(s2==s1)return 1;
    return 0;
}

int main()
{
    int i,j,k;
    char aa[100];
    reset();
    while(scanf(" %s",aa)==1)
    {
//        printf("%s\n",aa);
        s1=aa;
//        cout<<"S1: "<<s1<<endl;
        int m,p;
        m=mirrored();
        p=pl();
//        cout<<endl<<endl;

        if(!m && !p)cout<<s1<<" -- is not a palindrome."<<endl<<endl;
        else if(!m && p)cout<<s1<<" -- is a regular palindrome."<<endl<<endl;
        else if(m && !p)cout<<s1<<" -- is a mirrored string."<<endl<<endl;
        else if(m && p)cout<<s1<<" -- is a mirrored palindrome."<<endl<<endl;
        s1.clear();s2.clear();
    }
    return 0;
}
