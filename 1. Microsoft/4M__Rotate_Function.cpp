class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0 , f0 = 0 , n = nums.size() ;
        for ( int i = 0 ; i < n ; i++ )
        {
            sum += nums[i] ;
            f0 += nums[i]*i ;
        }

        vector<int> dp(n,0) ;
        dp[0] = f0;
        int ans = dp[0] ;

        for ( int i = 1 ; i < n ; i++ )
        {
            dp[i] = dp[i-1] + sum- n*nums[n-i] ;
            ans = max(ans,dp[i]) ; 
        }

        return ans ;
    }
};
