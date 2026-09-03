#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        int r=a.length(),c=b.length();
        vector<int>mx(r),my(c);
        mx[0]=a[0]-'0';
        my[0]=b[0]-'0';
        for(int j=1;j<r;j++){
            mx[j]=(mx[j-1]+(a[j]-'0'))%10;
        }
        for(int j=1;j<c;j++){
            my[j]=(my[j-1]+(b[j]-'0'))%10;
        }
        if(mx[r-1]!=my[c-1]){
            arr[i]=-1;
            continue;
        }
        vector<vector<int>>dp(r+1,vector<int>(c+1,0));
        for(int j=1;j<=r;j++){
            for(int k=1;k<=c;k++){
                if(mx[j-1]==my[k-1]){
                    dp[j][k]=1+dp[j-1][k-1];
                }
                else{
                    dp[j][k]=max(dp[j-1][k],dp[j][k-1]);
                }
            }
        }
        arr[i]=dp[r][c];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}