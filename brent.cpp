#include<bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
ll gcd(){return 0ll;} template<typename T,typename... Args> T gcd(T a,Args... args) { return __gcd(a,(__typeof(a))gcd(args...)); }
ll fun(string s)
{
	ll res=0;
	for(ll i=0;i<s.length();i++)
	{
		res=res*10+s[i]-'0';
	}
	return res;
}
ll mult(ll a, ll b, ll mod) {
    return (ll)a * b % mod;
}
ll f(ll x, ll c, ll mod) {
    return (mult(x, x, mod) + c) % mod;
}
void power(ll a,ll b,ll &n,ll &res) {
  res=1;
  a%=n;
  while(b) {
    if(b&1) res = (res*a)%n;
    b>>=1;
    a = (a*a)%n;
  }
}
bool composite(ll n,int a,int s,ll d,ll x) {
  power(a,d,n,x);
  if(x==1 || x==n-1) return 0;
  for(ll i=1;i<s;i++) {
    x = (x*x)%n;
    if(x==n-1) return 0;
  }
  return 1;
}

bool isprime(ll n) {
  int s=0;
  ll d=n-1,x;
  while(!(d&1)) d>>=1,s++;
  for(int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149} ) {
    if(a==n)
      return 1;
    if(!(n&1)) return 0;
    // out(n);cout<<" ";
    if(composite(n,a,s,d,x))
      return 0;
  }
  return 1;
}
ll brent(ll n) {
    ll c,x0;
    srand(time(0));
    x0=rand()%n+1;
    c=rand()%n+1;
    ll x = x0;
    ll g = 1;
    ll q = 1;
    ll xs, y;
    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = __gcd(q,n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = __gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}
void out(ll n) {
  stack<char> s;
  while(n) {
    s.push((n%10)+'0');
    n/=10;
  }
  while(!s.empty()) {
    cout<<s.top();
    s.pop();
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll t,num,curr;string s;
    ll n;
    vector <ll> arr;
       while(1)
     {
     	cin>>s;
        n=fun(s);
        if(n==0)
        break;
        arr.clear();
        while(n!=1)
        {
             if(isprime(n))
             break;
             num=brent(n);
             while(!isprime(num))
             {
                 num=brent(num);
             }
             while(n%num==0)
             {
                 arr.push_back(num);
                 n/=num;
             }
        }
        if(n!=1)
        arr.push_back(n);
        curr=1;
        if(arr.size()==1)
        {
        	  out(arr[0]);cout<<"^1"<<endl;
        	  //cout<<arr[0]<<"^1"<<endl;
        }
        for(ll i=1;i<arr.size();i++)
        {
            if(i==arr.size()-1)
            {
                if(arr[i]==arr[i-1])
                {
                	out(arr[i-1]);
                    cout<<"^";out(curr+1);cout<<endl;curr=1;
                }
                else
                {
                	out(arr[i-1]);
                    cout<<"^";out(curr);cout<<" ";out(arr[i]);cout<<"^1"<<endl;
                }
                break;
            }
            if(arr[i]!=arr[i-1])
            {
            	out(arr[i-1]);
                cout<<"^";out(curr);cout<<" ";curr=1;
            }
            else
            curr++;
        }
     }
}
