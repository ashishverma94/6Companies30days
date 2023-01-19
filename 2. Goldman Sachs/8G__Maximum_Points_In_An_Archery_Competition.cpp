class Solution {
public:
    bool isMaskPossible( vector<int> &alice, int arrows, string &mask ){
        int newArrow = 0;
        for ( int i = 11; i > 0; i-- ){
            if ( mask[i] == '1' ){
                newArrow += alice[i]+1 ;
            }
        }
        return newArrow <= arrows ;
    }

    int calculatePoint( string &mask ){
        int ans = 0;
        for ( int i = 0; i < 12; i++ ){
            if ( mask[i] == '1' ) ans += i;
        }
        return ans ;
    }

    vector<int> maximumBobPoints(int arrows, vector<int>& alice) {
        int score = 0, N = 4096 ;
        string original_mask ;
        for ( int i = 1; i < N; i++ ){
            string mask = bitset<12> (i).to_string();
            if ( isMaskPossible(alice, arrows, mask )) {
                int newPoint = calculatePoint( mask ) ;
                if ( newPoint > score ){
                    score = newPoint ;
                    original_mask = mask ;
                }
            }
        }

        vector<int> ans(12,0) ;
        for ( int i = 1; i < 12; i++ ){
            if ( original_mask[i] == '1' ) {
                ans[i] = alice[i] + 1 ;
                arrows -= ans[i] ;
            }
        }

        ans[0] = arrows ;
        return ans ;
    }
};
