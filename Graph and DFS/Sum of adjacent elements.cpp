#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row,col,sum=0;
    cout<<"Enter no of rows and columns in the grid: ";
    cin>>row>>col;
    vector<vector<int>> grid(row,vector<int>(col));
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>grid[i][j];
        }
    }
    int m,n;
    cout<<"Enter element index to find the sum of adjacent elements: ";
    cin>>m>>n;
    int diff[][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    for(int i=0;i<8;i++){
        int ar=m+diff[i][0];
        int ac=n+diff[i][1];
        if(ar>=0&&ar<row&&ac>=0&&ac<col){
            sum+=grid[ar][ac];
        }
    }
    cout<<"Sum: "<<sum<<endl;
    return 0;
}