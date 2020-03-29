#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
long long maxsub(long long arr[],long long l,long long r)
{
    long long mid=(l+r)/2,sum=0,maxi=-INF;
    for(long long i=mid;i>=l;i--)
    {
        sum+=arr[i];
        if(sum>maxi)
        maxi=sum;
    }
    sum=0;long long maxxi=-INF;
    for(long long i=mid+1;i<=r;i++)
    {
        sum+=arr[i];
        if(sum>maxxi)
        maxxi=sum;
    }
    return maxxi+maxi;
}
long long find(long long arr[],long long l,long long r)
{
    long long mid=(l+r)/2;
    if(l==r)
    return arr[l];
    long long ll,rr,mm;
    ll=find(arr,l,mid);
    rr=find(arr,mid+1,r);
    mm=maxsub(arr,l,r);
    return max(ll,max(mm,rr));
}
int main()
{
   long long n;
   cin>>n;
   long long arr[n];
   for(long long i=0;i<n;i++)
   cin>>arr[i];
   cout<<find(arr,0,n-1);
}
