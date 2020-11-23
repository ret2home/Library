---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/BWT.cpp
    title: Burrows Wheeler Transform
  - icon: ':heavy_check_mark:'
    path: string/FM_index.cpp
    title: FM Index
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.cpp
    title: Suffix Array (SA-IS)
  - icon: ':heavy_check_mark:'
    path: structure/BitVector.cpp
    title: Bit Vector
  - icon: ':heavy_check_mark:'
    path: structure/WaveletMatrix.cpp
    title: Wavelet Matrix
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/FM_index.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n)\
    \ for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v)\
    \ v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class\
    \ T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return true;}\n\treturn\
    \ false;\n}\ntemplate<class T,class U> inline bool chmax(T &a, U b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BitVector.cpp\"\
    \n\nclass BitVector{\n    vector<ll>sum;\n    vector<uint64_t>bit;\npublic:\n\
    \    ll rank(bool val,ll idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n\
    \        ll res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return\
    \ (val?res:idx-res);\n    }\n    BitVector(vector<bool>&v){\n        ll sz=(len(v)>>6)+1;\n\
    \        bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n\
    \            bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n       \
    \ rep(i,sz-1){\n            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n  \
    \      }\n    }\n};\n/*\n@brief Bit Vector\n@docs docs/BitVector.md\n*/\n#line\
    \ 4 \"structure/WaveletMatrix.cpp\"\n\ntemplate<class T,class C>\nclass WaveletMatrix{\n\
    \    int N,bitlen;\n    vector<BitVector>index;\n    map<C,int>st;\npublic:\n\
    \    T body;\n    int rank(C c,int idx){\n        if(st.find(c)==st.end())return\
    \ 0;\n        rev(i,bitlen){\n            if(c>>i&1)idx=index[i].rank(1,idx)+index[i].rank(0,N);\n\
    \            else idx-=index[i].rank(1,idx);\n        }\n        return max(0,idx-st[c]);\n\
    \    }\n    C quantile(int l,int r,int c){\n        C res=0;\n        rev(i,bitlen){\n\
    \            ll cnt=(r-l)-(index[i].rank(1,r)-index[i].rank(1,l));\n         \
    \   if(cnt<=c){\n                c-=cnt;\n                l=index[i].rank(0,N)+index[i].rank(1,l);\n\
    \                r=index[i].rank(0,N)+index[i].rank(1,r);\n                res+=1ll<<i;\n\
    \            }else {\n                l-=index[i].rank(1,l);\n               \
    \ r-=index[i].rank(1,r);\n            }\n        }\n        return res;\n    }\n\
    \    WaveletMatrix(T V,ll bitlen):N(len(V)),bitlen(bitlen),body(V){\n        vector<bool>bit(N);\n\
    \        index.resize(bitlen,bit);\n        rev(i,bitlen){\n            T newV[2];\n\
    \            rep(j,N){\n                bit[j]=(V[j]>>i&1);\n                newV[V[j]>>i&1].push_back(V[j]);\n\
    \            }\n            V=newV[0];V.insert(V.end(),all(newV[1]));\n      \
    \      index[i]=BitVector(bit);\n        }\n        rep(i,N)if(st.find(V[i])==st.end())st[V[i]]=i;\n\
    \    }\n};\n/*\n@brief Wavelet Matrix\n@docs docs/WaveletMatrix.md\n*/\n#line\
    \ 3 \"string/SuffixArray.cpp\"\n\ntemplate<class T>\nclass SuffixArray{\n\t#define\
    \ typeS make_pair(false,false)\n\t#define LMS make_pair(false,true)\n\t#define\
    \ typeL make_pair(true,true)\n\tusing TYPE=pair<bool,bool>;\n\tvector<TYPE>assignType(vector<ll>&S){\n\
    \t\tvector<TYPE>type(len(S));\n\t\ttype[len(S)-1]=LMS;\n\t\tfor(ll i=len(S)-2;i>=0;i--){\n\
    \t\t\tif(S[i]<S[i+1])type[i]=typeS;\n\t\t\telse if(S[i]>S[i+1]){\n\t\t\t\ttype[i]=typeL;\n\
    \t\t\t\tif(type[i+1]==typeS)type[i+1]=LMS;\n\t\t\t}else type[i]=type[i+1];\n\t\
    \t}\n\t\treturn type;\n\t}\n\tvector<ll>getBucket(vector<ll>&S,ll alph){\n\t\t\
    vector<ll>bucket(alph);\n\t\tfor(ll i:S)bucket[i]++;\n\t\trep(i,len(bucket)-1)bucket[i+1]+=bucket[i];\n\
    \t\treturn bucket;\n\t}\n\tvoid sortTypeL(vector<ll>&S,vector<ll>&SA,vector<TYPE>&type,ll\
    \ alph){\n\t\tvector<ll>bucket=getBucket(S,alph);\n\t\tfor(ll i:SA){\n\t\t\tif(i>0&&type[i-1]==typeL)SA[bucket[S[i-1]-1]++]=i-1;\n\
    \t\t}\n\t}\n\tvoid sortTypeS(vector<ll>&S,vector<ll>&SA,vector<TYPE>&type,ll alph){\n\
    \t\tvector<ll>bucket=getBucket(S,alph);\n\t\trev(j,len(S)){\n\t\t\tll i=SA[j];\n\
    \t\t\tif(i>0&&(type[i-1]==typeS||type[i-1]==LMS))SA[--bucket[S[i-1]]]=i-1;\n\t\
    \t}\n\t}\n\tvector<ll>InducedSorting(vector<ll>&S,ll alph){\n\t\tvector<ll>SA(len(S),-1);\n\
    \t\tvector<TYPE>type=assignType(S);\n\t\tvector<ll>bucket=getBucket(S,alph);\n\
    \t\tvector<ll>nextlms(len(S),-1),ordered_lms;\n\t\tll lastlms=-1;\n\t\trep(i,len(S))if(type[i]==LMS){\n\
    \t\t\tSA[--bucket[S[i]]]=i;\n\t\t\tif(lastlms!=-1)nextlms[lastlms]=i;\n\t\t\t\
    lastlms=i;\n\t\t\tordered_lms.emplace_back(i);\n\t\t}\n\t\tnextlms[lastlms]=lastlms;\n\
    \t\tsortTypeL(S,SA,type,alph);\n\t\tsortTypeS(S,SA,type,alph);\n\t\tvector<ll>lmses;\n\
    \t\tfor(ll i:SA)if(type[i]==LMS)lmses.emplace_back(i);\n\t\tll nowrank=0;\n\t\t\
    vector<ll>newS={0};\n\t\tREP(i,len(lmses)){\n\t\t\tll pre=lmses[i-1],now=lmses[i];\n\
    \t\t\tif(nextlms[pre]-pre!=nextlms[now]-now)newS.emplace_back(++nowrank);\n\t\t\
    \telse {\n\t\t\t\tbool flag=false;\n\t\t\t\trep(j,nextlms[pre]-pre+1){\n\t\t\t\
    \t\tif(S[pre+j]!=S[now+j]){flag=true;break;}\n\t\t\t\t}\n\t\t\t\tif(flag)newS.emplace_back(++nowrank);\n\
    \t\t\t\telse newS.emplace_back(nowrank);\n\t\t\t}\n\t\t}\n\t\tif(nowrank+1!=len(lmses)){\n\
    \t\t\tvector<ll>V(len(S),-1);\n\t\t\trep(i,len(lmses)){\n\t\t\t\tV[lmses[i]]=newS[i];\n\
    \t\t\t}\n\t\t\tvector<ll>newnewS;\n\t\t\trep(i,len(S))if(V[i]!=-1)newnewS.emplace_back(V[i]);\n\
    \t\t\tvector<ll>SA_=InducedSorting(newnewS,nowrank+1);\n\t\t\trep(i,len(SA_)){\n\
    \t\t\t\tlmses[i]=ordered_lms[SA_[i]];\n\t\t\t}\n\t\t}\n\t\tSA.assign(len(S),-1);\n\
    \t\tbucket=getBucket(S,alph);\n\t\trev(i,len(lmses)){\n\t\t\tSA[--bucket[S[lmses[i]]]]=lmses[i];\n\
    \t\t}\n\t\tsortTypeL(S,SA,type,alph);\n\t\tsortTypeS(S,SA,type,alph);\n\t\treturn\
    \ SA;\n\t}\n\tvector<ll>SA;\n\tT ST;\nprivate:\n\tll ismatch(T &S,ll index){\n\
    \t\trep(i,len(S)){\n\t\t\tif(i+index>=len(ST))return 1;\n\t\t\tif(ST[i+index]<S[i])return\
    \ 1;\n\t\t\tif(ST[i+index]>S[i])return -1;\n\t\t}\n\t\treturn 0;\n\t}\npublic:\n\
    \tP occ(T &S){\n\t\tll okl=len(ST)+1,ngl=0;\n\t\twhile(okl-ngl>1){\n\t\t\tll mid=(okl+ngl)/2;\n\
    \t\t\tif(ismatch(S,SA[mid])<=0)okl=mid;\n\t\t\telse ngl=mid;\n\t\t}\n\t\tll okr=len(ST)+1,ngr=0;\n\
    \t\twhile(okr-ngr>1){\n\t\t\tll mid=(okr+ngr)/2;\n\t\t\tif(ismatch(S,SA[mid])<0)okr=mid;\n\
    \t\t\telse ngr=mid;\n\t\t}\n\t\treturn P(okl,okr);\n\t}\n\tvector<ll>locate(T\
    \ &S){\n\t\tvector<bool>v(len(ST)+1);\n\t\tP range=occ(S);\n\t\tfor(ll i=range.first;i<range.second;i++)v[SA[i]]=true;\n\
    \t\tvector<ll>res;\n\t\trep(i,len(ST)+1)if(v[i])res.emplace_back(i);\n\t\treturn\
    \ res;\n\t}\n\tll operator[](ll k){return SA[k];}\n\npublic:\n\tvector<ll>LCP;\n\
    private:\n\tvoid constructLCP(){\n\t\tvector<ll>rank(len(ST)+1);\n\t\tLCP.resize(len(ST)+1);\n\
    \t\trep(i,len(ST)+1)rank[SA[i]]=i;\n\t\tll h=0;\n\t\trep(i,len(ST)){\n\t\t\tll\
    \ j=SA[rank[i]-1];\n\t\t\tif(h>0)h--;\n\t\t\tfor(j;j+h<len(ST)&&i+h<len(ST);h++){\n\
    \t\t\t\tif(ST[j+h]!=ST[i+h])break;\n\t\t\t}\n\t\t\tLCP[rank[i]-1]=h;\n\t\t}\n\t\
    }\npublic:\n\tSuffixArray(T S):ST(S){\n\t\tll mn=inf,mx=-inf;\n\t\tfor(auto i:S){\n\
    \t\t\tchmin(mn,(ll)i);chmax(mx,(ll)i);\n\t\t}\n\t\tvector<ll>newS;\n\t\tfor(auto\
    \ i:S)newS.emplace_back(i-mn+1);\n\t\tnewS.emplace_back(0);\n\t\tSA=InducedSorting(newS,mx-mn+2);\n\
    \t\tconstructLCP();\n\t}\n};\n\n/*\n@brief Suffix Array (SA-IS)\n@docs docs/SuffixArray.md\n\
    */\n#line 4 \"string/BWT.cpp\"\n\ntemplate<class T>\nT BWT(T S,SuffixArray<T>&SA){\n\
    \    S+='$';\n    T bwt;\n    rep(i,len(S)){\n        bwt.push_back(S[(SA[i]-1+len(S))%len(S)]);\n\
    \    }\n    return bwt;\n}\n\ntemplate<class T>\nT BWTInverse(T S){\n    vector<ll>B(len(S));\n\
    \    ll mx=-inf;\n    rep(i,len(S)){\n        B[i]=(S[i]=='$'?0:(ll)S[i]);\n \
    \       chmax(mx,B[i]);\n    }\n    vector<vector<ll>>BB(mx+1),F(mx+1);\n    vector<P>V;\n\
    \    rep(i,len(S)){\n        BB[B[i]].push_back(i);\n        F[B[i]].push_back(i);\n\
    \    }\n    ll cnt=0;\n    rep(i,mx+1){\n        rep(j,len(F[i])){\n         \
    \   F[i][j]=cnt++;\n            V.push_back({i,j});\n        }\n    }\n    ll\
    \ now=BB[0][0];\n    T res;\n    rep(i,len(S)-1){\n        res.push_back(V[now].first);\n\
    \        now=BB[V[now].first][V[now].second];\n    }\n    return res;\n}\n/*\n\
    @brief Burrows Wheeler Transform\n@docs docs/BWT.md\n*/\n#line 5 \"string/FM_index.cpp\"\
    \n\ntemplate<class T,class C>\nclass FMIndex{\n    ll N,base;\n    T bwt;\n  \
    \  vector<ll>c;\n    WaveletMatrix<T,C>WM;\n    SuffixArray<T>SA;\n    public:\n\
    \    T ST;\n    P occ(T &S){\n        for(auto i:S)if((ll)i<base||(ll)i-base>=len(c))return\
    \ P(0,0);\n        ll sp=0,ep=N;\n        rev(i,len(S)){\n            sp=c[(ll)S[i]-base]+WM.rank(S[i],sp);\n\
    \            ep=c[(ll)S[i]-base]+WM.rank(S[i],ep);\n            if(sp>=ep)return\
    \ P(0,0);\n        }\n        return P(sp,ep);\n    }\n    vector<ll>locate(T\
    \ &S){\n        vector<bool>v(len(ST)+1);\n\t\tP range=occ(S);\n\t\tfor(ll i=range.first;i<range.second;i++)v[SA[i]]=true;\n\
    \t\tvector<ll>res;\n\t\trep(i,len(ST)+1)if(v[i])res.emplace_back(i);\n\t\treturn\
    \ res;\n    }\n    FMIndex(T S):N(len(S)+1),ST(S+'$'),WM(\"\",0),SA(S){\n    \
    \    bwt=BWT(S,SA);\n        WM=WaveletMatrix<T,C>(bwt,8);\n        ll mn=inf,mx=-inf;\n\
    \        for(C i:ST){\n            chmin(mn,(ll)i);\n            chmax(mx,(ll)i);\n\
    \        }\n        c.resize(mx-mn+2);\n        for(C i:ST){\n            c[(ll)i-mn+1]++;\n\
    \        }\n        rep(i,mx-mn+1)c[i+1]+=c[i];\n        base=mn;\n    }\n};\n\
    /*\n@brief FM Index\n@docs docs/FM_index.md\n*/\n#line 4 \"test/FM_index.test.cpp\"\
    \n\nint main(){\n    string S,T;\n    cin>>S>>T;\n    FMIndex<string,char>FM(S);\n\
    \    for(int i:FM.locate(T))cout<<i<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    \n#include \"../string/FM_index.cpp\"\n\nint main(){\n    string S,T;\n    cin>>S>>T;\n\
    \    FMIndex<string,char>FM(S);\n    for(int i:FM.locate(T))cout<<i<<\"\\n\";\n\
    }"
  dependsOn:
  - string/FM_index.cpp
  - template/template.cpp
  - structure/WaveletMatrix.cpp
  - structure/BitVector.cpp
  - string/BWT.cpp
  - string/SuffixArray.cpp
  isVerificationFile: true
  path: test/FM_index.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FM_index.test.cpp
layout: document
redirect_from:
- /verify/test/FM_index.test.cpp
- /verify/test/FM_index.test.cpp.html
title: test/FM_index.test.cpp
---
