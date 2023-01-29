class Solution {
public:
    int helper( string s, set<string> &myset ){
        int maxx = 0;
        for ( int i = 1; i <= s.size(); i++ ){
            if ( myset.find(s.substr(0,i)) == myset.end()){
                string dup = s.substr(0,i) ;
                myset.insert(dup) ;
                maxx = max( maxx, 1+helper(s.substr(i),myset )) ;
                myset.erase(dup) ;
            }
        }
        return maxx ;
    }
    int maxUniqueSplit(string s) {
        set<string> myset ;
        return helper(s, myset ) ;
    }
};
