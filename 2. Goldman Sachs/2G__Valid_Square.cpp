class Solution {
    int f( vector<int> & a, vector<int>& b )
    {
        return (a[0]-b[0])*(a[0]-b[0])+ (a[1]-b[1])*(a[1]-b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> myset = { f(p1,p2), f(p1,p3), f(p1,p4), 
                           f(p2,p1), f(p2,p3), f(p2,p4),
                           f(p3,p1), f(p3,p2), f(p3,p4),
                           f(p4,p1), f(p4,p2), f(p4,p3)};
        
        if ( myset.size() == 2 and myset.count(0) == 0 ) return true ;
        else return false ;
    }
};
