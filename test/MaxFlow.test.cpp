#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include "../graph/MaxFlow.cpp"

int main(){
    ll V,E;cin>>V>>E;
    Dinic F(V);
    rep(i,E){
        int u,v,c;cin>>u>>v>>c;
        F.addEdge(u,v,c);
    }
    cout<<F.maxFlow(0,V-1)<<"\n";
}