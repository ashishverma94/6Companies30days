class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st ;

        for ( auto i : tokens )
        {
            if ( i == "+" )
            {
                long long x = stol(st.top()) ;
                st.pop() ;
                long long y = stol(st.top()) ;
                st.pop() ;
                long long z = x+y ;
                st.push(to_string(z)) ;
            }
            else if ( i == "-" )
            {
                long long x = stol(st.top()) ;
                st.pop() ;
                long long y = stol(st.top()) ;
                st.pop() ;
                long long z = y-x ;
                st.push(to_string(z)) ;
            }
            else if ( i == "*" )
            {
                long long x = stol(st.top()) ;
                st.pop() ;
                long long y = stol(st.top()) ;
                st.pop() ;
                long long z = x*y ;
                st.push(to_string(z)) ;
            }
            else if ( i == "/" )
            {
                long long x = stol(st.top()) ;
                st.pop() ;
                long long y = stol(st.top()) ;
                st.pop() ;
                long long z = y/x ;
                st.push(to_string(z)) ;
            }
            else
                st.push(i) ;
        }

        int  zz = stol(st.top()) ;
        return zz ;
    }
};
