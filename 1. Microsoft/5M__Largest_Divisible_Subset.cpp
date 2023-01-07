class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = size(arr), maxi = 1, lastIndex = 0 ;
		vector<int> dp(n,1), hash(n) ;

        for ( int i = 0 ; i < n ; i++ )
        {
            hash[i] = i ;
            for ( int prev = 0 ; prev < i ; prev ++ )
            {
                if ( arr[i] % arr[prev] == 0 and 1+dp[prev] > dp[i] )
                {
                    dp[i] = 1+dp[prev] ;
                    hash[i] = prev;
                }
            }

            if ( dp[i] > maxi )
            {
                maxi = dp[i] ;
                lastIndex = i ;
            }
        }

        vector<int> ans ;
        ans.push_back(arr[lastIndex]) ;
        while(hash[lastIndex] != lastIndex )
        {
            lastIndex = hash[lastIndex] ;
            ans.push_back(arr[lastIndex]) ;
        }

        return ans ;
    }
};
