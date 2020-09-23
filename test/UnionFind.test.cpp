#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../structure/UnionFind.cpp"

int N,Q;
int main(){
    cin>>N>>Q;
    UnionFind uf(N);
    while(Q--){
        int t,u,v;cin>>t>>u>>v;
        if(!t)uf.merge(u,v);
        else cout<<uf.same(u,v)<<"\n";
    }
}