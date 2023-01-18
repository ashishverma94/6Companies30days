class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,int> mymap ;
        
        int n = s.size() , nn = s.size() - k +1;
        
        for ( int i = 0 ; i < nn ; i ++ )
            mymap[s.substr(i,k)]++ ;
        
        return ( mymap.size() == pow(2,k) ) ? true : false ;    
        
    }
};
