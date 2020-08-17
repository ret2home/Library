struct UnionFind{
	vector<int>par,size;
	int find(int x){
		return (par[x]==x?x:par[x]=find(par[x]));
	}
	void merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		if(size[x]<size[y]){
			par[x]=y;
			size[y]+=size[x];
		}else {
			par[y]=x;
			size[x]+=size[y];
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	UnionFind(int x){
		rep(i,x){
			par.push_back(i);size.push_back(1);
		}
	}
};
