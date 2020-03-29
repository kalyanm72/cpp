#include<bits/stdc++.h>
using namespace std;long long n;
long long merge(long long arr[],long long temp[],long long l,long long mid,long long r)
{
    long long i=l,j=mid,k=l,count=0;
    while(i<mid&&j<=r)
    {
        if(arr[i]>arr[j]){count+=mid-i;
       temp[k++]=arr[j];j++;}
        else
        { 
            temp[k++]=arr[i];
            i++;
        }
    }
    for(;i<mid;i++)
    temp[k++]=arr[i];
    for(;j<=r;j++)
    temp[k++]=arr[j];
    for(i=l;i<=r;i++)
    arr[i]=temp[i];
    return count;
}
long long mergesort(long long arr[],long long temp[],long long l,long long r)
{
    long long count=0;
    if(l<r){
    long long mid=(l+r)/2;
    count=mergesort(arr,temp,l,mid);
    count+=mergesort(arr,temp,mid+1,r);
    count+=merge(arr,temp,l,mid+1,r);
    }
    return count;
}
long long find(long long arr[],long long n)
{
    long long temp[n];
    return mergesort(arr,temp,0,n-1);    
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        
        cin>>n;
        long long arr[n];
        for(long long i=0;i<n;i++)
        cin>>arr[i];
        cout<<find(arr,n);
    }
}
