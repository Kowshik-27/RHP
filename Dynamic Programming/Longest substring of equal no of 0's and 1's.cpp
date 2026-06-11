#include <iostream>
#include <map>
using namespace std;

int main() {
    string str;
    cout<<"Enter a string of 0's and 1's: ";
    cin>>str;
    map<int,int> m;
    int sum=0,len=0;
    m[sum]=-1;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            sum-=1;
        }
        else{
            sum+=1;
        }
        if(m.find(sum)!=m.end()){
            len=max(len,i-m[sum]);
        }
        else{
            m[sum]=i;
        }
    }
    cout<<"Length of longest substring containing equal no of 0's and 1's: "<<len<<endl;
    return 0;
}