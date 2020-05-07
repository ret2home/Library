#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back
#define fi first
#define se second

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
constexpr int mod = 998244353;
constexpr int inf = LLONG_MAX;

template<class T>
struct SplayTree{
	struct node{
		T val;
		node *lch,*rch;
	};
	node *root=NULL;
	int size=0;
	node *rightRotate(node *x){
		node *y=x->lch;
		x->lch=y->rch;
		y->rch=x;
		return y;
	}
	node *leftRotate(node *x){
		node *y=x->rch;
		x->rch=y->lch;
		y->lch=x;
		return y;
	}
	node *splay(node *x,T v){
		if(x==NULL||x->val==v)return x;
		if(v<x->val){
			if(x->lch==NULL)return x;
			if(v<x->lch->val){
				x->lch->lch=splay(x->lch->lch,v);
				x=rightRotate(x);
			}else if(x->lch->val<v){
				x->lch->rch=splay(x->lch->rch,v);
				if(x->lch->rch!=NULL)
					x->lch=leftRotate(x->lch);
			}
			return (x->lch==NULL||x->val==v)?x:rightRotate(x);
		}else {
			if(x->rch==NULL)return x;
			if(v<x->rch->val){
				x->rch->lch=splay(x->rch->lch,v);
				if(x->rch->lch!=NULL)
					x->rch=rightRotate(x->rch);
			}else {
				x->rch->rch=splay(x->rch->rch,v);
				x=leftRotate(x);
			}
			return (x->rch==NULL||x->val==v)?x:leftRotate(x);
		}
	}
	node *find(T x){
		root=splay(root,x);
		if(root==NULL||root->val!=x)return NULL;
		return root;
	}
	node *insert(node *x,T v){
		if(x==NULL){
			node *q=new node;
			q->val=v;
			q->lch=q->rch=NULL;
			return q;
		}
		if(v<x->val)x->lch=insert(x->lch,v);
		else x->rch=insert(x->rch,v);
		return x;
	}
	void insert(T x){
		if(!find(x)){
			root=insert(root,x);size++;
		}
	}
	node *erase(node *x,T v){
		if(x==NULL)return NULL;
		if(v<x->val)x->lch=erase(x->lch,v);
		else if(x->val<v)x->rch=erase(x->rch,v);
		else if(x->lch==NULL){
			node *q=x->rch;
			delete x;
			return q;
		}else if(x->lch->rch==NULL){
			node *q=x->lch;
			q->rch=x->rch;
			delete x;
			return q;
		}else {
			node *q;
			for(q=x->lch;q->rch->rch!=NULL;q=q->rch);
			node *r=q->rch;
			q->rch=r->lch;
			r->lch=x->lch;
			r->rch=x->rch;
			delete x;
			return r;
		}
		return x;
	}
	node* lower_bound(T x){
		root=splay(root,x);
		if(root==NULL||root->val>=x)return root;
		if(root->rch==NULL)return NULL;
		node *q;
		for(q=root->rch;q->lch!=NULL;q=q->lch);
		return q;
	}
	node *upper_bound(T x){
		root=splay(root,x);
		if(root==NULL||root->val>x)return root;
		if(root->rch==NULL)return NULL;
		node *q;
		for(q=root->rch;q->lch!=NULL;q=q->lch);
		return q;
	}
	void erase(T x){
		if(find(x)){
			root=erase(root,x);
			size--;
		}
	}
};

signed main(){
	SplayTree<int>st;
	rep(i,1000000){
		int type,x;cin>>type>>x;
		if(type==0){
			auto p=st.lower_bound(x);
			if(p!=NULL)cout<<p->val<<endl;
		}else if(type==1){
			st.insert(x);
		}else {
			st.erase(x);
		}
	}
}

