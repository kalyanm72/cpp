#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     ll t,num,n,k,ma,mi,temp;int flg;
     cin>>t;
     while(t--)
     {
         cin>>n>>k;ma=-1;
         vector< vector<ll> > arr;
         vector<ll>p;
         for(ll i=0;i<300000;i++)
         {
           arr.push_back(p);             
         }
         for(ll i=0;i<n;i++)
         {
             cin>>num;
             ma=max(ma,num);
             arr[num].push_back(i);
         }flg=0;mi=40000000;
         for(ll i=1;i<=ma;i++)
         {
             for(ll j=1;j<arr[i].size();j++)
             arr[i][j]+=arr[i][j-1];
             if(arr[i].size()>=k){flg=1;
             temp=(k*(k-1))/2;
             for(ll j=0;j<=arr[i].size()-k;j++)
                 {
                     if(j==0)
                     {
                         mi=min(mi,arr[i][j+k-1]-temp);
                     }
                     else
                     {
                         mi=min(mi,arr[i][j+k-1]-arr[i][j-1]-temp);
                     }
                     temp+=k;
                 }
             }
         }
         if(flg==1)
         {
             cout<<mi<<endl;
         }
         else
         cout<<"-1"<<endl;
         
     }
     
}

