class Solution {
    int ans = 0 ;
    
    int helper ( int s , int e , int curr, int k, vector<vector<int>>& dp ){
        if ( k == 0 ){
            if ( curr == e ) return 1 ;
            else return 0 ;
        }
        if ( dp[curr+1001][k] != -1 )
            return dp[curr+1001][k] ;
        
        int rightmove = helper( s,e,curr+1,k-1,dp)%1000000007;
        int leftmove  = helper( s,e,curr-1,k-1,dp)%1000000007;
        return dp[curr+1001][k] = (rightmove+leftmove)%1000000007 ;
    }
public:
    int numberOfWays(int sp, int ep, int k) {
        vector<vector<int>> dp ( 3002, vector<int>(1001,-1)) ;
        return helper( sp , ep , sp, k, dp) ;
    }

};
