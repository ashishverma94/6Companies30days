class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , n = s.size(), ans = 0 ;
        vector<int> dp(3,0) ;
        for ( int right = 0 ; right < n; right++ )
        {
            dp[s[right]-'a']++;
            while( dp[0]>0 and dp[1]>0 and dp[2]>0 and left < right)
            {
                dp[s[left++]-'a']--;
                ans += n-right;
            }
        }
        return ans ;
    }
};
