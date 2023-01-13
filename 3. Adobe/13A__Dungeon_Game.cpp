class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        
        vector<vector<int>> ans(row, vector<int>(col));
        ans [row-1][col-1] = dungeon[row-1][col-1]>0?1:1-dungeon[row-1][col-1];
        
        for( int i = row-2;i>=0;i--)
            ans[i][col-1]=max(ans[i+1][col-1]-dungeon[i][col-1],1);
        
        for( int j = col-2;j>=0;j--)
            ans[row-1][j]=max(ans[row-1][j+1]-dungeon[row-1][j],1);
        
        for( int i = row-2;i>=0;i--)
            for( int j = col-2;j>=0;j--)
                ans[i][j] = max(min(ans[i+1][j],ans[i][j+1])-dungeon[i][j],1);
        return ans[0][0];
    }
};
