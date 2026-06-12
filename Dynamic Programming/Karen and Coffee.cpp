#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k,q;
    cin>>n>>k>>q;
    int max=200000;
    vector<int> diff(max+2,0);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        diff[l]++;
        diff[r+1]--;
    }
    vector<int> count(max+1,0);
    for(int i=1;i<=max;i++){
        count[i]=count[i-1]+diff[i];
    }
    vector<int> prefix(max+1,0);
    for(int i=1;i<max;i++){
        prefix[i]=prefix[i-1]+(count[i]>=k);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
    return 0;
}