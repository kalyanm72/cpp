ll dfs(ll x , ll p=-1){
	vis1[x] = 1;
	ll mx=0 , mx1=0;
	for(auto i : adj[x]){
		if(!vis1[i]){
			ll tmp = dfs(i,x)+1;
			if(tmp >= mx)
				mx1 = mx , mx = tmp;
			else if(tmp > mx1)
				mx1 = tmp;
		}
	}
	mmx = max(mmx,mx1+mx);
	return (p == -1) ? mmx : mx;
}
