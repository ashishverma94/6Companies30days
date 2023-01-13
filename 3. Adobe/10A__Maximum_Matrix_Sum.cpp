class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long tot = 0 ;
        int n = matrix.size(), matmin = INT_MAX , neg = 0;

        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                if ( matrix[i][j] < 0 ) neg++;
                tot += abs(matrix[i][j]) ;
                matmin = min( abs(matrix[i][j]) , matmin ) ;
            }
        }
        if ( neg %2 == 0 )
            return tot ;
        else
            return tot - 2*matmin ;
    }
};
