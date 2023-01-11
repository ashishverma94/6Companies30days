class Solution {
    void fun( long long num, long long den, string &ans )
    {
        map<long long, long long> mymap ;
        while( num != 0 )
        {
            if ( mymap[num] )
            {
                long long pos = mymap[num] ;
                ans = ans.substr(0,pos)+"("+ans.substr(pos)+")" ;
                return ;
            }
            else
            {
                mymap[num] = ans.size() ;
                num *= 10 ;
                long long q = num/den ;
                num = num%den ;
                ans += to_string(q) ;
            }
        }
    }
public:
    string fractionToDecimal(int num, int den) {
        long long x = (1LL*num)%(1LL*den) ;
        long long y = (1LL*num)/(1LL*den) ;
        if ( x == 0 ) 
            return to_string(y) ;

        bool sign = true ;
        if ( num >= 0 and den >= 0 || num <= 0 and den <= 0 ) sign = false ;
        num = abs(num) ;
        den = abs(den) ;

        string ans = "" ;
        if ( sign )  ans += "-" ;

        ans += to_string(num/den) +"." ;
        num = num%den ;
        fun( num, den, ans ) ;
        return ans ;
    }
};
