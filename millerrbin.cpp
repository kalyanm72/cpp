ll mul(ll a,ll b,ll mod)
{
    ll res=0;
    b%=mod;
    while(b)
    {
        if(b&1)
        res=(res+a)%mod;
        a=(a+a)%mod;
        b/=2;
    }
    return res;
}
ll power(ll a,ll b,ll mod)
{
    ll res=1;
    b%=mod;
    while(b)
    {
        if(b&1)
        res=mul(res,a,mod);
        a=mul(a,a,mod);
        b/=2;
    }
    return res;
}
ll check(ll n,ll num,ll d,ll r)
{
   ll  res=power(num,d,n);
    if(res==1||res==n-1)
    return 0;
    for(ll i=1;i<r;i++)
    {
        res=mul(res,res,n);
        if(res==n-1)
        return 0;
    }
    return 1;
}
ll solve(ll num)
{

    if(num<2)
    return 0;
    if(num<4)
    return num==2||num==3;
    ll arr[12]={2,3,5,7,11,13,17,19,23,29,31,37};ll d=0,r=0;
    d=num-1;
    while((d&1)==0)
    {
        d/=2;
        r++;
    }
    for(ll i=0;i<12;i++)
    {
        if(num==arr[i])
        return 1;
        if(check(num,arr[i],d,r)){
        //	cout<<"y";
        return 0;}
    }
    return 1;
}
