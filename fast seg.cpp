
const ll N = 1e5;  // limit for array size
ll n;  // array size
ll t[26][2 * N];
void build() {  // build the tree
   for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(ll l, ll r) {
  ll res = 0,sum=0,li=l,ri=r;
  l+=n;r+=n;c
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[i][l++];
    if (r&1) res += t[i][--r];
}
  return sum;
}
