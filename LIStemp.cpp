template<typename T>
struct LIS{
    pair<vector<ll>,ll> solve(T arr[],ll n)
    {
        vector<T> ans(n,0);ll len=1,idx;
        for(ll i=0;i<n;i++)
        {
           if(arr[i]<ans[0])
           ans[0]=arr[i];
           else if(arr[i]>ans[len-1])
           ans[len]=arr[i],len++;
           else
           {
               idx=lower_bound(ans.begin(),ans.begin()+len,arr[i])-ans.begin();
               if(idx==len)
               {
                   ans[len]=arr[i];len++;
               }
               else
               {
                   ans[idx]=arr[i];
               }
           }
        }
        pair<vector<ll>,ll> p;
        p={ans,len};
        return p;
    }
};

// number 
ll fun(ll arr[],ll n)
{
    ll max=1,len=1;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1])
            len++;
        else{
            if(len > max)
                max = len;
            len = 1;
        }
    }
    if(len > max)
        max = len;

    return max;
}
