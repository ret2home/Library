---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/UnionFind.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"structure/UnionFind.cpp\"\n\nclass UnionFind{\n\tint N;\n\tvector<int>par,siz;\n\
    public:\n\tint find(int x){\n\t\tassert(x<N);\n\t\treturn (par[x]==x?x:par[x]=find(par[x]));\n\
    \t}\n\tvoid merge(int x,int y){\n\t\tassert(x<N&&y<N);\n\t\tx=find(x);y=find(y);\n\
    \t\tif(x==y)return;\n\t\tif(siz[x]>siz[y])swap(x,y);\n\t\tpar[x]=y;siz[y]+=siz[x];\n\
    \t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\t}\n\tint size(int\
    \ x){\n\t\treturn siz[find(x)];\n\t}\n\tUnionFind(int N):N(N),siz(N,1),par(N){\n\
    \t\tiota(all(par),0);\n\t}\n};\n\n/*\n@brief Union Find\n@docs docs/UnionFind.md\n\
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nclass UnionFind{\n\
    \tint N;\n\tvector<int>par,siz;\npublic:\n\tint find(int x){\n\t\tassert(x<N);\n\
    \t\treturn (par[x]==x?x:par[x]=find(par[x]));\n\t}\n\tvoid merge(int x,int y){\n\
    \t\tassert(x<N&&y<N);\n\t\tx=find(x);y=find(y);\n\t\tif(x==y)return;\n\t\tif(siz[x]>siz[y])swap(x,y);\n\
    \t\tpar[x]=y;siz[y]+=siz[x];\n\t}\n\tbool same(int x,int y){\n\t\treturn find(x)==find(y);\n\
    \t}\n\tint size(int x){\n\t\treturn siz[find(x)];\n\t}\n\tUnionFind(int N):N(N),siz(N,1),par(N){\n\
    \t\tiota(all(par),0);\n\t}\n};\n\n/*\n@brief Union Find\n@docs docs/UnionFind.md\n\
    */"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/UnionFind.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/UnionFind.test.cpp
documentation_of: structure/UnionFind.cpp
layout: document
redirect_from:
- /library/structure/UnionFind.cpp
- /library/structure/UnionFind.cpp.html
title: Union Find
---
## 概要

素集合データ構造、通称 Union-Find (UF) または Disjoint-Set-Union (DSU) 。

集合のマージ、どこの集合に属しているかの問い合わせを高速に行える。

- ```find(x)``` : ```x``` が属する集合の根を求める
- ```merge(x,y)``` : ```x,y``` をマージする
- ```same(x,y)``` : ```x,y``` が同じ集合に属するかを求める
- ```size(x)``` : ```x``` が属する集合のサイズを求める

## 計算量

これよく分かってないけど、1回のクエリあたり $O(\alpha (N))$ らしい。

$\alpha(N)$ はアッカーマン関数の逆関数と言って、収束がすごく速い関数。定数倍と見て問題ない（？）