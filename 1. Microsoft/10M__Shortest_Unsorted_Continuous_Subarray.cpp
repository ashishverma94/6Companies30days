class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), amin = INT_MAX, amax = INT_MIN;
        if ( n == 1 ) return 0 ;
        
        for ( int i = 0; i < n; i++ )
        {
            if ( i == 0 ) 
            {
                if ( nums[i] > nums[i+1])
                {
                    amin = min( amin, nums[i] ) ;
                    amax = max( amax, nums[i] ) ;
                }
            }

            else if ( i == n-1 )
            {
                if ( nums[i-1] > nums[i])
                {
                    amin = min( amin, nums[i] ) ;
                    amax = max( amax, nums[i] ) ;
                }
            }

            else 
            {
                if ( nums[i] > nums[i+1] || nums[i-1] > nums[i] )
                {
                    amin = min( amin, nums[i] ) ;
                    amax = max( amax, nums[i] ) ;
                }
            }
        }

        if ( amin == INT_MAX || amax == INT_MIN )
            return 0 ;

        cout<<amax<<" "<<amin ;

        int i =0, j=n-1 ;

        for ( i = 0 ; i < n && nums[i] <= amin ; i++ ) ;
        for ( j = n-1 ; j >= 0 && nums[j] >= amax ; j-- );
        cout<<endl<<i<<" "<<j;

        return j-i+1; 
    }
};
