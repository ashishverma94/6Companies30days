class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort( piles.rbegin(), piles.rend()) ;
        int n = piles.size();
        int ans = 0, k = 0;
        for ( int i = 1; i <n; i+=2 ){
            ans += piles[i];
            k++ ;
            if ( k == n/3 ) break;
        }
        return ans ;
    }
};
