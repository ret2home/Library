#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../math/factor.cpp"

int main(){
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        auto res=factor(N);
        cout<<len(res)<<" ";
        sort(all(res));
        for(ll i:res)cout<<i<<" ";
        cout<<"\n";
    }
}