#pragma once
#include "../template/template.cpp"

void dft(vector<complex<double>>&func,int inv){
	int sz=func.size();
	if(sz==1)return;
	vector<complex<double>>va,vb;
	rep(i,sz/2){
		va.push_back(func[2*i]);
		vb.push_back(func[2*i+1]);
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
		nf[i]=f[i];
	}
	rep(i,len(g)){
		ng[i]=g[i];
	}
	dft(nf,1);dft(ng,1);
	rep(i,sz)nf[i]*=ng[i];
	dft(nf,-1);
	vector<double>res;
	rep(i,sz)res.push_back(nf[i].real()/sz);
	return res;
}
