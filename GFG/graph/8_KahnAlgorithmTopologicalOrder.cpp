topologicalSort()
{
    vector<int> in_degree(V,0);
    
    for(int u=0;u<V;u++)
    {
        list<int>:: iterator its;
        
        for(itr = adj[u].begin();itr!=adj[u].end();itr++)
        {
            in_degree[*itr]++;
        }
    }
    queue<int> q;
    
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    
    vector<int> top_order;
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        top_order.push_back(u);
        
        
        list<int>::iterator itr;
        
        for(itr=adj[u].begin();itr!=adj[u].end();itr++)
        {
            if(--in_degree[*itr]==0)
            {
                q.push(*itr);
            }
        }
        cnt++;
    }
    if(cnt!=V)
    {
        cout<<"cycle exist\n";
        return;
    }
    
    for(int i=0;i<top_order.size();i++)
    {
        cout<<top_order[i]<<" ";
    }
}