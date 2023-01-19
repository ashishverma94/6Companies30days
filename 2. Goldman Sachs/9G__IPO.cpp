class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> pvec;
        for ( int i = 0; i < capital.size(); i++ ){
            pvec.push_back({capital[i],profits[i]}) ;
        }
        sort(pvec.begin(),pvec.end()) ;
        int p = 0;
        for ( int i = 0; i < k ;i++ ){
            while( p < profits.size() and pvec[p].first <= w ){
                pq.push(pvec[p++].second) ;
            }
            if ( pq.size() > 0 ){
                w += pq.top() ;
                pq.pop() ;
            }
        }
        return w ;
    }
};
