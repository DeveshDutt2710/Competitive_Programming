void dfs(int x, vector<vector<int>>& adj, vector<bool>& visited){
    visited[x] = true;
    for(int y : adj[x]){
        if(!visited[y]) dfs(y, adj, visited);
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    for(int i = 0; i < B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<bool> visited(A+1, false);
    dfs(1, adj, visited);
    if(visited[A]) return 1;
    else return 0;
}
