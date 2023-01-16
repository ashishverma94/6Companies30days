class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0) ;
        for ( auto i : s ) freq[i-'a']++;
        string ans = "";
        for ( auto i : order )
            while(freq[i-'a']-- > 0 )  ans += i;
   
        for ( char i = 'a' ; i <= 'z' ; i++ )
            while(freq[i-'a']-- > 0 )  ans += i;
        return ans ;
    }
};
