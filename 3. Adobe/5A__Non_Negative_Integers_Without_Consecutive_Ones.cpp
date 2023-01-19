class Solution {
public:
    int findIntegers(int n) {
        int fib[31] ;
        fib[0] = 1;
        fib[1] = 2;
        for ( int i = 2; i < 31; i++ )
            fib[i] = fib[i-1] + fib[i-2] ;

        int ans = 0, pbit = 0 , count = 30 ;
        while( count >= 0)
        {
            int x = 1 << count ;
            if ( x&n )
            {
                ans += fib[count] ;
                if ( pbit ) return ans ;
                pbit = 1 ;
            }
            else
                pbit = 0 ;
            count--;
        }

        return ans +1 ;
    }
};
