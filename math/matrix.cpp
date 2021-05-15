#pragma once
#include "../template/template.cpp"
#include "modint.cpp"

template<int MOD>
struct matrix{
    using modint=mint<MOD>;
	vector<vector<modint>>mat;
	matrix(int x,int y){
		mat.resize(x);
		rep(i,x)mat[i].resize(y);
		rep(i,x)rep(j,y)mat[i][j]=0;
	}
	matrix operator*(matrix a){
		assert(mat[0].size()==a.mat.size());
		matrix<MOD> res(mat.size(),a.mat[0].size());
		rep(i,mat.size()){
			rep(j,a.mat[0].size()){
				rep(k,a.mat.size()){
					res.mat[i][j]+=mat[i][k]*a.mat[k][j];
				}
			}
		}
		return res;
	}
	matrix pow(ll x){
		assert(mat.size()==mat[0].size());
		matrix<MOD> res(mat.size(),mat.size()),me(mat.size(),mat.size());
		rep(i,mat.size())res.mat[i][i]=1;
		me.mat=mat;
		while(x>0){
			if(x&1)res=res*me;
			me=me*me;
			x>>=1;
		}
		return res;
	}
};