class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size(), col = mat[0].size();
        for ( int i = 1; i < row; i++ ){
            mat[i][0] += mat[i-1][0] ;
        }
        for ( int i= 1; i < col; i++ ){
            mat[0][i] += mat[0][i-1] ;
        }
        for ( int i = 1; i < row; i++ ){
            for ( int j = 1; j < col ;j++ ){
                mat[i][j] = mat[i][j]-mat[i-1][j-1]+mat[i-1][j]+mat[i][j-1] ;
            }
        }

        vector<vector<int>> res(row, vector<int>(col,0)) ;
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < col; j++ ){
                int xbottom = min(row-1, i+k ), ybottom = min( j+k, col-1 ) ;
                int xtop = i-k-1, ytop = j-k-1 ;
                int ans = mat[xbottom][ybottom] ;
                if ( xtop >= 0 )
                    ans -= mat[xtop][ybottom] ;
                if ( ytop >= 0 )
                    ans -= mat[xbottom][ytop] ;
                if ( xtop >= 0 and ytop >= 0 )
                    ans += mat[xtop][ytop] ;
                res[i][j] = ans ;
            }
        }
        return res ;
    }
};
