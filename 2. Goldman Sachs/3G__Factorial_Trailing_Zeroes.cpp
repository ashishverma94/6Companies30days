class Solution {
public:
    int trailingZeroes(int n) {
        int five = 5, ans = 0 ;
        while( n >= five )
        {
            ans += n/five;
            five *= 5;
        }

        return ans ;
    }
};
