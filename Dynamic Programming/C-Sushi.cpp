#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int m,n;
  cin>>m>>n;
  int fa[m],sa[n];
  for(int i=0;i<m;i++){
    cin>>fa[i];
  }
  for(int i=0;i<n;i++){
    cin>>sa[i];
  }
  sort(fa,fa+m);
  sort(sa,sa+n);
  int count=0;
  for(int i=m-1,j=n-1;i>=0 && j>=0;j--){
    if(fa[i]*2>=sa[j]){
      count++;
      i--;
    }
  }
  cout<<count<<endl;
}