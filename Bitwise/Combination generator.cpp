#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=1;i<(1<<len);i++){
        string comb="";
        for(int j=0;j<len;j++){
            if((i&(1<<j))>0){
                comb+=s[j];
            }
        }
        cout<<comb<<endl;
    }
    return 0;
}