class Solution {
public:
    bool isValid ( int x , int y , int n )
    {
        if ( x >= 0 && y >= 0 && x < n && y < n )
            return true ;
        return false ;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        double curr[n][n] , next[n][n] ;
        memset( curr , 0 , sizeof ( curr )) ;
        memset( next , 0 , sizeof ( next )) ;
        
        int xc[8] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 } ;
        int yc[8] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2 } ;
        
        curr[row][column] = 1 ;
        
        for ( int move = 0 ; move < k ; move ++ )
        {
            for ( int i = 0 ; i < n ; i ++ )
            {
                for ( int j = 0 ; j < n ; j ++ )
                {
                    if ( curr[i][j] != 0 )
                    {
                        for ( int point = 0 ; point < 8 ; point ++ )
                        {
                            int x = i+xc[point] ;
                            int y = j+yc[point] ;
                            if ( isValid( x , y , n ))
                                next[x][y] += curr[i][j] / 8.0 ;
                        }
                    }
                }
            }
            
            for ( int i = 0 ; i < n ; i ++ )
            {
                for ( int j = 0 ; j < n ; j ++ )
                {
                    curr[i][j] = next[i][j] ;
                }
            }
            memset( next , 0 , sizeof(next)) ; 
        }
        
        double probability = 0 ; 
        for ( int i = 0 ; i < n ; i ++ )
        {
            for ( int j = 0 ; j < n ; j ++ )
            {
                probability += curr[i][j] ;
            }
        }
        
        return probability ;
    }
};
