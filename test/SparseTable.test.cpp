#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../structure/SparseTable.cpp"

int main(){
	int N,Q;cin>>N>>Q;
	vector<int>V(N);
	for(int &i:V)cin>>i;
	auto f=[](int a,int b)->int{return min(a,b);};
	SparseTable<int,decltype(f)>ST(V,f);
	while(Q--){
		int l,r;cin>>l>>r;
		cout<<ST.query(l,r)<<"\n";
	}
}