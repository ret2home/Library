#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../structure/BIT.cpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    BIT<ll>bit(N);
    rep(i,N){
        int a;cin>>a;
        bit.add(i,a);
    }
    while(Q--){
        int t;cin>>t;
        if(!t){
            int p,x;cin>>p>>x;
            bit.add(p,x);
        }else {
            int l,r;cin>>l>>r;
            cout<<bit.sum(l,r)<<"\n";
        }
    }
}