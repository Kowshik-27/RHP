#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int a=arr[0],b=arr[n-1];
        while(b){
            int x=b;
            b=a%b;
            a=x;
        }
        cout<<a<<endl;
    }
}