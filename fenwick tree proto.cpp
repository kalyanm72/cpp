#include<bits/stdc++.h>
using namespace std;
long long getsum(long long bit[],long long arr[],long long idx)
{
    idx++;long long sum=0;
    while(idx>0)
    {
       // cout<<idx<<" ";
        sum+=bit[idx];
        idx-=idx&-idx;
    }
    return sum;
}
long long update(long long bit[],long long n,long long idx,long long val)
{
    idx++;
    while(idx<=n)
    {
        bit[idx]+=val;//cout<<bit[idx]<<" ";
        idx+=idx&-idx;
    }
}
long long *construc(long long bit[],long long arr[],long long n)
{
    for(long long i=0;i<n+1;i++)
    {
        bit[i]=0;
    }
    for(long long i=0;i<n;i++)
    {
        update(bit,n,i,arr[i]);
    }
    return bit;
}
int main()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long bit [n+1];
    construc(bit,arr,n);
    long long q;
    cin>>q;long long key;
    while(q--)
    {
        cin>>key;
        long long idx,val;
        switch(key)
        {
            case 1:
            {
                cin>>idx;
                cout<<getsum(bit,arr,idx-1)<<endl;
                break;
            }
            case 2:
            {
                cin>>idx>>val;
                val=val-arr[idx-1];
                update(bit,n,idx-1,val);
            }
        }
    }
}
