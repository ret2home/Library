#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
void cmps(vector<int>&v,int &i){
	i=lower_bound(all(v),i)-v.begin();
}
constexpr int mod = 1e9+7;
constexpr int inf = LLONG_MAX;

struct WaveletMatrix{
	int N;
	vector<int>V;
	vector<int>bit[40];
	map<int,int>st;
	int rank(int loc,int num){
		if(st.find(num)==st.end())return 0;
		rep(i,40){
			if(num>>(39-i)&1){
				loc=(N-bit[i][N-1])+(loc?bit[i][loc-1]:0);
			}else {
				loc-=(loc?bit[i][loc-1]:0);
			}
		}
		return max(0ll,loc-st[num]);
	}
	int quantile(int l,int r,int c){
		int res=0;
		rep(i,40){
			int num=(r-l)-(bit[i][r-1]-(l?bit[i][l-1]:0));
			if(num<=c){
				c-=num;
				l=(N-bit[i][N-1])+(l?bit[i][l-1]:0);
				r=(N-bit[i][N-1])+bit[i][r-1];
				res+=1ll<<(39-i);
			}else {
				if(l)l-=bit[i][l-1];
				r-=bit[i][r-1];
			}
		}
		return res;
	}
	WaveletMatrix(vector<int>V):N(V.size()),V(V){
		vector<int>dat=V;
		rep(i,N-1)V[i+1]+=V[i];
		rep(i,40){
			bit[i].pb(0);
			vector<int>zero,one;
			rep(j,N){
				if(dat[j]>>(39-i)&1){
					bit[i][j]++;
					one.pb(dat[j]);
				}else {
					zero.pb(dat[j]);
				}
				if(j<N-1)bit[i].pb(bit[i][j]);
			}
			zero.insert(zero.end(),all(one));
			dat=zero;
		}
		rep(i,N){
			if(st.find(dat[i])==st.end())st[dat[i]]=i;
		}
	}
};
signed main(){
	int N,Q;
	cin>>N>>Q;
	vector<int>v(N);
	for(int &i:v)cin>>i;
	WaveletMatrix WM(v);

	while(Q--){
		int l,r,k;cin>>l>>r>>k;
		cout<<WM.quantile(l,r,k)<<endl;
	}
}

