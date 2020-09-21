---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/FM_index.cpp
    title: String/FM_index.cpp
  - icon: ':warning:'
    path: String/BWT.cpp
    title: String/BWT.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define int long long\n#define rep(i,n) for(int i=0;i<n;i++)\n\
    #define REP(i,n) for(int i=1;i<n;i++)\n#define rev(i,n) for(int i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<int,int>\n#define len(s) (int)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr int mod = 1e9+7;\nconstexpr long long\
    \ inf = 3e18;\n#line 3 \"String/SuffixArray.cpp\"\n\ntemplate<class T>\nclass\
    \ SuffixArray{\n\t#define typeS make_pair(false,false)\n\t#define LMS make_pair(false,true)\n\
    \t#define typeL make_pair(true,true)\n\tusing TYPE=pair<bool,bool>;\n\tvector<TYPE>assignType(vector<int>&S){\n\
    \t\tvector<TYPE>type(len(S));\n\t\ttype[len(S)-1]=LMS;\n\t\tfor(int i=len(S)-2;i>=0;i--){\n\
    \t\t\tif(S[i]<S[i+1])type[i]=typeS;\n\t\t\telse if(S[i]>S[i+1]){\n\t\t\t\ttype[i]=typeL;\n\
    \t\t\t\tif(type[i+1]==typeS)type[i+1]=LMS;\n\t\t\t}else type[i]=type[i+1];\n\t\
    \t}\n\t\treturn type;\n\t}\n\tvector<int>getBucket(vector<int>&S,int alph){\n\t\
    \tvector<int>bucket(alph);\n\t\tfor(int i:S)bucket[i]++;\n\t\trep(i,len(bucket)-1)bucket[i+1]+=bucket[i];\n\
    \t\treturn bucket;\n\t}\n\tvoid sortTypeL(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int\
    \ alph){\n\t\tvector<int>bucket=getBucket(S,alph);\n\t\tfor(int i:SA){\n\t\t\t\
    if(i>0&&type[i-1]==typeL)SA[bucket[S[i-1]-1]++]=i-1;\n\t\t}\n\t}\n\tvoid sortTypeS(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int\
    \ alph){\n\t\tvector<int>bucket=getBucket(S,alph);\n\t\trev(j,len(S)){\n\t\t\t\
    int i=SA[j];\n\t\t\tif(i>0&&(type[i-1]==typeS||type[i-1]==LMS))SA[--bucket[S[i-1]]]=i-1;\n\
    \t\t}\n\t}\n\tvector<int>InducedSorting(vector<int>&S,int alph){\n\t\tvector<int>SA(len(S),-1);\n\
    \t\tvector<TYPE>type=assignType(S);\n\t\tvector<int>bucket=getBucket(S,alph);\n\
    \t\tvector<int>nextlms(len(S),-1),ordered_lms;\n\t\tint lastlms=-1;\n\t\trep(i,len(S))if(type[i]==LMS){\n\
    \t\t\tSA[--bucket[S[i]]]=i;\n\t\t\tif(lastlms!=-1)nextlms[lastlms]=i;\n\t\t\t\
    lastlms=i;\n\t\t\tordered_lms.emplace_back(i);\n\t\t}\n\t\tnextlms[lastlms]=lastlms;\n\
    \t\tsortTypeL(S,SA,type,alph);\n\t\tsortTypeS(S,SA,type,alph);\n\t\tvector<int>lmses;\n\
    \t\tfor(int i:SA)if(type[i]==LMS)lmses.emplace_back(i);\n\t\tint nowrank=0;\n\t\
    \tvector<int>newS={0};\n\t\tREP(i,len(lmses)){\n\t\t\tint pre=lmses[i-1],now=lmses[i];\n\
    \t\t\tif(nextlms[pre]-pre!=nextlms[now]-now)newS.emplace_back(++nowrank);\n\t\t\
    \telse {\n\t\t\t\tbool flag=false;\n\t\t\t\trep(j,nextlms[pre]-pre+1){\n\t\t\t\
    \t\tif(S[pre+j]!=S[now+j]){flag=true;break;}\n\t\t\t\t}\n\t\t\t\tif(flag)newS.emplace_back(++nowrank);\n\
    \t\t\t\telse newS.emplace_back(nowrank);\n\t\t\t}\n\t\t}\n\t\tif(nowrank+1!=len(lmses)){\n\
    \t\t\tvector<int>V(len(S),-1);\n\t\t\trep(i,len(lmses)){\n\t\t\t\tV[lmses[i]]=newS[i];\n\
    \t\t\t}\n\t\t\tvector<int>newnewS;\n\t\t\trep(i,len(S))if(V[i]!=-1)newnewS.emplace_back(V[i]);\n\
    \t\t\tvector<int>SA_=InducedSorting(newnewS,nowrank+1);\n\t\t\trep(i,len(SA_)){\n\
    \t\t\t\tlmses[i]=ordered_lms[SA_[i]];\n\t\t\t}\n\t\t}\n\t\tSA.assign(len(S),-1);\n\
    \t\tbucket=getBucket(S,alph);\n\t\trev(i,len(lmses)){\n\t\t\tSA[--bucket[S[lmses[i]]]]=lmses[i];\n\
    \t\t}\n\t\tsortTypeL(S,SA,type,alph);\n\t\tsortTypeS(S,SA,type,alph);\n\t\treturn\
    \ SA;\n\t}\n\tvector<int>SA;\n\tT ST;\nprivate:\n\tint ismatch(T &S,int index){\n\
    \t\trep(i,len(S)){\n\t\t\tif(i+index>=len(ST))return 1;\n\t\t\tif(ST[i+index]<S[i])return\
    \ 1;\n\t\t\tif(ST[i+index]>S[i])return -1;\n\t\t}\n\t\treturn 0;\n\t}\npublic:\n\
    \tP occ(T &S){\n\t\tint okl=len(ST)+1,ngl=0;\n\t\twhile(okl-ngl>1){\n\t\t\tint\
    \ mid=(okl+ngl)/2;\n\t\t\tif(ismatch(S,SA[mid])<=0)okl=mid;\n\t\t\telse ngl=mid;\n\
    \t\t}\n\t\tint okr=len(ST)+1,ngr=0;\n\t\twhile(okr-ngr>1){\n\t\t\tint mid=(okr+ngr)/2;\n\
    \t\t\tif(ismatch(S,SA[mid])<0)okr=mid;\n\t\t\telse ngr=mid;\n\t\t}\n\t\treturn\
    \ P(okl,okr);\n\t}\n\tvector<int>locate(T &S){\n\t\tvector<bool>v(len(ST)+1);\n\
    \t\tP range=occ(S);\n\t\tfor(int i=range.first;i<range.second;i++)v[SA[i]]=true;\n\
    \t\tvector<int>res;\n\t\trep(i,len(ST)+1)if(v[i])res.emplace_back(i);\n\t\treturn\
    \ res;\n\t}\n\tint operator[](int k){return SA[k];}\n\npublic:\n\tvector<int>LCP;\n\
    private:\n\tvoid constructLCP(){\n\t\tvector<int>rank(len(ST)+1);\n\t\tLCP.resize(len(ST)+1);\n\
    \t\trep(i,len(ST)+1)rank[SA[i]]=i;\n\t\tint h=0;\n\t\trep(i,len(ST)){\n\t\t\t\
    int j=SA[rank[i]-1];\n\t\t\tif(h>0)h--;\n\t\t\tfor(j;j+h<len(ST)&&i+h<len(ST);h++){\n\
    \t\t\t\tif(ST[j+h]!=ST[i+h])break;\n\t\t\t}\n\t\t\tLCP[rank[i]-1]=h;\n\t\t}\n\t\
    }\npublic:\n\tSuffixArray(T S):ST(S){\n\t\tint mn=inf,mx=-inf;\n\t\tfor(auto i:S){\n\
    \t\t\tchmin(mn,(int)i);chmax(mx,(int)i);\n\t\t}\n\t\tvector<int>newS;\n\t\tfor(auto\
    \ i:S)newS.emplace_back(i-mn+1);\n\t\tnewS.emplace_back(0);\n\t\tSA=InducedSorting(newS,mx-mn+2);\n\
    \t\tconstructLCP();\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    class SuffixArray{\n\t#define typeS make_pair(false,false)\n\t#define LMS make_pair(false,true)\n\
    \t#define typeL make_pair(true,true)\n\tusing TYPE=pair<bool,bool>;\n\tvector<TYPE>assignType(vector<int>&S){\n\
    \t\tvector<TYPE>type(len(S));\n\t\ttype[len(S)-1]=LMS;\n\t\tfor(int i=len(S)-2;i>=0;i--){\n\
    \t\t\tif(S[i]<S[i+1])type[i]=typeS;\n\t\t\telse if(S[i]>S[i+1]){\n\t\t\t\ttype[i]=typeL;\n\
    \t\t\t\tif(type[i+1]==typeS)type[i+1]=LMS;\n\t\t\t}else type[i]=type[i+1];\n\t\
    \t}\n\t\treturn type;\n\t}\n\tvector<int>getBucket(vector<int>&S,int alph){\n\t\
    \tvector<int>bucket(alph);\n\t\tfor(int i:S)bucket[i]++;\n\t\trep(i,len(bucket)-1)bucket[i+1]+=bucket[i];\n\
    \t\treturn bucket;\n\t}\n\tvoid sortTypeL(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int\
    \ alph){\n\t\tvector<int>bucket=getBucket(S,alph);\n\t\tfor(int i:SA){\n\t\t\t\
    if(i>0&&type[i-1]==typeL)SA[bucket[S[i-1]-1]++]=i-1;\n\t\t}\n\t}\n\tvoid sortTypeS(vector<int>&S,vector<int>&SA,vector<TYPE>&type,int\
    \ alph){\n\t\tvector<int>bucket=getBucket(S,alph);\n\t\trev(j,len(S)){\n\t\t\t\
    int i=SA[j];\n\t\t\tif(i>0&&(type[i-1]==typeS||type[i-1]==LMS))SA[--bucket[S[i-1]]]=i-1;\n\
    \t\t}\n\t}\n\tvector<int>InducedSorting(vector<int>&S,int alph){\n\t\tvector<int>SA(len(S),-1);\n\
    \t\tvector<TYPE>type=assignType(S);\n\t\tvector<int>bucket=getBucket(S,alph);\n\
    \t\tvector<int>nextlms(len(S),-1),ordered_lms;\n\t\tint lastlms=-1;\n\t\trep(i,len(S))if(type[i]==LMS){\n\
    \t\t\tSA[--bucket[S[i]]]=i;\n\t\t\tif(lastlms!=-1)nextlms[lastlms]=i;\n\t\t\t\
    lastlms=i;\n\t\t\tordered_lms.emplace_back(i);\n\t\t}\n\t\tnextlms[lastlms]=lastlms;\n\
    \t\tsortTypeL(S,SA,type,alph);\n\t\tsortTypeS(S,SA,type,alph);\n\t\tvector<int>lmses;\n\
    \t\tfor(int i:SA)if(type[i]==LMS)lmses.emplace_back(i);\n\t\tint nowrank=0;\n\t\
    \tvector<int>newS={0};\n\t\tREP(i,len(lmses)){\n\t\t\tint pre=lmses[i-1],now=lmses[i];\n\
    \t\t\tif(nextlms[pre]-pre!=nextlms[now]-now)newS.emplace_back(++nowrank);\n\t\t\
    \telse {\n\t\t\t\tbool flag=false;\n\t\t\t\trep(j,nextlms[pre]-pre+1){\n\t\t\t\
    \t\tif(S[pre+j]!=S[now+j]){flag=true;break;}\n\t\t\t\t}\n\t\t\t\tif(flag)newS.emplace_back(++nowrank);\n\
    \t\t\t\telse newS.emplace_back(nowrank);\n\t\t\t}\n\t\t}\n\t\tif(nowrank+1!=len(lmses)){\n\
    \t\t\tvector<int>V(len(S),-1);\n\t\t\trep(i,len(lmses)){\n\t\t\t\tV[lmses[i]]=newS[i];\n\
    \t\t\t}\n\t\t\tvector<int>newnewS;\n\t\t\trep(i,len(S))if(V[i]!=-1)newnewS.emplace_back(V[i]);\n\
    \t\t\tvector<int>SA_=InducedSorting(newnewS,nowrank+1);\n\t\t\trep(i,len(SA_)){\n\
    \t\t\t\tlmses[i]=ordered_lms[SA_[i]];\n\t\t\t}\n\t\t}\n\t\tSA.assign(len(S),-1);\n\
    \t\tbucket=getBucket(S,alph);\n\t\trev(i,len(lmses)){\n\t\t\tSA[--bucket[S[lmses[i]]]]=lmses[i];\n\
    \t\t}\n\t\tsortTypeL(S,SA,type,alph);\n\t\tsortTypeS(S,SA,type,alph);\n\t\treturn\
    \ SA;\n\t}\n\tvector<int>SA;\n\tT ST;\nprivate:\n\tint ismatch(T &S,int index){\n\
    \t\trep(i,len(S)){\n\t\t\tif(i+index>=len(ST))return 1;\n\t\t\tif(ST[i+index]<S[i])return\
    \ 1;\n\t\t\tif(ST[i+index]>S[i])return -1;\n\t\t}\n\t\treturn 0;\n\t}\npublic:\n\
    \tP occ(T &S){\n\t\tint okl=len(ST)+1,ngl=0;\n\t\twhile(okl-ngl>1){\n\t\t\tint\
    \ mid=(okl+ngl)/2;\n\t\t\tif(ismatch(S,SA[mid])<=0)okl=mid;\n\t\t\telse ngl=mid;\n\
    \t\t}\n\t\tint okr=len(ST)+1,ngr=0;\n\t\twhile(okr-ngr>1){\n\t\t\tint mid=(okr+ngr)/2;\n\
    \t\t\tif(ismatch(S,SA[mid])<0)okr=mid;\n\t\t\telse ngr=mid;\n\t\t}\n\t\treturn\
    \ P(okl,okr);\n\t}\n\tvector<int>locate(T &S){\n\t\tvector<bool>v(len(ST)+1);\n\
    \t\tP range=occ(S);\n\t\tfor(int i=range.first;i<range.second;i++)v[SA[i]]=true;\n\
    \t\tvector<int>res;\n\t\trep(i,len(ST)+1)if(v[i])res.emplace_back(i);\n\t\treturn\
    \ res;\n\t}\n\tint operator[](int k){return SA[k];}\n\npublic:\n\tvector<int>LCP;\n\
    private:\n\tvoid constructLCP(){\n\t\tvector<int>rank(len(ST)+1);\n\t\tLCP.resize(len(ST)+1);\n\
    \t\trep(i,len(ST)+1)rank[SA[i]]=i;\n\t\tint h=0;\n\t\trep(i,len(ST)){\n\t\t\t\
    int j=SA[rank[i]-1];\n\t\t\tif(h>0)h--;\n\t\t\tfor(j;j+h<len(ST)&&i+h<len(ST);h++){\n\
    \t\t\t\tif(ST[j+h]!=ST[i+h])break;\n\t\t\t}\n\t\t\tLCP[rank[i]-1]=h;\n\t\t}\n\t\
    }\npublic:\n\tSuffixArray(T S):ST(S){\n\t\tint mn=inf,mx=-inf;\n\t\tfor(auto i:S){\n\
    \t\t\tchmin(mn,(int)i);chmax(mx,(int)i);\n\t\t}\n\t\tvector<int>newS;\n\t\tfor(auto\
    \ i:S)newS.emplace_back(i-mn+1);\n\t\tnewS.emplace_back(0);\n\t\tSA=InducedSorting(newS,mx-mn+2);\n\
    \t\tconstructLCP();\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: String/SuffixArray.cpp
  requiredBy:
  - String/FM_index.cpp
  - String/BWT.cpp
  timestamp: '2020-09-19 18:14:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/SuffixArray.cpp
layout: document
redirect_from:
- /library/String/SuffixArray.cpp
- /library/String/SuffixArray.cpp.html
title: String/SuffixArray.cpp
---
