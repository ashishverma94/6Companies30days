class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> original;
        for ( int i = 0; i < nums.size(); i++ ){
            int count =0;
            string sb = "" ;
            for ( int j = i; j < nums.size(); j++ ){
                if ( nums[j]%p== 0 ) count++;
                if ( count > k ) break;
                sb += "-"+to_string(nums[j]) ;
                original.insert(sb) ;
            }
        }
        return original.size() ;
    }
};
