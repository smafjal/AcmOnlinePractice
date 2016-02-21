#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))
#define sz 1000

typedef struct
{
    int info[sz][sz];
    int d[sz];
    int nv;
    int ne;
} node;

node g;
bool discover[sz];
bool process[sz];
int queue[sz];
int f=0,r=0;
char color[sz];


char complement(int x,int y);
void push(int i)
{
    queue[++r]=i;
}
int pop(void)
{
    return queue[++f];
}
int check(void)
{
    if(f==r)return 0;
    return 1;
}

void intial(void)
{
    int i;
    for(i=0; i<sz; i++)g.d[i]=0;
}

void insert(int x,int y,bool di)
{
    g.info[x][g.d[x]]=y;
    g.d[x]++;
    if(di==0)
        insert(y,x,1);

}
void read(void)
{
    intial();
    int i,j,k;
    int x,y;
    for(i=0; i<g.ne; i++)
    {
        scanf("%d %d",&x,&y);
        insert(x,y,0);
    }
}
void view(void)
{
    for(int i=0; i<g.nv; i++)
    {
        printf("nodes %d: ",i);
        for(int j=0; j<g.d[i]; j++)printf("%d ",g.info[i][j]);
        printf("\n");
    }
}
int  pro(int x,int y)
{
    if(color[x]==color[y])
    {
        printf("NOT BICOLORABLE.\n");
        return 0;
    }
    color[y]=complement(x,y);
    return 1;
}
char complement(int x,int y)
{
    if(color[x]=='w')return 'b';
    if(color[x]=='b') return 'w';
    return 'o';
}

int  bfs(int i)
{
    int j,k,v;
    int man=1;
    push(i);
    discover[i]=1;
    while(check())
    {
        v=pop();
        process[v]=1;
        for(i=0; i<g.d[v]; i++)
        {
            k=g.info[v][i];
            if(process[k]==0)
            {
                man=pro(v,k);
                if(!man)break;
            }

            if(discover[k]==0)
            {
                push(k);
                discover[k]=1;
            }

        }
        if(!man)break;
    }
    return man;
}

void work(void)
{
    mem(color,'o');
    int i,j,k,w=0;
    for(i=0; i<g.nv; i++)
    {
        if(discover[i]==0)
        {
            color[i]='w';
            w=bfs(i);
        }
        if(!w)break;
    }
    if(w)printf("BICOLORABLE.\n");
}

int main()
{
    int i,j,k,n;
    while(scanf("%d",&g.nv)==1)
    {
        if(g.nv==0)break;
        scanf("%d",&g.ne);
        read();
//        view();
        work();
//        view();
        f=0;r=0;
        for(i=0;i<sz;i++)
        {
            discover[i]=0;
            process[i]=0;
        }
    }
}
