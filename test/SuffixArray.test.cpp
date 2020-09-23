#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../string/SuffixArray.cpp"

int main(){
    string s;cin>>s;
    SuffixArray<string>SA(s);
    REP(i,len(s)+1)cout<<SA[i]<<" ";cout<<"\n";
}