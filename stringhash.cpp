struct stringhash{
  string s;ll n,p=31;vector<ll> hash;vector<ll> po,inv;
  ll init(string a,ll num){
    s=a;n=num;
    hash.resize(n+1,0);
    po.resize(n+1,0);
    inv.resize(n+1,0);
    po[0]=1;
    for(ll i=1;i<=n;i++)po[i]=(p*po[i-1])%mod;
    inv[n]=power(po[n],mod-2);
    for(ll i=n-1;i>0;i--)
    inv[i]=(inv[i+1]*p)%mod;
    for(ll i=0;i<n;i++)
    hash[i+1]=(hash[i]+(s[i]-'a'+1)*po[i+1])%mod;
  }
  ll fin(ll i,ll j){
      ll res;j++;
      res=(hash[j]-hash[i]+mod)%mod;
      res=(res*hash[i+1])%mod;
      return res;
  }
  // 1 based index
};
