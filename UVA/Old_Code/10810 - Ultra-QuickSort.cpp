#include<stdio.h>
#include<iostream>
#include<vector>

#define MAX 500009
#define ll long long

using namespace std;

ll arr[MAX],cnt;
ll tmp[MAX];

void merge(ll low,ll mide,ll high)
{
    ll i,j,k;

    i=low;j=mide+1;k=0;

    while((i<=mide) and (j<=high))
    {
        if(arr[i]<=arr[j])
        {
            tmp[++k]=arr[i];i++;
        }
        else if(arr[i]>arr[j])
        {
            tmp[++k] = arr[j];
            cnt+=(mide-i)+1;
            j++;
        }
    }

    while(i<=mide) {tmp[++k]=arr[i];i++;}
    while(j<=high) {tmp[++k]=arr[j];j++;}

    k=1;
    for(i=low;i<=high;i++)
    {
        arr[i]=tmp[k];
        k++;
    }
    return;
}

void merge_sort(ll lo,ll hi)
{
    if(lo<hi)
    {
        ll mid=(lo+hi)/(ll)2;
        merge_sort(lo,mid);
        merge_sort(mid+1,hi);
        merge(lo,mid,hi);
    }
    return;
}


int main()
{
    ll i,j,k,n;
    while(scanf("%lld",&n)==1 and n)
    {
        bool fl=1;ll mx=-1;

        for(i=1;i<=n;i++)
        {
            scanf("%lld",&k);
            arr[i]=k;
            if(mx>k) fl=0;
            mx=k;
        }
        if(fl) {printf("0\n");continue;}

        cnt=0;
        merge_sort((ll)1,n);
        printf("%lld\n",cnt);
    }
    return 0;
}
