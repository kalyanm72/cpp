 a[1001],b[1001][1001];
long long  power(long long  a,long long b,long long mod)
{
    long long  res=1;
    while(b>0)
    {
        if(b&1)
        res=(res*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return res;
}
void fun(long long  n) 
{
    long long  i,j,x;
    for(long long i=0;i<1001;i++){
        for(long long i=0;i<1001;i++)
        b[i][j]=0;
    }
    b[1][0]=b[1][1] = 1;
    b[2][0]=1;b[2][1]=2;b[2][2]=1;
    x=4;
    for (i = 3; i <= n; i++) 
    {
        b[i][0]=1;
        for(j=1;j<x;j++)
        {
            b[i][j]=(b[i-1][j-1]+b[i-1][j])%1000000007;
        }
        x++;
    }
}
