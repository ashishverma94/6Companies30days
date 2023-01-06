class Solution {
public:
    string longestPrefix(string s) {
        
        int n = s.size(), j = 0 ;
        vector<int> dp(n,0) ;
        for ( int i = 1; i < n; i++ )
        {
            if ( s[i] == s[j] ) dp[i] = ++j;
            else if ( j > 0 )
            {
                j = dp[j-1];
                i--;
            }
        }

        return s.substr(0,j) ;
    }
};
