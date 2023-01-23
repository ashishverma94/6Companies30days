class Solution {
    int row, col, ans = 0;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}} ;
    void dfsAtBorder( vector<vector<int>> & grid, int i, int j ){
        if ( i >= row || j >= col || i < 0 || j < 0 )
            return ;
        
        if ( grid[i][j] == 1 )
            return ;
        grid[i][j] = 1;
        for ( int k = 0; k < 4; k++ ){
            dfsAtBorder(grid, i+dir[k].first, j+dir[k].second ) ;
        }  
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size() ;
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < col ; j++ ){
                if ( i == 0 || j == 0 || i == row-1 || j == col-1 ){
                    dfsAtBorder(grid, i, j ) ;
                }
            }
        }

        for ( int i = 1; i < row-1; i++ ){
            for ( int j = 1; j < col-1; j++ ){
                if ( grid[i][j] == 0 ){
                    ans ++ ;
                    dfsAtBorder(grid, i, j ) ;
                }
            }
        }

        return ans ;
    }
};
