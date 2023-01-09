class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0 ;
        for ( int i = 0 ; i < points.size() ; i++ )
        {
            map<int,int> distances ;
            for ( int j = 0 ; j < points.size(); j++ )
            {
                int xx = (points[i][0]-points[j][0]) ;
                int yy = (points[i][1]-points[j][1]) ;
                int dis1 = xx*xx + yy*yy ;
                distances[dis1]++;
            }

            for ( auto i : distances )
            {
                if ( i.second )
                {
                    ans += i.second*(i.second-1) ;
                }
            }
        }

        return ans ;
    }
};
