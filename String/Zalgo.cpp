#pragma once
#include "../template/template.cpp"

template<class T>
vector<int>zalgo(T v){
	vector<int>res(v.size());
	int c=0;
	REP(i,(int)v.size()){
		if(i+res[i-c]<c+res[c])res[i]=res[i-c];
		else {
			int j=max(0ll,c+res[c]-i);
			while(i+j<(int)v.size()&&v[j]==v[i+j])++j;
			res[i]=j;c=i;
		}
	}res[0]=v.size();
	return res;
}