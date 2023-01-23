class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(2005,0) ;
        dp[1] = 1;
        int mod = 1e9+7 ;
        for ( int i = 1; i <= n; i++ )
            for ( int j = i+delay; j < i+forget; j++ )
                dp[j] = ( dp[j] + dp[i] )%mod ;

        int ans = 0, i = 0 ;
        while( forget-- ){
            ans = (ans + dp[n-i] )%mod ;
            i++ ;
        }
        return ans ;
    }
};
