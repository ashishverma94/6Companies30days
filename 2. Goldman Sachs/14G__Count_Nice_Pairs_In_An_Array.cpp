class Solution {
    int mod = 1e9+7 ;
    long long dorev( long long n )
    {
        long long ans = 0;
        while( n > 0 )
        {
            ans = ans*10 + n%10 ;
            n = n/10 ;
        }

        return ans ;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), ans = 0 ;
        vector<long long> rev(n) ;
        for ( int i = 0; i < n; i++ )
            rev[i] = dorev(nums[i]) ;

        map<long long,long long> mymap ;
        for ( int i = 0; i < n; i++ )
            mymap[(nums[i]-rev[i])] ++;
        
        for ( auto i : mymap )
            ans = ( ans + (i.second*(i.second-1))/2)%mod ;
        return ans%mod ;
    }
};
