class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int row = grid.size() , col = grid[0].size(), ans = INT_MIN ;
        for ( int i = 1 ; i < row-1 ; i++ )
            for ( int j = 1 ; j < col-1 ; j++ ){
                int temp = grid[i][j] + grid[i+1][j] + grid[i-1][j] + 
                           grid[i-1][j-1] + grid[i-1][j+1] + grid[i+1][j-1] + 
                           grid[i+1][j+1] ;
                ans = max(ans,temp) ;
            }
        
        return ans ;
    }
};
