class Compare {
    public:
       bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
           if(a.first > b.first){
               return true;
           }
           return false;
      }
};

class Solution {
    int n ;
    vector<int> xo = {1,-1,0,0} ;
    vector<int> yo = {0,0,1,-1} ;

    bool isValid( int x, int y ){
        if ( x < n and y < n and x >= 0 and y >= 0 )
            return true ;
        return false ;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size() ;
        vector<vector<bool>> visited( n, vector<bool>(n,false)) ;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare > pq;
        pq.push({grid[0][0],{0,0}}) ;
        int ans = grid[0][0 ];
        while( !pq.empty()){
            for ( int i = 0; i < pq.size(); i++ ){
                auto curr = pq.top() ;
                pq.pop() ;

                int timeToEnter = curr.first;
                int x = curr.second.first ;
                int y = curr.second.second ;
                ans = max(ans, timeToEnter ) ;

                if ( x == n-1 and y == n-1 ) return ans ;
                for ( int i = 0; i < 4; i++ ){
                    int newx = x+xo[i];
                    int newy = y+yo[i];
                    if ( isValid(newx, newy) and visited[newx][newy] == false){
                        visited[newx][newy] = true ;
                        pq.push({grid[newx][newy],{newx,newy}}) ;
                    }
                }
            }
        }
        return -1 ;
    }
};
