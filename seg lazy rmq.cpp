
struct segtree{
	vector<ll> tree;//(4*LIM);
	vector<ll> lazy;
ll combine(ll a,ll b)
{
	return min(a,b);
}
segtree(ll n){
	tree=vector(4*n+100,0);
		lazy=vector(4*n+100,0);
}
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += val;    // Update it
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = combine(tree[node*2], tree[node*2+1]);        // Updating root with max value
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 1e18;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += lazy[node];    // Update it

        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return combine(p1,p2);
}};
// 1 based indexing
//initialising
	// segtree tree(n);
//updating range (1,1,n,l,r,val)
	// tree.updateRange(1,1,n,i,n,b[i]);
//query queryRange(1,1,n,l,r)
	// tree.queryRange(1,1,n,r,n);
