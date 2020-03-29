template<typename T>
struct kruskal
{
    struct edge{
        T src,des,weight;
        edge(T a,T b,T c)
        {
            src=a;des=b;weight=c;
        }
        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };
    vector<edge> edges;
    union_find dsu;
    kruskal(int n)
    {
    	// cout<<n;
        dsu.init(n);
    }
    int add_edge(int a,int b,int c)
    {
        edges.emplace_back(a,b,c);
        return 0;
    }

    int solve()
    {
        sort(edges.begin(),edges.end());
        int n=edges.size(),sum=0;

        for(int i=0;i<n;i++)
        {
            if(dsu.unite(edges[i].src,edges[i].des))
            {
                sum+=edges[i].weight;
            }
        }
        return sum;
    }
};
