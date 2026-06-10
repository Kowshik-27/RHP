#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str1,str2;
    int m=0;
    cout<<"Enter the string values: ";
    cin>>str1>>str2;
    int n1=str1.length();
    int n2=str2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                m=max(m,dp[i][j]);
            }
        }
    }
    cout<<"Length of longest common substring: "<<m<<endl;
    return 0;
}