#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../string/SuffixArray.cpp"

int main(){
    string S;cin>>S;
    ll N=len(S);
    ll ans=N*(N-1)/2+N;
    SuffixArray<string>SA(S);
    rep(i,len(S))ans-=SA.LCP[i];
    cout<<ans<<"\n";
}