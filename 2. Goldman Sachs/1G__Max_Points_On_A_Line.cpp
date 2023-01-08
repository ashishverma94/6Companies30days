class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        
        int s = p.size() ;
        if ( s <=2 )
            return s ;
            
        int ans = 2 , myans = 2 ;
        for ( int i = 0 ; i  < s ;  i ++ )
        {
            int x_s = p[i][0] ;
            int y_s = p[i][1] ;
            
            for ( int j = i+1 ;  j < s ; j ++ )
            {
                int x_f = p[j][0] ;
                int y_f = p[j][1] ;
                ans = 2 ;
                for ( int k = 0 ; k < s ; k ++ )
                {
                    int c_x = p[k][0] ;
                    int c_y = p[k][1] ;
                    
                    if ( k != i && k != j )
                    {
                        if ( ( c_y -y_s ) * ( x_f - c_x ) == ( c_x  - x_s ) * ( y_f - c_y ) ) 
                            ans ++ ;
                    }
                }
                myans = max ( myans , ans ) ;
            }
        }
        return myans ;   
    }
};
