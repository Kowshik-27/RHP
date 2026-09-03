#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<long long> arr(m+1);
        long long b=0;
        bool p=true;
        for(int j=1;j<=m;j++){
            cin>>arr[j];
        }
        for(int j=1;j<=m;j++){
            if(arr[j]>j){
                b+=arr[j]-j;
            }
            else if(arr[j]<j){
                int need=j-arr[j];
                if(need>b){
                    p=false;
                    break;
                }
                b-=need;
            }
        }
        if(p){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}