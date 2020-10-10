---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/BWT.cpp
    title: Burrows Wheeler Transform
  - icon: ':heavy_check_mark:'
    path: string/FM_index.cpp
    title: FM Index
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FM_index.test.cpp
    title: test/FM_index.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SuffixArray.LCP.test.cpp
    title: test/SuffixArray.LCP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SuffixArray.matching.test.cpp
    title: test/SuffixArray.matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SuffixArray.test.cpp
    title: test/SuffixArray.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/SuffixArray.md
    document_title: Suffix Array (SA-IS)
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"string/SuffixArray.cpp\"\
    \n\ntemplate<class T>\nclass SuffixArray{\n\t#define typeS make_pair(false,false)\n\
    \t#define LMS make_pair(false,true)\n\t#define typeL make_pair(true,true)\n\t\
    using TYPE=pair<bool,bool>;\n\tvector<TYPE>assignType(vector<ll>&S){\n\t\tvector<TYPE>type(len(S));\n\
    \t\ttype[len(S)-1]=LMS;\n\t\tfor(ll i=len(S)-2;i>=0;i--){\n\t\t\tif(S[i]<S[i+1])type[i]=typeS;\n\
    \t\t\telse if(S[i]>S[i+1]){\n\t\t\t\ttype[i]=typeL;\n\t\t\t\tif(type[i+1]==typeS)type[i+1]=LMS;\n\
    \t\t\t}else type[i]=type[i+1];\n\t\t}\n\t\treturn type;\n\t}\n\tvector<ll>getBucket(vector<ll>&S,ll\
    \ alph){\n\t\tvector<ll>bucket(alph);\n\t\tfor(ll i:S)bucket[i]++;\n\t\trep(i,len(bucket)-1)bucket[i+1]+=bucket[i];\n\
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
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    class SuffixArray{\n\t#define typeS make_pair(false,false)\n\t#define LMS make_pair(false,true)\n\
    \t#define typeL make_pair(true,true)\n\tusing TYPE=pair<bool,bool>;\n\tvector<TYPE>assignType(vector<ll>&S){\n\
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
    */"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: string/SuffixArray.cpp
  requiredBy:
  - string/FM_index.cpp
  - string/BWT.cpp
  timestamp: '2020-09-23 20:44:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FM_index.test.cpp
  - test/SuffixArray.test.cpp
  - test/SuffixArray.LCP.test.cpp
  - test/SuffixArray.matching.test.cpp
documentation_of: string/SuffixArray.cpp
layout: document
redirect_from:
- /library/string/SuffixArray.cpp
- /library/string/SuffixArray.cpp.html
title: Suffix Array (SA-IS)
---
## 概要

SA-IS を使ってSuffix Arrayを $O(\mid S \mid)$ で構築する。JOI夏季セミ2020 の成果物でもある。

- ```[i]``` : Suffix Arrayの```i``` 番目 (0番目は末尾である事に注意)
- ```occ(T)``` : ```T``` が登場するSuffix Array上の区間
- ```locate(T)``` : ```T``` が登場する index の集合
- ```LCP``` : 高さ配列

## 計算量

- 構築 : $O(\mid S \mid)$
- ```occ,locate``` : $O(\mid T \mid log \mid S \mid)$