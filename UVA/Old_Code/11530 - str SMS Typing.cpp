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


/*---------------------
|      | abc | def  |
---------------------
| ghi  | jkl | mno  |
---------------------
| pqrs | tuv | wxyz |
---------------------
|      | <SP>|      |
---------------------
*/

int main()
{
    int i,j,k,loop;
    scanf("%d",&loop);
    scanf("%*c");
    for(k=1;k<=loop;k++)
    {
        string s;
        getline(cin,s);
        int count=0;
        for(i=0;i<SIZE(s);i++)
        {
            if(s[i]=='a'||s[i]=='d'||s[i]=='g'||s[i]=='j'||s[i]=='m'||s[i]=='p'||s[i]=='t'||s[i]=='w'||s[i]==' ')count++;
            else if(s[i]=='b'||s[i]=='e'||s[i]=='h'||s[i]=='k'||s[i]=='n'||s[i]=='q'||s[i]=='u'||s[i]=='x')count+=2;
            else if(s[i]=='c'||s[i]=='f'||s[i]=='i'||s[i]=='l'||s[i]=='o'||s[i]=='r'||s[i]=='v'||s[i]=='y')count+=3;
            else if(s[i]=='s'||s[i]=='z')count+=4;
        }
        printf("Case #%d: %d\n",k,count);
    }
    return 0;
}
