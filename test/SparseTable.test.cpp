#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../structure/SparseTable.cpp"

auto f=[](int a,int b)->int{return min(a,b);};
int main(){
	int N,Q;cin>>N>>Q;
	vector<int>V(N);
	for(int &i:V)cin>>i;
	SparseTable<int,f>ST(V);
	while(Q--){
		int l,r;cin>>l>>r;
		cout<<ST.query(l,r)<<"\n";
	}
}