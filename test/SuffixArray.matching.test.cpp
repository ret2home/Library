#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include "../string/SuffixArray.cpp"

int main(){
    string S,T;cin>>S>>T;
    SuffixArray<string>SA(S);
    for(int i:SA.locate(T))cout<<i<<"\n";
}