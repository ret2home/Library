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
	void destructive_set(int idx,T val,Node *&t){
		if(!t)t=new Node();
		if(idx==0)t->val=val;
		else destructive_set(idx/20,val,t->ch[idx%20]);
	}
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
struct PersistentUnionFind{
	using node=PersistentArray<P>::Node;
	PersistentArray<P>data;
	P find(int x,node *t){
		P p=data.get(x,t);
		if(p.first==x)return p;
		p=find(p.first,t);
		data.set(x,p,t);
		return p;
	}
	bool same(int x,int y,node *t){
		return find(x,t)==find(y,t);
	}
	int size(int x,node *t){
		return data.get(find(x,t).first,t).second;
	}
	node* merge(int x,int y,node *t){
		P u=find(x,t),v=find(y,t);
		if(u.first==v.first)return new node(*t);
		if(u.second>v.second)swap(u,v);
		node *res=data.set(u.first,{v.first,u.second},t);
		data.destructive_set(v.first,{v.first,u.second+v.second},res);
		return res;
	}
	node* init(int x){
		node* root=new node();
		rep(i,x){
			data.destructive_set(i,{i,1},root);
		}
		return root;
	}
};
signed main(){
	using node=PersistentUnionFind::node;
	int N,Q;cin>>N>>Q;
	vector<node*>V(Q);
	PersistentUnionFind PU;
	V[0]=PU.init(N);
	REP(i,Q+1){
		int type;
		cin>>type;
		if(type==0){
			int k,u,v;cin>>k>>u>>v;k++;
			V[i]=PU.merge(u,v,V[k]);
		}else {
			int k,u,v;cin>>k>>u>>v;k++;
			cout<<PU.same(u,v,V[k])<<endl;
		}
	}
}

