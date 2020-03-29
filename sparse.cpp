struct sparse{
    ll MAXN = 10000005;ll K=25;
    long long st[MAXN][K];
    int log[MAXN+1];

    void init(ll array[]){
for (ll i = 0; i < N; i++)
st[i][0] = array[i];
log[1] = 0;
for (int i = 2; i < MAXN; i++)
log[i] = log[i/2] + 1;

for (ll j = 1; j <= K; j++)
for (ll i = 0; i + (1 << j) <= N; i++)
    st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
}
    ll rmq(ll l,ll r){
        int j = log[r - l + 1];
int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
return minimum;
    }
};
