class Solution {
public:
    int dfs(vector<vector<int>>&matrix, vector<vector<int>> &dp,int i,int j,int row,int col){
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int diff[][2]={{0,-1},{-1,0},{0,1},{1,0}};
        int m=0;
        for(int k=0;k<4;k++){
            int ar=i+diff[k][0];
            int ac=j+diff[k][1];
            if(ar>=0 && ar<row && ac>=0 && ac<col && matrix[ar][ac]>matrix[i][j]){
                m=max(m,dfs(matrix,dp,ar,ac,row,col));
            }
        }
        return dp[i][j]=1+m;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        int longest=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dp[i][j]==0){
                    longest=max(longest,dfs(matrix,dp,i,j,row,col));
                }
            }
        }
        return longest;
    }
};
