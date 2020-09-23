#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include "../string/RollingHash.cpp"

int main(){
    string S,T;
    cin>>S>>T;
    RollingHash<string>RH1(S),RH2(T);
    rep(i,len(S)-len(T)+1){
        if(RH1.get(i,i+len(T))==RH2.hash[len(T)])cout<<i<<"\n";
    }
}