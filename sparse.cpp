struct sparse{
    ll MAXN = 10000005;ll K=25;
    long long st[MAXN][K],N;
    int log[MAXN+1];

    void init(vector<ll> arr){
        N=arr.size();
for (ll i = 0; i < N; i++)
st[i][0] = arr[i];
log[1] = 0;
for (int i = 2; i < MAXN; i++)
log[i] = log[i/2] + 1;

for (ll j = 1; j <= K; j++)
for (ll i = 0; i + (1 << j) <= N; i++)
    st[i][j] = __gcd(st[i][j-1] , st[i + (1 << (j - 1))][j - 1]);
}
    ll rmq(ll l,ll r){
        int j = log[r - l + 1];
int minimum = __gcd(st[l][j], st[r - (1 << j) + 1][j]);
return minimum;
    }
};
