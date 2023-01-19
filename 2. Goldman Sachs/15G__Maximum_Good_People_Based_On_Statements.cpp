class Solution {
    int n;

    int apply( vector<int>& roles, int mask ){
        int count = 0;
        for ( int i = 0; i < n; i++ ){
            count += roles[i] = mask & 1;
            mask >>= 1 ;
        }
        return count ;
    }

    bool valid( vector<int>& roles, vector<vector<int>>& statements ){
        for ( int i = 0; i < n; i++ ){
            if ( roles[i] == 0 ) continue ;
            for ( int j = 0; j < n; j++ ){
                if ( statements[i][j] == 2 ) continue ;
                if ( statements[i][j] != roles[j] ) return false ;
            }
        }
        return true ;
    }

public:
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        int goodPersons = 0, combos = 1<<n ;
        vector<int> roles(n,0);
        for ( int mask = 0; mask < combos; mask++ ){
            int cgp = apply( roles, mask ) ;
            if ( valid( roles, statements ))
                goodPersons = max( goodPersons, cgp ) ;
        }
        return goodPersons ;
    }
};

