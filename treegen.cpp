#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define eb emplace_back
ll mmin(){return LLONG_MAX;} template<typename T,typename... Args> T mmin(T a,Args... args) { return min(a,mmin(args...)); }
ll mmax(){return LLONG_MIN;} template<typename T,typename... Args> T mmax(T a,Args... args) { return max(a,mmax(args...)); }
 ll gcd(){return 0ll;} template<typename T,typename... Args> T gcd(T a,Args... args) { return __gcd(a,(__typeof(a))gcd(args...)); }
ll mod=1000000007  ;
ll id[100005],par[100005],*tree[500005],subt[100005]={0},p1,p2,p3,rev[100005],coun=0;
ll dfs(vector<ll> (&arr) [100005],ll num,ll parr)
{
    id[coun]=num;
    rev[num]=coun;
    coun++;
    for(ll i=0;i<arr[num].size();i++)
    {
        if(arr[num][i]!=parr)
        subt[num]+=dfs(arr,arr[num][i],num);
    }
    par[num]=parr;
    subt[num]++;
    return subt[num];
}
ll *construct(ll l,ll r,ll pos)
{
	if(l==r)
	{
		tree[pos]=new ll(id[l]);
		return tree[pos];
	}
    ll mid=l+(r-l)/2;
	ll *p1=construct(l,mid,2*pos+1);
	ll *p2=construct(mid+1,r,2*pos+2);
	merge(p1,p1+mid-l+1,p2,p2+r-mid-1,tree[pos]);
	return tree[pos];
}

pair<ll,ll> query(ll s,ll e,ll l,ll r,ll pos,ll num)
{
    ll ans;
    if(r<s || l>e)
    return {0,0};
    if (s<=l && e>=r){
        ans=lower_bound(tree[pos],tree[pos]+r-l+1,num)-tree[pos];
        return {ans,r-l+1-ans};
    }
    ll mid=l+(r-l)/2;
    pair<ll,ll> p1=query(s,e,l,mid,2*pos+1,num);
    pair<ll,ll> p2=query(s,e,mid+1,r,2*pos+2,num);
    return {p1.first+p2.first,p1.second+p2.second};
}
ll solv3(vector<ll> (&arr)[100005],ll n)
{
    ll sum=0,num,ans=0,anss=0,sum1=0,temp;
    pair<ll,ll> p;
    for(ll i=0;i<n;i++)
    {
        temp=id[i];
        ans=0;sum=0;sum1=0;
        num=arr[temp].size();
        for(ll j=0;j<num;j++)
        {
            if(arr[temp][j]!=par[temp])
            {
                p=query(rev[arr[temp][j]],rev[arr[temp][j]]+subt[arr[temp][j]]-1,0,n-1,0,temp);
                if(p2==3){
                ans+=p.first*(sum1);
                sum+=p.second;
                sum1+=p.first;}
                else if(p2==1)
                {
                    ans+=sum*(p.second);
                    sum+=p.second;
                    sum1+=p.first;
                }
                else
                {
                    ans+=sum*(p.first);
                    ans+=sum1*(p.second);
                    sum+=p.second;
                    sum1+=p.first;
                }
            }
        }
        if(temp!=0){
            if(p2==3)
            ans+=(temp-sum1)*(sum1);
            else if(p2==1)
            ans+=sum*(n-temp-1-sum);
            else
            {
                ans+=sum*(n-subt[temp]-(n-temp-1-sum));
                ans+=sum1*(n-temp-1-sum);
            }
        }
        anss+=ans;
    }
    return anss;
}
ll solve(vector<ll> (&arr)[100005],ll n)
{
    dfs(arr,0,-1);
    construct(0,n-1,0);
    return solv3(arr,n);
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   ll a,b,t,n,s1=0,s2=0,idx;
   cin>>t;
   vector<ll>  arr[100005];
   while(t--)
   {coun=0;
       cin>>n;
       for(ll i=0;i<=n;i++)
       subt[i]=0,arr[i].clear();
       for(ll i=0;i<=4*n;i++)
       free(tree[i]);
       cin>>p1>>p2>>p3;s1=0;s2=0;
       for(ll i=0;i<n-1;i++)
       {
           cin>>a>>b;
           a--;b--;
           arr[a].push_back(b);
           arr[b].push_back(a);
       }
       cout<<solve(arr,n)<<endl;
   }
}
