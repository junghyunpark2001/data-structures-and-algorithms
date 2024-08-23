#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int n,m;

int main(void){
    cin>>n>>m;
    for(int i=1;i<=n;i++) fill(d[i],d[i]+1+n,INF);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        // INF를 c로 업ㅇㅇㅇ데이트
        d[a][b] = min(d[a][b], c);
    }
    // i에서 i로 가는 가중치 0으로 업데이트
    for(int i=1;i<=n;i++) d[i][i] = 0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==INF) cout<<"0 ";
            else cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }

}