class Solution {
public:
    int recur( int n, int k ){
        if ( n == 1 ) return 0 ;
        return ( recur( n-1, k) + k ) % n ;
    }
    int findTheWinner(int n, int k) {
        return recur(n,k)+1 ;
    }
};
