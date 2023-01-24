class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left, right, max_picked= 0, n = fruits.size() ;
        unordered_map<int,int> basket ;
        for ( left = 0, right = 0; right < n; ++right ){
            basket[fruits[right]]++;
            if ( basket.size() > 2 ){
                basket[fruits[left]]--;
                if ( basket[fruits[left]] == 0 )
                    basket.erase(fruits[left]) ;
                left++ ;
            }
        }
        return right-left ;
    }
};
