#pragma once
#include "../template/template.cpp"

template<class T>
class SuffixArray{
	#define typeS make_pair(false,false)
	#define LMS make_pair(false,true)
	#define typeL make_pair(true,true)
	using TYPE=pair<bool,bool>;
	vector<TYPE>assignType(vector<int>&S){
		vector<TYPE>type(len(S));
		type[len(S)-1]=LMS;
		for(int i=len(S)-2;i>=0;i--){
			if(S[i]<S[i+1])type[i]=typeS;
			else if(S[i]>S[i+1]){
				type[i]=typeL;
				if(type[i+1]==typeS)type[i+1]=LMS;
			}else type[i]=type[i+1];
		}
		return type;
	}
	vector<int>getBucket(vector<int>&S,int alph){
		vector<int>bucket(alph);
		for(int i:S)bucket[i]++;
		rep(i,len(bucket)-1)bucket[i+1]+=bucket[i];
		return bucket;
	}
	void sortTypeL(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int alph){
		vector<int>bucket=getBucket(S,alph);
		for(int i:SA){
			if(i>0&&type[i-1]==typeL)SA[bucket[S[i-1]-1]++]=i-1;
		}
	}
	void sortTypeS(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int alph){
		vector<int>bucket=getBucket(S,alph);
		rev(j,len(S)){
			int i=SA[j];
			if(i>0&&(type[i-1]==typeS||type[i-1]==LMS))SA[--bucket[S[i-1]]]=i-1;
		}
	}
	vector<int>InducedSorting(vector<int>&S,int alph){
		vector<int>SA(len(S),-1);
		vector<TYPE>type=assignType(S);
		vector<int>bucket=getBucket(S,alph);
		vector<int>nextlms(len(S),-1),ordered_lms;
		int lastlms=-1;
		rep(i,len(S))if(type[i]==LMS){
			SA[--bucket[S[i]]]=i;
			if(lastlms!=-1)nextlms[lastlms]=i;
			lastlms=i;
			ordered_lms.emplace_back(i);
		}
		nextlms[lastlms]=lastlms;
		sortTypeL(S,SA,type,alph);
		sortTypeS(S,SA,type,alph);
		vector<int>lmses;
		for(int i:SA)if(type[i]==LMS)lmses.emplace_back(i);
		int nowrank=0;
		vector<int>newS={0};
		REP(i,len(lmses)){
			int pre=lmses[i-1],now=lmses[i];
			if(nextlms[pre]-pre!=nextlms[now]-now)newS.emplace_back(++nowrank);
			else {
				bool flag=false;
				rep(j,nextlms[pre]-pre+1){
					if(S[pre+j]!=S[now+j]){flag=true;break;}
				}
				if(flag)newS.emplace_back(++nowrank);
				else newS.emplace_back(nowrank);
			}
		}
		if(nowrank+1!=len(lmses)){
			vector<int>V(len(S),-1);
			rep(i,len(lmses)){
				V[lmses[i]]=newS[i];
			}
			vector<int>newnewS;
			rep(i,len(S))if(V[i]!=-1)newnewS.emplace_back(V[i]);
			vector<int>SA_=InducedSorting(newnewS,nowrank+1);
			rep(i,len(SA_)){
				lmses[i]=ordered_lms[SA_[i]];
			}
		}
		SA.assign(len(S),-1);
		bucket=getBucket(S,alph);
		rev(i,len(lmses)){
			SA[--bucket[S[lmses[i]]]]=lmses[i];
		}
		sortTypeL(S,SA,type,alph);
		sortTypeS(S,SA,type,alph);
		return SA;
	}
	vector<int>SA;
	T ST;
private:
	int ismatch(T &S,int index){
		rep(i,len(S)){
			if(i+index>=len(ST))return 1;
			if(ST[i+index]<S[i])return 1;
			if(ST[i+index]>S[i])return -1;
		}
		return 0;
	}
public:
	P occ(T &S){
		int okl=len(ST)+1,ngl=0;
		while(okl-ngl>1){
			int mid=(okl+ngl)/2;
			if(ismatch(S,SA[mid])<=0)okl=mid;
			else ngl=mid;
		}
		int okr=len(ST)+1,ngr=0;
		while(okr-ngr>1){
			int mid=(okr+ngr)/2;
			if(ismatch(S,SA[mid])<0)okr=mid;
			else ngr=mid;
		}
		return P(okl,okr);
	}
	vector<int>locate(T &S){
		vector<bool>v(len(ST)+1);
		P range=occ(S);
		for(int i=range.first;i<range.second;i++)v[SA[i]]=true;
		vector<int>res;
		rep(i,len(ST)+1)if(v[i])res.emplace_back(i);
		return res;
	}
	int operator[](int k){return SA[k];}

public:
	vector<int>LCP;
private:
	void constructLCP(){
		vector<int>rank(len(ST)+1);
		LCP.resize(len(ST)+1);
		rep(i,len(ST)+1)rank[SA[i]]=i;
		int h=0;
		rep(i,len(ST)){
			int j=SA[rank[i]-1];
			if(h>0)h--;
			for(j;j+h<len(ST)&&i+h<len(ST);h++){
				if(ST[j+h]!=ST[i+h])break;
			}
			LCP[rank[i]-1]=h;
		}
	}
public:
	SuffixArray(T S):ST(S){
		int mn=inf,mx=-inf;
		for(auto i:S){
			chmin(mn,(int)i);chmax(mx,(int)i);
		}
		vector<int>newS;
		for(auto i:S)newS.emplace_back(i-mn+1);
		newS.emplace_back(0);
		SA=InducedSorting(newS,mx-mn+2);
		constructLCP();
	}
};
