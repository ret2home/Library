#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../structure/LiChaoTree.cpp"

ll N,Q;
ll L[200005],R[200005],x[200005],y[200005];
ll l[200005],r[200005],a[200005],b[200005];
vector<ll>v;
signed main(){
	cin>>N>>Q;
	rep(i,N){
		cin>>L[i]>>R[i]>>x[i]>>y[i];
		v.push_back(L[i]);v.push_back(R[i]);
	}
	rep(i,Q){
		int type;cin>>type;
		if(type==0){
			cin>>l[i]>>r[i]>>a[i]>>b[i];
			v.push_back(l[i]);v.push_back(r[i]);
		}
		else {
			cin>>a[i];v.push_back(a[i]);b[i]=inf;
		}
	}
	sort(all(v));v.erase(unique(all(v)),v.end());
	LiChaoTree<ll>LCT(v);
	auto idx=[&](ll &x){
		x=lower_bound(all(v),x)-v.begin();
	};
	rep(i,N){
		idx(L[i]);idx(R[i]);
		LCT.add(L[i],R[i],{x[i],y[i]});
	}
	rep(i,Q){
		if(b[i]!=inf){
			idx(l[i]);idx(r[i]);
			LCT.add(l[i],r[i],{a[i],b[i]});
		}
		else {
			idx(a[i]);
			ll ans=LCT.query(a[i]);
			if(ans==inf)cout<<"INFINITY"<<endl;
			else cout<<ans<<endl;
		}
	}
}
