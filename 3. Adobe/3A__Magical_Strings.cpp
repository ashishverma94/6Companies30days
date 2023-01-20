class Solution {
public:
    int magicalString(int n) {
        string s = "122" ;
        int finish = 2, backend = 2 ;

        while( finish < n ){
            if ( s[backend] == '1' ){
                if ( s[finish] == '1' )
                    s += '2' ;
                else
                    s += '1' ;
                finish++;
            }
            else{
                if ( s[finish] == '1' )
                    s += "22" ;
                else
                    s += "11" ;
                finish += 2;
            }
            backend ++ ;
        }

        int ans = 0;
        for (int i = 0; i < n; i++ ) if ( s[i] == '1' ) ans ++ ;
        return ans ;
    }
};
