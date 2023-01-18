class Solution {
    int inf = 1e7 ;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<int>> distArr( n, vector<int>(n,0)) ;
        for ( auto edge : edges ){
            distArr[edge[0]][edge[1]] = edge[2] ;
            distArr[edge[1]][edge[0]] = edge[2] ;
        }

        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n; j++ ){
                if ( i == j ) continue ;
                if ( distArr[i][j] == 0 ) distArr[i][j] = inf ;
            }
        }

        for ( int k = 0; k < n; k++ ){
            for ( int i = 0; i < n; i++ ){
                for ( int j = 0; j < n; j++ ){
                    distArr[i][j] = min( distArr[i][k] + distArr[k][j] , distArr[i][j] ) ;
                }
            }
        }

        int ans = 0, dist = n+1;

        for ( int i = 0; i < n; i++ ){
            int temp = 0;
            for ( int j = 0; j < n; j++ ){
                if ( distArr[i][j] <= thres ) temp++;
            }
            if ( temp <= dist ){
                dist = temp ;
                ans = i ;
            }
        }
        return ans ;
    }
};
