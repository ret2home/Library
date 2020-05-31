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
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

template<class T>
struct PersistentArray{
	struct Node{
		T val;
		Node* ch[20];
	};
	Node *set(int idx,T val,Node *t){
		Node *res=(t?new Node(*t):new Node());
		if(idx==0)res->val=val;
		else res->ch[idx%20]=set(idx/20,val,res->ch[idx%20]);
		return res;
	}
	T get(int idx,Node *t){
		assert(t);
		if(!idx)return t->val;
		return get(idx/20,t->ch[idx%20]);
	}
};
int l[500005],r[500005];
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	using node=PersistentArray<int>::Node;
	int Q;cin>>Q;
	vector<node*>v(1,nullptr);
	PersistentArray<int>PA;
	REP(i,Q+1){
		int type;cin>>type;
		if(type==0){
			int t,x;cin>>t>>x;t++;
			v.pb(PA.set(r[t],x,v[t]));
			l[i]=l[t];r[i]=r[t]+1;
		}else {
			int t;cin>>t;t++;
			cout<<PA.get(l[t],v[t])<<endl;
			v.pb(new node(*v[t]));
			l[i]=l[t]+1;r[i]=r[t];
		}
	}
}

