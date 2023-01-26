class Solution {
    vector<int> csum ;
    int n ;
public:
    Solution(vector<int>& w) {
        n = w.size();
        csum.resize(n) ;
        csum[0] = w[0] ;
        for ( int i = 1; i < n; i++ ) csum[i] = csum[i-1]+ w[i] ;
    }
    
    int pickIndex() {
        int randWeight = rand()%csum[n-1] ;
        return upper_bound( csum.begin(), csum.end(), randWeight )- csum.begin() ;  
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
