long long INF = 1e15;
long long mod = 1e9 + 7;
typedef long long ll ;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // construct a graph 
        vector<pair<int,int>> graph[n] ;
        for ( auto i : roads )
        {
            graph[i[0]].push_back({i[1],i[2]}) ;
            graph[i[1]].push_back({i[0],i[2]}) ;
        }

        // declare a queue 
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq ;
        vector<ll> dist ( n, INF ), ways( n,0) ;
        dist[0] = 0 ;
        ways[0] = 1 ;
        pq.push({0,0}) ; // { dist, node }

        while( !pq.empty())
        {
            ll dis = pq.top().first ;
            ll node = pq.top().second ;

            pq.pop() ;

            for ( auto it : graph[node] )
            {
                ll adjNode = it.first ;
                ll wt = it.second ;

                if ( dis + wt < dist[adjNode] )
                {
                    dist[adjNode] = dis+ wt ;
                    pq.push( {dis+wt, adjNode} ) ;
                    ways[adjNode] = ways[node] ;

                }

                else if ( dis+wt == dist[adjNode] )
                {
                    ways[adjNode] = (ways[node] + ways[adjNode])%mod ;
                }
            }
        }

        return ways[n-1]%mod ;
    }
};
