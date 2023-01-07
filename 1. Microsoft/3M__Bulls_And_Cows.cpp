class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0 , cows = 0 ;
        unordered_map<char,int> mysec,myguess ;
        for ( int i = 0 ; i < guess.size() ; i++ )
        {
            if ( secret[i] == guess[i] )
            {
                bulls ++ ;
            }
            mysec[secret[i]]++;
            myguess[guess[i]]++;
        }

        for ( auto i : mysec )
        {
            int s = i.second ;
            int g = myguess[i.first];
            cows += min(s,g) ;
        }

        string ans =""+ to_string(bulls)+"A"+to_string(cows-bulls)+"B" ;
        return ans ;
    }
};
