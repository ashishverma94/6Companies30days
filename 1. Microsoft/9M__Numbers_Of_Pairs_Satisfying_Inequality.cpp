typedef long long int ll ;
class Solution {
    ll ans = 0 ;
    void validPairs( int left, int mid, int right, vector<int> &nums, int diff )
    {
        int l = left, r = mid+1 ;
        while( l <= mid and r <= right )
        {
            if ( nums[l] <= nums[r] + diff )
            {
                ans += right-r+1;
                l++;
            }
            else r++;
        }

        vector<int> dup;
        for ( int i = left; i <= right ; i++ )
            dup.push_back(nums[i]) ;
        sort(dup.begin(),dup.end()) ;
        
        int k = 0 ;
        for ( int i = left; i <= right ; i++ )
            nums[i] = dup[k++] ;
    }
    void mergeSort( int left, int right, vector<int> &nums, int diff )
    {
        if ( left == right ) return ;

        int mid = (left+right)>>1 ;
        mergeSort( left, mid, nums, diff ) ;
        mergeSort( mid+1, right, nums, diff ) ;  

        validPairs( left, mid, right, nums, diff ) ; 
    }


public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size() ;
        ans = 0 ;
        vector<int> nums ;
        for ( int i = 0; i < n; i++ )
            nums.push_back(nums1[i]-nums2[i]) ;
        
        mergeSort( 0, n-1, nums, diff );
        return ans ;
    }
};
