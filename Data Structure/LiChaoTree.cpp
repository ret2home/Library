#pragma once
#include "../template/template.cpp"

template<class T>
struct LiChaoTree{
	struct L{
		T a,b;
		L(T a,T b):a(a),b(b){}
		bool operator==(L l){return a==l.a&&b==l.b;};
	};
	T f(L line,T x){
		return line.a*x+line.b;
	}
	int size=1;
	L ini={0,inf};
	vector<L>dat;
	vector<T>X;
	void add(int a,int b,L li,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l)return;
		int m=(l+r)/2;
		if(!(a<=l&&r<=b)){
			add(a,b,li,2*k+1,l,m);
			add(a,b,li,2*k+2,m,r);
			return;
		}
		if(dat[k]==ini){
			dat[k]=li;
			return;
		}
		int lx=X[l],mx=X[m],rx=X[r-1];
		bool left=f(li,lx)<f(dat[k],lx);
		bool mid=f(li,mx)<f(dat[k],mx);
		bool right=f(li,rx)<f(dat[k],rx);

		if(left&&right){dat[k]=li;return;}
		if(!left&&!right)return;
		if(mid)swap(li,dat[k]);
		if(left!=mid){
			add(a,b,li,2*k+1,l,m);
		}else {
			add(a,b,li,2*k+2,m,r);
		}
	}
	T query(int a,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		if(r-l==1)return f(dat[k],X[a]);
		if(a<(l+r)/2)return min(query(a,k*2+1,l,(l+r)/2),f(dat[k],X[a]));
		else return min(query(a,k*2+2,(l+r)/2,r),f(dat[k],X[a]));
	}
	LiChaoTree(vector<T>v):X(v){
		int N=len(v);
		while(size<N)size*=2;
		dat.resize(size*2-1,ini);
		X.resize(size*2-1,1e9);
	}
};
