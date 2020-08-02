#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

struct BIT{
	int N;
	vector<int>bit;
	void add(int x,int y){
		while(x<=N){
			bit[x]+=y;x+=x&-x;
		}
	}
	int sum(int x){
		int res=0;
		while(x>0){
			res+=bit[x];x-=x&-x;
		}
		return res;
	}
	int lower_bound(int w){
		if(w<=0)return 0;
		int x=0;
		int k=1;while(k*2<=N)k*=2;
		for(;k>0;k/=2){
			if(x+k<=N&&bit[x+k]<w){
				w-=bit[x+k];
				x+=k;
			}
		}
		return x+1;
	}
	BIT(int x):N(x),bit(x+1){}
};

int N;
struct S{
	int idx,A,B;
};
bool f(S a,S b){
	if(a.B!=b.B)return a.B>b.B;
	return a.A<b.A;
}
bool g(S a,S b){
	return a.A<b.A;
}
S A[300005];
signed main(){
	cin>>N;
	rep(i,N){
		cin>>A[i].A>>A[i].B;A[i].idx=i;
	}
	sort(A,A+N,g);
	rep(i,N){
		A[i].idx=i;
	}
	sort(A,A+N,f);
	BIT bit(N+10),bit2(N+10);
	int ans=0;
	rep(i,N){
		bit2.add(A[i].idx+1,1);
		bit.add(A[i].idx+1,A[i].A);
		while(ans<=i){
			int j=bit2.lower_bound(ans+1);
			if(bit.sum(j)<=A[i].B*(ans+1))ans++;
			else break;
		}
	}
	cout<<ans<<endl;
}

