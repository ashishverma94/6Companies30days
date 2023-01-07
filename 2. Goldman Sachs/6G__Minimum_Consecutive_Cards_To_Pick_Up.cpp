class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), ans = INT_MAX ;

        map<int,int> mymap ;
        for ( int i = 0 ; i < n; i++ )
        {
            if ( mymap.find(cards[i])==mymap.end())
            {
                mymap[cards[i]] = i;
            }
            else
            {
                ans = min(ans, i-mymap[cards[i]]+1) ;
                mymap[cards[i]] = i ;
            }
        }

        return ans== INT_MAX ? -1 : ans ;
    }
};
