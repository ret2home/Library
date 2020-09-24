#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#include "../graph/MinCostFlow.cpp"
int main(){
    ll V,E,F;
    cin>>V>>E>>F;
    PrimalDual FL(V);
    rep(i,E){
        int u,v,c,d;cin>>u>>v>>c>>d;
        FL.add_edge(u,v,c,d);
    }
    cout<<FL.minCostFlow(0,V-1,F)<<"\n";
}