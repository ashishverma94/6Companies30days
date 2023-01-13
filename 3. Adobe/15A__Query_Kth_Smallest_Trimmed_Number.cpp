vector<int> ans ;
int i = 0 , sz ;
vector<pair<string,int>> trimmed ;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        ans.clear() ;
        int n = nums.size() ;
        for ( auto p : queries )
        {            
            trimmed.clear() ;
            
            for ( i = 0 ; i < n ; i ++ )
            {
                sz = nums[i].size() ;
                sz = sz-p[1] ;
                trimmed.push_back({nums[i].substr(sz),i} ) ;
            }
      
            sort(trimmed.begin(),trimmed.end()) ;
            ans.push_back(trimmed[p[0]-1].second) ;
        }
        
        return ans ;
    }
};
