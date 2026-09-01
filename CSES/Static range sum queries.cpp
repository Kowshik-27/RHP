#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        cout<<arr[e]-arr[s-1]<<endl;
    }
}
