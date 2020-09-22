#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../structure/SegmentTree.cpp"

constexpr int MOD=998244353;

auto f=[](int a,int b)->int{return (a+b)%MOD;};
auto g=[](int a,P b,int sz)->int{return (a*b.first+b.second*sz)%MOD;};
auto h=[](P a,P b)->P{return P(a.first*b.first%MOD,(a.second*b.first+b.second)%MOD);};

signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q;
	cin>>N>>Q;
	Segtree<int,P,decltype(f),decltype(g),decltype(h)>segtree(N,f,g,h,0,P(1,0));
	rep(i,N){
		int a;cin>>a;
		segtree.set(i,a);
	}
	segtree.init();
	while(Q--){
		int t;cin>>t;
		if(!t){
			int l,r,b,c;cin>>l>>r>>b>>c;
			segtree.update(l,r,P(b,c));
		}else {
			int l,r;cin>>l>>r;
			cout<<segtree.query(l,r)<<"\n";
		}
	}
}