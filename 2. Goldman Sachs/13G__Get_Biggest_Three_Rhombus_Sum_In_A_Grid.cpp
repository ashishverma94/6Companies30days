class Solution {

    int row , col ;
    bool isValid( int x, int y )
    {
        if ( x >= 0 and y >= 0 and x < row and y < col )
            return true ;
        return false ;
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size() ;

        vector<vector<int>> rtol(row,vector<int>(col,0)) ;
        for ( int i = 0 ; i < col; i++ )
            rtol[0][i] = grid[0][i] ;
        for ( int i = 0 ; i < row ; i++ )
            rtol[i][col-1] = grid[i][col-1] ; 

        for ( int i = 1; i < row ; i++ )
            for ( int j = 0; j < col-1 ; j++ )
                rtol[i][j] = grid[i][j] + rtol[i-1][j+1] ;

        vector<vector<int>> ltor(row,vector<int>(col,0)) ;
        for ( int i = 0 ; i < col; i++ )
            ltor[0][i] = grid[0][i] ;
        for ( int i = 0 ; i < row ; i++ )
            ltor[i][0] = grid[i][0] ; 

        for ( int i = 1; i < row ; i++ )
            for ( int j = 1; j < col ; j++ )
                ltor[i][j] = grid[i][j] + ltor[i-1][j-1] ;
        
        vector<int> vec ;
        for ( int x = 0 ; x < row ; x++ )
        {
            for ( int y = 0 ; y < col ; y++ )
            {
                  vec.push_back(grid[x][y]) ;
                  for ( int k = 1; k < min(row,col) ; k++ )
                  {
                      int lx = x+k, ly = y-k;
                      int rx = x+k, ry = y+k;
                      int bx = x+2*k, by = y;
                
                      if ( isValid(lx,ly) && isValid(rx,ry) && isValid(bx,by) )
                      {
                        int one = rtol[lx][ly] - rtol[x][y];
                        int two = rtol[bx][by] - rtol[rx][ry] ;
                        int thr = ltor[bx][by] - ltor[lx][ly] ;
                        int fou = ltor[rx][ry] - ltor[x][y] ;

                        int tot = one + two + thr + fou + grid[x][y] - grid[bx][by] ;
                        vec.push_back(tot) ;
                      }  
                      else
                          break;
                  }
            }
        }

        set<int> s ;
        for ( auto i : vec )  s.insert(i) ;
        vector<int> ans;
        for ( auto i : s ) ans.push_back(i) ;
        
        sort(ans.rbegin(),ans.rend()) ;
        if ( ans.size() <= 3 ) return ans ;
        
        return {ans[0],ans[1],ans[2]} ;
    }
};
