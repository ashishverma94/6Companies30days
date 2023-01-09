class Solution {
public:
    bool isPossible(vector<int>& nums) {

        map<int,int> vmap,amap;
        for ( auto i : nums ) amap[i]++;

        for ( auto i : nums )
        {
            if ( amap[i] == 0 ) continue ;
            if ( vmap[i] > 0 )
            {
                amap[i]--;
                vmap[i+1]++;
                vmap[i]--;
            }
            else
            {
                if ( amap[i] and amap[i+1] and amap[i+2] )
                {
                    amap[i]--;
                    amap[i+1]-- ;
                    amap[i+2]--;
                    vmap[i+3]++;
                }
                else
                    return false ;
            }
        }

        return true ;
    }
};
