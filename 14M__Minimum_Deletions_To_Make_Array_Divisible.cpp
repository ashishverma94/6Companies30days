class Solution {
public:
    int gcd(int a, int b)
    {
      if (a == 0)
        return b;
      return gcd(b % a, a);
    }

    int gcd_arr(vector<int> arr)
    {
      int n = arr.size() ;
      int result = arr[0];
      for (int i = 1; i < n; i++)
      {
        result = gcd(arr[i], result);
        if(result == 1)
            return 1;
      }
          return result;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int mygcd = gcd_arr(numsDivide) ;
        
        int ans = 0 ;
        cout<<mygcd;
        for ( auto i : nums )
        {
            if ( mygcd%i == 0 )
                break;
            else
            {
                ans++;
            }
        }
        
        if ( ans == nums.size()) 
            return -1 ;
        return ans ;
    }
};
