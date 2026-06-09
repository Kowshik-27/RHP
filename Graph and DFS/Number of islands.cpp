class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j,int row,int col){
        grid[i][j]='0';
        int diff[][2]={{-1,0},{0,1},{1,0},{0,-1}};
        for(int k=0;k<4;k++){
            int ar=i+diff[k][0];
            int ac=j+diff[k][1];
            if(ar>=0 && ar<row && ac>=0 && ac<col && grid[ar][ac]=='1'){
                dfs(grid,ar,ac,row,col);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int num=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    num++;
                    dfs(grid,i,j,row,col);
                }
            }
        }
        return num;
    }
};