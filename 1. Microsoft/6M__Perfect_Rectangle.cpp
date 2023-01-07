class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rect) {
        map<pair<int,int>,int> mymap;
        for ( auto i : rect )
        {
            mymap[{i[0],i[1]}]++;
            mymap[{i[2],i[3]}]++;
            mymap[{i[0],i[3]}]--;
            mymap[{i[2],i[1]}]--;
        }

        int corners = 0 ;
        for ( auto i : mymap )
        {
            if ( i.second )
            {
                if ( abs(i.second) !=  1 ) return false ;
                corners++;
            }
        }

        return corners == 4 ;
    }
};
