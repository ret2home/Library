---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"structure/PartialPersistentUnionFind.cpp\"\n\nstruct PartialPersistentUnionFind{\n\
    \tll version=0;\n\tvector<ll>tim,par;\n\tvector<vector<P>>siz;\n\tll find(ll x,ll\
    \ t){\n\t\tif(tim[x]>t)return x;\n\t\treturn find(par[x],t);\n\t}\n\tll same(ll\
    \ x,ll y,ll t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tll size(ll x,ll t){\n\
    \t\tx=find(x,t);\n\t\treturn (--upper_bound(all(siz[x]),P(t,inf)))->second;\n\t\
    }\n\tvoid merge(ll x,ll y){\n\t\tversion++;\n\t\tx=find(x,version);\n\t\ty=find(y,version);\n\
    \t\tif(x==y)return;\n\t\tll sx=size(x,version),sy=size(y,version);\n\t\tif(sx>sy)swap(x,y);\n\
    \t\ttim[x]=version;par[x]=y;\n\t\tsiz[y].push_back({version,sx+sy});\n\t}\n\t\
    PartialPersistentUnionFind(ll x):tim(x,inf){\n\t\tsiz.resize(x);\n\t\trep(i,x){\n\
    \t\t\tpar.push_back(i);\n\t\t\tsiz[i].push_back(P(0,1));\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct PartialPersistentUnionFind{\n\
    \tll version=0;\n\tvector<ll>tim,par;\n\tvector<vector<P>>siz;\n\tll find(ll x,ll\
    \ t){\n\t\tif(tim[x]>t)return x;\n\t\treturn find(par[x],t);\n\t}\n\tll same(ll\
    \ x,ll y,ll t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tll size(ll x,ll t){\n\
    \t\tx=find(x,t);\n\t\treturn (--upper_bound(all(siz[x]),P(t,inf)))->second;\n\t\
    }\n\tvoid merge(ll x,ll y){\n\t\tversion++;\n\t\tx=find(x,version);\n\t\ty=find(y,version);\n\
    \t\tif(x==y)return;\n\t\tll sx=size(x,version),sy=size(y,version);\n\t\tif(sx>sy)swap(x,y);\n\
    \t\ttim[x]=version;par[x]=y;\n\t\tsiz[y].push_back({version,sx+sy});\n\t}\n\t\
    PartialPersistentUnionFind(ll x):tim(x,inf){\n\t\tsiz.resize(x);\n\t\trep(i,x){\n\
    \t\t\tpar.push_back(i);\n\t\t\tsiz[i].push_back(P(0,1));\n\t\t}\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/PartialPersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/PartialPersistentUnionFind.cpp
layout: document
redirect_from:
- /library/structure/PartialPersistentUnionFind.cpp
- /library/structure/PartialPersistentUnionFind.cpp.html
title: structure/PartialPersistentUnionFind.cpp
---
