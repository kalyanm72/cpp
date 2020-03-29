template<typename T>
struct union_find{
    vector<T> par,rn;
   int init(int n)
   {
     if(n)
     {
         par.resize(n);
         rn.resize(n);
         for(auto it:en)
         it=0;
         for(int i=0;i<n;i++)
         par[i]=i;
     }
   }
   T find(T a)
   {
       if(par[a]!=a)
       par[a]=find(par[a]);
       return par[a];
   }
   bool unite(T a,T b)
   {
       T p1,p2;
       p1=find(a);
       p2=find(b);
       if(p1==p2)
       return false;
       if(rn[p1]<rn[p2])
       par[p1]=p2;
       else if(rn[p1]>rn[p2])
       par[p2]=p1;
       else
       {
           par[p1]=p2;
           rn[p2]++;
       }
       return true;
   }
};
