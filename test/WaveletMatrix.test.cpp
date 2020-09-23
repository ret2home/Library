#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../structure/WaveletMatrix.cpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int>V(N);
    for(int &i:V)cin>>i;
    WaveletMatrix<vector<int>,int>WM(V,30);
    while(Q--){
        int l,r,k;cin>>l>>r>>k;
        cout<<WM.quantile(l,r,k)<<"\n";
    }
}