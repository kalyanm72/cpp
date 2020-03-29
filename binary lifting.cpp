ll walk(ll curr,ll k)
{
	ll idx=curr;
   for(ll i=0;i<=d&&idx!=-1;i++)
   {
	   if((1<<i)&k)
		   idx=dp[i][idx];
   }
	return idx;
}
ll lca(ll a,ll b)
{
	if(nodes[a].dep<nodes[b].dep)
	{
		b=walk(b,nodes[b].dep-nodes[a].dep);
	}
	else if(nodes[b].dep<nodes[a].dep)
	{
	  a=walk(a,nodes[a].dep-nodes[b].dep);	
	}
	if(a==b)
		return a;
	for(ll i=d;i>=0;i--)
	{
		if(dp[i][a]!=dp[i][b])
		{
			if(dp[i][a]!=-1&&a!=-1)
				prev1=a;
			if(dp[i][b]!=-1&&b!=-1)
				prev2=b;	
			a=dp[i][a];
			b=dp[i][b];
		}
	}
	return dp[0][a];
}
for(ll i=0;i<=d;i++)
		{
			for(ll j=0;j<=n;j++)
			{
				dp[i][j]=-1;
			}
		}
		
		for(ll i=1;i<=d;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(dp[i-1][j]!=-1)
					dp[i][j]=dp[i-1][dp[i-1][j]];
			}
		}
