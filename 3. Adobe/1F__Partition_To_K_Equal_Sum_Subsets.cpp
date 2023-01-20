class Solution {
    bool helper( int i, int bucketNum, int bucketSum, int reqSum, int k, vector<int> &nums, vector<bool> &alreadyPicked ){

        if ( bucketNum == k+1 ) return true ;
        if ( bucketSum == reqSum ){
            return helper( 0, bucketNum+1, 0, reqSum, k, nums, alreadyPicked ) ;
        }
        if ( bucketSum > reqSum )  return false ;
        if ( i >= nums.size() )    return false ;
        if ( alreadyPicked[i] == true ){
            return helper( i+1, bucketNum, bucketSum, reqSum, k, nums, alreadyPicked ) ;
        }else{
            bucketSum += nums[i];
            alreadyPicked[i] = 1;
            bool option1 = helper(i+1, bucketNum, bucketSum, reqSum, k, nums, alreadyPicked ) ;
            bucketSum -= nums[i];
            alreadyPicked[i] = 0;
            bool option2 = helper(i+1, bucketNum, bucketSum, reqSum, k, nums, alreadyPicked ) ;

            return option1 | option2 ;
        } 
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       
        int tot = 0, n = nums.size() ;
        for ( auto i : nums ) tot += i ;
        if ( tot % k != 0 ) return false ;
        if ( nums.size() < k ) return false ;

        vector<bool> alreadyPicked(nums.size(),0) ;
        sort(nums.begin(),nums.end()) ;
        return helper( 0, 1, 0, tot/k, k, nums, alreadyPicked ) ;
    }
};
