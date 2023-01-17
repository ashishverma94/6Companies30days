const int N = 1000005 ;
vector<bool> isPrime(N,true) ;
vector<int> primes ;

void markPrime()
{
	for ( int i = 2 ; i< N ; i++ )
	{
		if ( isPrime[i])
		{
			for ( int j = 2*i ; j < N ; j += i)
				isPrime[j] = false ;
		}
	}
}

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        markPrime() ;
        
        for ( int i = 2 ; i < N ; i++ )
            if ( isPrime[i] == true )
                primes.push_back(i) ;
        
        vector<int> ans = {-1,-1} ;
        int gap = INT_MAX ;
        for ( int i = 0  ; i < primes.size()-1 ; i++ )
        {
            if ( primes[i] >= left and primes[i] <right )
            {
                if ( primes[i+1]-primes[i] < gap )
                {
                    gap = primes[i+1]-primes[i] ;
                    ans[0] = primes[i] ;
                    ans[1] = primes[i+1] ;
                }
            }
            
        }

        if ( left <= ans[0] and ans[0] < ans[1] and ans[1] <= right)
            return ans ;
        else
            return {-1,-1} ;
    }
};
