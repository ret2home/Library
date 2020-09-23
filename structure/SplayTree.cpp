#pragma once
#include "../template/template.cpp"

template<class T>
class SplayTree{
	struct node{
		T val;
		node *lch,*rch;
	};
	node *root=NULL;
	ll sz=0;
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
			return (x->lch==NULL)?x:rightRotate(x);
		}else {
			if(x->rch==NULL)return x;
			if(v<x->rch->val){
				x->rch->lch=splay(x->rch->lch,v);
				if(x->rch->lch!=NULL)
					x->rch=rightRotate(x->rch);
			}else if(x->rch->val<v){
				x->rch->rch=splay(x->rch->rch,v);
				x=leftRotate(x);
			}
			return (x->rch==NULL)?x:leftRotate(x);
		}
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
public:
	ll size(){
		return sz;
	}
	node *find(T x){
		root=splay(root,x);
		if(root==NULL||root->val!=x)return NULL;
		return root;
	}
	void insert(T x){
		if(!find(x)){
			root=insert(root,x);sz++;
		}
	}
	void erase(T x){
		if(find(x)){
			root=erase(root,x);
			sz--;
		}
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
};