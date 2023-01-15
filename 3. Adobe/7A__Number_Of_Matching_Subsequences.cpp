class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> freqIndex;
        for ( int i = 0; i < s.size(); i++ ) freqIndex[s[i]].push_back(i) ;

        int ans = 0;
        for ( auto word : words ){
            bool subseq = true ;
            int lastIndex = -1 ;
            for ( int i = 0; i < word.size() ; i++ ){
                auto x = upper_bound(freqIndex[word[i]].begin(), freqIndex[word[i]].end(),lastIndex) ;
                if ( x == freqIndex[word[i]].end()){
                    subseq = false ;
                    break;
                }
                else
                    lastIndex = *x ;
            }
            if ( subseq ) ans ++ ;
        }
        return ans ;
    }
};
