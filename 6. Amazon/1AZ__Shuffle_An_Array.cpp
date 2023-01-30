class Solution {
    vector<int> original;
    int n ;
public:
    Solution(vector<int>& nums) {
        n = nums.size() ;
        original = nums ;
    }
    
    vector<int> reset() {
        return original ;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = original ;
        int right = n ;
        for ( int i = n-1 ; i >= 0 ; i-- ){
            int j = rand()%right ;
            swap( shuffled[i],shuffled[j]) ;
            right-- ;
        }
        return shuffled ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
