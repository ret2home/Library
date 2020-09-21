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
    \ inf = 3e18;\n#line 3 \"Data Structure/UnionFind.cpp\"\n\nstruct UnionFind{\n\
    \tvector<int>par,size;\n\tint find(int x){\n\t\treturn (par[x]==x?x:par[x]=find(par[x]));\n\
    \t}\n\tvoid merge(int x,int y){\n\t\tx=find(x);y=find(y);\n\t\tif(x==y)return;\n\
    \t\tif(size[x]>size[y])swap(x,y);\n\t\tpar[x]=y;\n\t\tsize[y]+=size[x];\n\t}\n\
    \tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\t}\n\tUnionFind(int\
    \ x):size(x,1),par(x){\n\t\tiota(all(par),0);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct UnionFind{\n\
    \tvector<int>par,size;\n\tint find(int x){\n\t\treturn (par[x]==x?x:par[x]=find(par[x]));\n\
    \t}\n\tvoid merge(int x,int y){\n\t\tx=find(x);y=find(y);\n\t\tif(x==y)return;\n\
    \t\tif(size[x]>size[y])swap(x,y);\n\t\tpar[x]=y;\n\t\tsize[y]+=size[x];\n\t}\n\
    \tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\t}\n\tUnionFind(int\
    \ x):size(x,1),par(x){\n\t\tiota(all(par),0);\n\t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Data Structure/UnionFind.cpp
  requiredBy: []
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structure/UnionFind.cpp
layout: document
redirect_from:
- /library/Data Structure/UnionFind.cpp
- /library/Data Structure/UnionFind.cpp.html
title: Data Structure/UnionFind.cpp
---
