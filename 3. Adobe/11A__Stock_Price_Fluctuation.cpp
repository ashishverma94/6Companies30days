class StockPrice {
    map<int,int> time_price, price_freq ;
    priority_queue<int> mx_heap;
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    int curr = 0 , maxtime = 0 ;

public:
    StockPrice() {
        
    }
    
    void update(int time, int price ) {
        if ( time_price.find(time) != time_price.end())
        {
            price_freq[time_price[time]]--;
            while(!mx_heap.empty() and price_freq[mx_heap.top()] == 0 )
                mx_heap.pop() ;
            
            while(!mn_heap.empty() and price_freq[mn_heap.top()] == 0 )
                mn_heap.pop() ;
        }

        time_price[time] = price ;

        mx_heap.push(price) ;
        mn_heap.push(price) ;
        price_freq[price]++;
        
        if ( time >= maxtime)
        {
            maxtime = time ;
            curr = price ;
        }      
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        return mx_heap.top() ;
    }
    
    int minimum() {
        return mn_heap.top() ;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
