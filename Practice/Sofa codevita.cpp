#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'0')),g(n,vector<char>(m));
    int st[2][2];
    int t=0,step=0;
    bool fnd=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='s'){
                st[t][0]=i;
                st[t][1]=j;
                t++;
            }
            if(g[i][j]=='H'){
                grid[i][j]='H';
            }
        }
    }
    queue<tuple<int,int,int,int>> q;
    q.push({st[0][0],st[0][1],st[1][0],st[1][1]});
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto[fr,fc,sr,sc]=q.front();
            q.pop();
            if(g[fr][fc]=='S' && g[sr][sc]=='S'){
                fnd=true;
                break;
            }
            grid[fr][fc]=step;
            grid[sr][sc]=step;
            int diff[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
            for(int i=0;i<4;i++){
                int far=diff[i][0]+fr,fac=diff[i][1]+fc;
                int sar=diff[i][0]+sr,sac=diff[i][1]+sc;
                if(far<n && far>=0 && sar<n && sar>=0 && fac<m && fac>=0 && sac<m && sac>=0
                    && (grid[far][fac]=='0' || grid[sar][sac]=='0') && grid[far][fac]!='H' && grid[sar][sac]!='H'){
                        q.push({far,fac,sar,sac});
                }
            }
            int rot[2]={1,-1};    
            for(int i=0;i<2;i++){
                int e1=fr+rot[i],e2=sr+rot[i];
                int e3=fc+rot[i],e4=sc+rot[i];
                if(fr==sr && e1>=0 && e1<n && e2>=0 && e2<n && grid[e1][fc]=='0' && grid[e2][sc]=='0'){
                    q.push({fr,fc,e1,fc});
                    q.push({e2,sc,sr,sc});
                }
                if(fr!=sr && e3>=0 && e3<m && e4>=0 && e4<m && grid[fr][e3]=='0' && grid[sr][e4]=='0'){
                    q.push({fr,fc,fr,e3});
                    q.push({sr,e4,sr,sc});
                }
            }
        }
        if(fnd)break;
        step++;
    }
    if(fnd)cout<<step<<endl;
    else cout<<"Impossible"<<step<<endl;
}