int sor(int arr[],int n)
{
   int ma=-1000,coun=0;
   for(int i=0;i<n;i++)
   if(arr[i]>ma)
   ma=arr[i];
   while(ma)
   {
       coun++;
       ma/=10;
   }
   int res=1,temp[n];
   for(int i=0;i<coun;i++)
   {
       int c[10]={0};
       for(int j=0;j<n;j++)
       c[(arr[j]/res)%10]++;
       for(int j=1;j<10;j++)
       c[j]+=c[j-1];
       for(int j=n-1;j>=0;j--)
       {
           temp[c[(arr[j]/res)%10]-1]=arr[j];
           c[(arr[j]/res)%10]--;
       }
       for(int j=0;j<n;j++)
       arr[j]=temp[j];res*=10;
   }
}
