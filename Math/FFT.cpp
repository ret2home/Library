#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 998244353;
constexpr int inf = 3e18;

void dft(vector<complex<double>>&func,int inv){
	int sz=func.size();
	if(sz==1)return;
	vector<complex<double>>va,vb;
	rep(i,sz/2){
		va.pb(func[2*i]);
		vb.pb(func[2*i+1]);
	}
	dft(va,inv);dft(vb,inv);
	complex<double>now=1,zeta=polar(1.0,inv*2.0*acos(-1)/sz);
	rep(i,sz){
		func[i]=va[i%(sz/2)]+now*vb[i%(sz/2)];
		now*=zeta;
	}
}
template<class T>
vector<double>fft(vector<T>f,vector<T>g){
	vector<complex<double>>nf,ng;
	int sz=1;
	while(sz<len(f)+len(g))sz*=2;
	nf.resize(sz);ng.resize(sz);
	rep(i,len(f)){
		nf[i]=f[i];ng[i]=g[i];
	}
	dft(nf,1);dft(ng,1);
	rep(i,sz)nf[i]*=ng[i];
	dft(nf,-1);
	vector<double>res;
	rep(i,sz)res.pb(nf[i].real()/sz);
	return res;
}
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<int>a(N),b(N);
	rep(i,N)cin>>a[i]>>b[i];
	auto res=fft(a,b);
	cout<<0<<endl;
	rep(i,2*N-1)cout<<(int)(res[i]+0.1)<<endl;
}

