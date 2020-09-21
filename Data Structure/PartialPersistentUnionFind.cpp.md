---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
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
    \ inf = 3e18;\n#line 3 \"Data Structure/PartialPersistentUnionFind.cpp\"\n\nstruct\
    \ PartialPersistentUnionFind{\n\tint version=0;\n\tvector<int>tim,par;\n\tvector<vector<P>>siz;\n\
    \tint find(int x,int t){\n\t\tif(tim[x]>t)return x;\n\t\treturn find(par[x],t);\n\
    \t}\n\tint same(int x,int y,int t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\t\
    int size(int x,int t){\n\t\tx=find(x,t);\n\t\treturn (--upper_bound(all(siz[x]),P(t,inf)))->second;\n\
    \t}\n\tvoid merge(int x,int y){\n\t\tversion++;\n\t\tx=find(x,version);\n\t\t\
    y=find(y,version);\n\t\tif(x==y)return;\n\t\tint sx=size(x,version),sy=size(y,version);\n\
    \t\tif(sx>sy)swap(x,y);\n\t\ttim[x]=version;par[x]=y;\n\t\tsiz[y].push_back({version,sx+sy});\n\
    \t}\n\tPartialPersistentUnionFind(int x):tim(x,inf){\n\t\tsiz.resize(x);\n\t\t\
    rep(i,x){\n\t\t\tpar.push_back(i);\n\t\t\tsiz[i].push_back(P(0,1));\n\t\t}\n\t\
    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct PartialPersistentUnionFind{\n\
    \tint version=0;\n\tvector<int>tim,par;\n\tvector<vector<P>>siz;\n\tint find(int\
    \ x,int t){\n\t\tif(tim[x]>t)return x;\n\t\treturn find(par[x],t);\n\t}\n\tint\
    \ same(int x,int y,int t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tint size(int\
    \ x,int t){\n\t\tx=find(x,t);\n\t\treturn (--upper_bound(all(siz[x]),P(t,inf)))->second;\n\
    \t}\n\tvoid merge(int x,int y){\n\t\tversion++;\n\t\tx=find(x,version);\n\t\t\
    y=find(y,version);\n\t\tif(x==y)return;\n\t\tint sx=size(x,version),sy=size(y,version);\n\
    \t\tif(sx>sy)swap(x,y);\n\t\ttim[x]=version;par[x]=y;\n\t\tsiz[y].push_back({version,sx+sy});\n\
    \t}\n\tPartialPersistentUnionFind(int x):tim(x,inf){\n\t\tsiz.resize(x);\n\t\t\
    rep(i,x){\n\t\t\tpar.push_back(i);\n\t\t\tsiz[i].push_back(P(0,1));\n\t\t}\n\t\
    }\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Data Structure/PartialPersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structure/PartialPersistentUnionFind.cpp
layout: document
redirect_from:
- /library/Data Structure/PartialPersistentUnionFind.cpp
- /library/Data Structure/PartialPersistentUnionFind.cpp.html
title: Data Structure/PartialPersistentUnionFind.cpp
---
