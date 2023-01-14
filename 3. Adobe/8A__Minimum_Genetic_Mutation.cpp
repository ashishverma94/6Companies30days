class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> bankset(bank.begin(),bank.end()), visited ;
        int ans = 0;
        string letters = "ACGT" ;

        queue<string > edges ;
        edges.push(startGene) ;

        while( !edges.empty())
        {
            ans ++;
            int n = edges.size() ;
            for ( int k = 0; k < n ; k++ )
            {
                string parent = edges.front() ;
                edges.pop() ;
                visited.insert(parent) ;

                for ( int i = 0; i < 8; i++ )
                {
                    string dup = parent;
                    for ( int j = 0; j <4; j++ )
                    {
                        dup[i] = letters[j] ;
                        if ( bankset.find(dup) != bankset.end() and visited.find(dup) == visited.end())
                            edges.push(dup) ;
                            
                        if ( bankset.find(dup) != bankset.end() and dup == endGene ) 
                            return ans ;
                    }
                }
            }
        }
        return -1 ;  
    }
};
