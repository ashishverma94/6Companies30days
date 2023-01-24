class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        int ans = -1 ;
        s.push_back(bottom-1);
        s.push_back(top+1) ;
        sort(s.begin() , s.end()) ;
        for ( int i = 1 ; i < s.size() ; i ++ ){
            ans = max( ans , s[i] - s[i-1] -1 ) ;
        }
        return ans ;
    }
};
