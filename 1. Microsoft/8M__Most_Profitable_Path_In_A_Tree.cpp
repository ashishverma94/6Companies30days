const int INF = 1e9+1 ;
class Solution {

    vector<vector<int>> graph ;
    vector<int> parent;
    vector<int> dist ;
    vector<int> bestctl;
    vector<int> val;

    void calculateParent( int root )
    {
        for ( auto child : graph[root] )
        {
            if ( child == parent[root] ) continue ;
            parent[child] = root ;
            calculateParent( child ) ;
        }
    }

    void maxPathToLeaf(int root )
    {
        int& cost = bestctl[root] ;
        cost = -INF ;
        int child_count = 0 ;
        for ( auto child : graph[root] )
        {
            if ( child == parent[root] ) continue ;
            child_count++;
            maxPathToLeaf( child ) ;
            cost = max( cost, bestctl[child] ) ;
        }

        if ( child_count == 0 ) cost = val[root] ;
        else cost += val[root] ;
    }

    int findBest( int root , int skip )
    {
        int result = -INF ;
        int child_count = 0 ;
        for ( auto child : graph[root] )
        {
            if ( child == parent[root] ) continue ;
            child_count++;
            if ( child == skip ) continue ;

            result = max( result, bestctl[child] ) ;
        }

        if ( child_count == 0 ) return 0 ;
        return result ;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // count nodes 
        int N = amount.size() ;
        graph.resize(N+1) ;

        // make graph
        for ( auto i : edges )
        {
            graph[i[0]].push_back(i[1]) ;
            graph[i[1]].push_back(i[0]) ;
        }

        int n = edges.size() ;
        val.resize(N) ;
        val = amount ;
        parent.assign(N+1,-1) , dist.assign(N+1,-1), bestctl.resize(N) ;

        int curr = bob, currdist = 0 ;

        // calculate parent of each node 
        calculateParent(0) ;

        // calculate cost of each node ;
        maxPathToLeaf(0) ;

        // calculate path of bob 
        vector<int> bobPath;
        while(bob != -1 )
        {
            bobPath.push_back(bob) ;
            bob = parent[bob] ;
        }
        reverse( bobPath.begin(), bobPath.end()) ;

        int result = -INF ;
        int bobPathSize = bobPath.size() ; 
        for ( int ind = 0, cost_till_now = 0 ; ind < bobPathSize; ind++ )
        {
            bool is_alice = ( ind < bobPathSize-1-ind ) ;
            bool is_same  = ( ind == bobPathSize-1-ind) ;

            if ( is_alice ) cost_till_now += val[bobPath[ind]] ;
            if ( is_same  ) cost_till_now += val[bobPath[ind]]/2 ;

            result = max( result, cost_till_now+findBest(bobPath[ind], ind+1 < bobPathSize ? bobPath[ind+1] : -1 )) ;
        }

        return result ;
    }
};
