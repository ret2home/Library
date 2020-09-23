#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include "../string/FM_index.cpp"

int main(){
    string S,T;
    cin>>S>>T;
    FMIndex<string,char>FM(S);
    for(int i:FM.locate(T))cout<<i<<"\n";
}