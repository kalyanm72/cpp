#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   string s;
   cin>>s;ll flg=0,curr=0;
   for(ll i=s.length()-1;i>=0;i--)
   {
       if((i-s.length()-1)%2==0){
       if(i!=0)
       curr++;
       else
       {
           if(flg)
           curr++;
       }}
       if(s[i]=='1')
       flg=1;
   }
   cout<<curr;
}
