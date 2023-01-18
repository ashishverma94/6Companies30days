class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size() ;
        map<int,int> mymap ;
        for ( auto i : barcodes )
            mymap[i]++ ;

        priority_queue<pair<int,int>> maxHeap ;
        for ( auto i : mymap ) maxHeap.push({i.second,i.first}) ;

        int index = 0;
        while(maxHeap.size() > 0 ){
            auto a = maxHeap.top() ;
            maxHeap.pop() ;
            barcodes[index++] = a.second;
            if ( maxHeap.size() == 0 ) break;
            auto b = maxHeap.top() ;
            maxHeap.pop() ;
            barcodes[index++] = b.second;

            a.first--;
            b.first--;

            if ( a.first > 0 )
                maxHeap.push(a) ;
            if ( b.first > 0 )
                maxHeap.push(b) ;
        }
        return barcodes ;
    }
};
