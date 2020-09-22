#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E"

#include "math/Combination.cpp"

signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	Combination<mod>C;
	int n,k;cin>>n>>k;
	cout<<C.nCk(k,n)<<"\n";
}