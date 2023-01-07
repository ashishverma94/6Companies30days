class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& tasks ) {
        vector<int> adj[n] ;
        for ( auto i : tasks )
            adj[i[0]].push_back(i[1]) ;

        vector<int> indegree(n,0) ;
        for ( int i = 0 ; i < n ; i++ )
            for ( auto j : adj[i] )
                indegree[j]++;
        
        queue<int> qu ;

        for ( int i = 0 ; i < n ; i++ )
            if ( indegree[i] == 0 ) qu.push(i) ;

        vector<int> topo;
        while(!qu.empty())
        {
            int node = qu.front() ;
            qu.pop() ;
            topo.push_back(node) ;
            for ( auto i : adj[node] )
            {
                indegree[i]--;
                if ( indegree[i] == 0 ) qu.push(i) ;
            }
        }

        return topo.size() == n ;
    }
};
