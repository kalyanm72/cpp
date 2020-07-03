
struct sufar{

string s;ll n;vector<ll> c;
    void init(string a){
        s=a;
        s+="$";
        n=s.length();
    }
    vector<ll> sufcon(){

        vector<ll> p(n);c.resize(n);
        vector<pair<char,ll>> arr(n);
        for(ll i=0;i<n;i++)
        arr[i]={s[i],i};
        sort(arr.begin(),arr.end());

        for(ll i=0;i<n;i++){
            p[i]=arr[i].second;
            if(!i)
            c[p[i]]=0;
            else
            c[p[i]]=c[p[i-1]]-(arr[i-1].first==arr[i].first)+1;
        }

        ll k=0;
        while((1<<k)<n){
            vector<pair<pair<ll,ll>,ll>> temp(n);
            for(ll i=0;i<n;i++)
            temp[i]={{c[i],c[i+(1<<k)]},i};
            sort(temp.begin(),temp.end());
            for(ll i=0;i<n;i++)
            {
                p[i]=temp[i].second;
                if(!i)
                c[p[i]]=0;
                else
                c[p[i]]=c[p[i-1]]-(temp[i-1].first==temp[i].first)+1;
            }
            k++;
        }
        // for(auto it:c)cout<<it<<endl;
        return p;
    }
    vector<ll> lcp(){
        // cout<<"y";
        vector<ll> p;
        p=sufcon();
        vector<ll> ans(n);
        ll k=0,pi,j;
        for(ll i=0;i<n-1;i++){
            pi=c[i];
            j=p[pi-1];
            while(s[i+k]==s[j+k])
            k++;
            ans[pi]=k;
            k=max(k-1,0ll);
        }
        // cout<<"Y";
        return ans;
    }
    // init(string)
    // lcp() ||sufcon()
};
